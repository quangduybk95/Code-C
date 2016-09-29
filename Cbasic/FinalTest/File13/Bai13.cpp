#include<iostream>
#include<conio.h>
#include<fstream>
#include<stack>
using namespace std;
int A[100][100],cx[100],CE[100];
int n;
void nhap(){                                              
	fstream fi;
	fi.open("De_13.txt",ios::in);
	fi>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) fi>>A[i][j];
	}
	fi.close();
}
void DFS(int u){
	cx[u]=0;
	for(int v=1;v<=n;v++){
		if(cx[v]==1&&A[u][v]==1)
		DFS(v);
	}
}
int lienthong(){
	for(int i=1;i<=n;i++) cx[i]=1;
	DFS(1);
	for(int i=1;i<=n;i++)
	if(cx[i]==1) return 0;
	return 1;
}
int kt(){
	int deg;
	for(int i=1;i<=n;i++){
		deg=0;
		for(int j=1;j<=n;j++) deg=deg+A[i][j];
		if(deg%2!=0) return 0;
	}
	return 1;
}
void CTeuler(){
	int dCE=0,bd;
	cout<<"Nhap dinh bat dau:";cin>>bd;
	stack<int> s1;
	s1.push(bd);
	while(!s1.empty()){
		int u=s1.top();
		int x=0;
		while(x<=n&&A[u][x]==0){
			x++;
		}
		if(x>n){
			dCE++;CE[dCE]=u;s1.pop();
		}else{
			A[u][x]=A[x][u]=0;
			s1.push(x);
		}
	}
	for(int v=dCE;v>0;v--){
		cout<<CE[v]<<" ";
	}
}
main(){
	nhap();
	if(kt()==1&&lienthong()==1) CTeuler();
	else cout<<"G khong phai do thi euler";
	getch();
}
