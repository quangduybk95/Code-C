#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;
int A[100][100],n,cx[100];
void nhap(){
	fstream fi;
	fi.open("De_17.txt",ios::in);
	fi>>n;
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++) fi>>A[i][j];
	fi.close();
}
void DFS(int u){
	cx[u]=0;
	for(int v=0;v<n;v++){
		if(cx[v]==1&&A[u][v]==1) 
		DFS(v);
	}
}
int LTmanh(){
	for(int i=0;i<n;i++) cx[i]=1;
	for(int i=0;i<n;i++){
		DFS(i);
		for(int j=0;j<n;j++)
		if(cx[j]==1) return 0;
	}
	return 1;
}
void Dothivohuong(){
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++){
		if(A[i][j]==1) A[i][j]=A[j][i]=1;
	}
}
int LTyeu(){
	Dothivohuong();
	for(int i=0;i<n;i++) cx[i]=1;
	DFS(0);
	for(int i=0;i<n;i++)
	if(cx[i]==1) return 0;
	return 1;
}
main(){
	nhap();
	if(LTmanh()==1)cout<<"Do thi lien thong manh";
	else if(LTyeu()==1) cout<<"Do thi lien thong yeu";
	else cout<<"Do thi khong lien thong manh,khong lien thong yeu";
	getch();
}
