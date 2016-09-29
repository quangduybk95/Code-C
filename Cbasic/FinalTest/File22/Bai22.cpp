#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;
int A[100][100],cx[100],n,dem1=0,tam[10];
void nhap(){
	fstream fi;
	fi.open("De_22.txt",ios::in);
	fi>>n;
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++) fi>>A[i][j];
	fi.close();
}
void DFS(int u){
	cx[u]=0;
	for(int v=0;v<n;v++)
	if(cx[v]==1&&A[u][v]==1) DFS(v);
}
int tplienthong(){
	int dem=0;
	for(int i=0;i<n;i++)
	if(cx[i]==1){
		DFS(i); dem++;
	}
	return dem;
}
int ktdinhtru(int i){
	for(int j=0;j<n;j++) cx[j]=1;
	cx[i]=0;
	if(tplienthong()>1) return 1;
	else return 0;
}
void timdinhtru(){
	for(int i=0;i<n;i++)
	if(ktdinhtru(i)==1){
		dem1++;tam[dem1]=i;
	}
}
main(){
	nhap();
	timdinhtru();
	cout<<dem1<<endl;
	for(int i=1;i<=dem1;i++)cout<<tam[i]+1<<" ";
	getch();
}
