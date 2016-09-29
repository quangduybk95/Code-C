#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;
int A[100][100],cx[100],CBT[100][3];
int n,m,sc,w;
int MAX=10000;
void nhap(){
	int ax[50],bx[50],ts;
	fstream fi;
	fi.open("De_18.txt",ios::in);
	fi>>n>>m;
	for(int i=0;i<m;i++){
		fi>>ax[i]>>bx[i]>>ts;
		A[ax[i]][bx[i]]=A[bx[i]][ax[i]]=ts;
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	if(i!=j&&A[i][j]==0) A[i][j]=MAX;
}
void hienthi(){
	
}
void PRIM(){
	int top,k,s[100],MIN,l,t,u;
	sc=0;w=0;u=1;
	for(int i=1;i<=n;i++) cx[i]=1;
	top=1;s[top]=u;
	cx[u]=0;
	while(sc<n-1){
		MIN=MAX;
		for(int i=1;i<=top;i++){
			t=s[i];
			for(int j=1;j<=n;j++){
				if(cx[j]==1&&MIN>A[t][j]){
					MIN=A[t][j];
					k=t;l=j;
				}
			}
		}
		sc++;w=w+MIN;
		CBT[sc][1]=k;CBT[sc][2]=l;
		cx[l]=0; A[k][l]=MAX; A[k][l]=MAX;
		top++;s[top]=l;
	}
}
main(){
	nhap();
	PRIM();
	cout<<w<<endl;
	for(int i=1;i<=sc;i++)
	cout<<CBT[i][1]<<" "<<CBT[i][2]<<endl;
	getch();
}
