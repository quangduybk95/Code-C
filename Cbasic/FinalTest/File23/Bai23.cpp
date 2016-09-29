#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;
int A[100][100],cx[100],n,dem=0,tam1[10],tam2[10];
void nhap(){
	fstream fi;
	fi.open("De_23.txt",ios::in);
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
int ktcanhcau(int i,int j){
	for(int v=0;v<n;v++) cx[v]=1;
	DFS(0);
	for(int i=0;i<n;i++)
	if(cx[i]==1) return 1;
	return 0;
}
void timcanhcau(){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(A[i][j]==1){
				A[i][j]=A[j][i]=0;
				if(ktcanhcau(i,j)){
					dem++;
					tam1[dem]=i;tam2[dem]=j;
				}
				A[i][j]=A[j][i]=1;
			}
		}
	}
}
main(){
	nhap();
	timcanhcau();
	cout<<dem<<endl;
	for(int i=1;i<=dem;i++)
	cout<<tam1[i]+1<<" "<<tam2[i]+1<<endl;
	getch();
}
