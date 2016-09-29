#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;
int A[100][100],D[50][50],S[50][50];
int n,u,v;
int MAX=3200;
void nhap(){
	fstream fi;
	fi.open("De_16.txt",ios::in);
	fi>>n>>u>>v;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++){
		fi>>A[i][j];
		if(i!=j&&A[i][j]==0) A[i][j]=MAX;
	}
	fi.close();
}
void hienthi(int u,int v){
	cout<<D[u][v]<<" ";
	cout<<u<<" ";
	while(u!=v){
		cout<<S[u][v]<<" ";
		u=S[u][v];
	}
}
int kt(){
	if(D[u][v]>=MAX) return 0;
	return 1;
}
void FLoy(){
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++){
		D[i][j]=A[i][j];
		if(D[i][j]==MAX)S[i][j]=0;
		else S[i][j]=j;
	}
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++){
		if(D[i][k]!=MAX&&D[i][j]>(D[i][k]+D[k][j])){
			D[i][j]=D[i][k]+D[k][j];
			S[i][j]=S[i][k];
		}
	}
}
main(){
	nhap();
	FLoy();
	if(kt()==1){
		cout<<u<<" "<<v<<endl;
		hienthi(u,v);
	    cout<<endl;
	    hienthi(v,u);
	}
	else cout<<"Khong co duong di";
	getch();
}
