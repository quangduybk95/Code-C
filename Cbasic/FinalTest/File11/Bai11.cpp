#include<iostream>
#include<conio.h>
#include<fstream>
#include<stack>
using namespace std;
int n,A[100][100],cx[100],dinhdau,CE[100];
void nhap(){
	fstream fi;
	fi.open("De_11.txt",ios::in);
	fi>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) fi>>A[i][j];
	}
	fi.close();
}
void DFS(int u){
	cx[u]=0;
	for(int v=0;v<n;v++)
	if(cx[v]==1&&A[u][v]==1){
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
	int dem1=0,dem2=0,deg1,deg2;
	for(int i=0;i<n;i++){
		deg1=0;deg2=0;
		for(int j=0;j<n;j++){
			deg1=deg1+A[i][j];
			deg2=deg2+A[j][i];
		}
		if((deg1-deg2)==1){
			dinhdau=i;dem1++;
		}
		else if((deg1-deg2)==-1) dem2++;
		else if((deg1-deg2)!=0) return 0;
	}
	if(dem1==1&&dem2==1) return 1;
}
void euler(int i){
	int dCE=0;
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
   if(lienthong()==1&&kt()==1)   euler(dinhdau);
   else cout<<"khong co duong di euler";
   getch();
}
