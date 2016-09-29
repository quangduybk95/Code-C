#include<iostream>
#include<conio.h>
#include<fstream>
#include<stack>
using namespace std;
int A[100][100],cx[100],dinhdau[10],CE[100];
int n;
void nhap(){
	fstream fi;
	fi.open("De_12.txt",ios::in);
	fi>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) fi>>A[i][j];
	}
	fi.close();
}
void DFS(int u){
	cx[u]=0;
	for(int v=0;v<n;v++){
		if(cx[v]==1&&A[u][v]==1)
		DFS(v);
	}
}
int lienthong(){
	for(int i=0;i<n;i++) cx[i]=1;
	DFS(0);
	for(int i=0;i<n;i++)
	if(cx[i]==1) return 0;
	return 1;
}	
int kt(){
	int deg,k=0;
	for(int i=0;i<n;i++){
		deg=0;
		for(int j=0;j<n;j++) deg=deg+A[i][j];
		if(deg%2!=0){
			k++; dinhdau[k]=i;
		}
	}
	if(k>2) return 0;
	return 1;
}
void nuaeuler(int dinhdau[]){
	int dCE=0,i=dinhdau[1];
	stack<int> s1;
	s1.push(i);
	while(!s1.empty()){
		int u=s1.top();
		int x=0;
		while(x<n&&A[u][x]==0){
			x++;
		}
		if(x==n){
			dCE++;CE[dCE]=u;s1.pop();
		}else{
			A[u][x]=A[x][u]=0;
			s1.push(x);
		}
	}
	for(int v=dCE;v>0;v--){
		cout<<CE[v]+1<<" ";
	}
}
main(){
	nhap();
	if(lienthong()==1&&kt()==1)nuaeuler(dinhdau);
	else cout<<"G khong la do thi nua Euler";
	getch();
}
