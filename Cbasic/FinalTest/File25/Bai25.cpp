#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;
int A[100][100],n,c1[10],c2[10],cx[10],sc=0;
void nhap(){
	fstream fi;
	fi.open("De_25.txt",ios::in);
	fi>>n;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++) fi>>A[i][j];
	
	for(int k=1;k<=n;k++) cx[k]=1;
	fi.close();
}
void DFS(int u){
	cx[u]=0;
	for(int v=1;v<=n;v++)
	if(cx[v]==1&&A[u][v]==1){
		sc++;
		c1[sc]=u;c2[sc]=v;
		DFS(v);
	}
}
void hienthi(){
	for(int i=1;i<=sc;i++)
	cout<<c1[i]<<" "<<c2[i]<<endl;
}
main(){
	int m;
	cout<<"Nhap dinh bat dau: ";cin>>m;
	nhap();
	DFS(m);
	hienthi();
	getch();
}
