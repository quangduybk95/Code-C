#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;
int MT[100][100],a[10],b[10],cx[10],tam1[10],tam2[10];
int n,m,dem;
void nhap(){
	fstream fi;
	fi.open("De_24.txt",ios::in);
	fi>>n>>m;
	for(int i=0;i<m;i++){
		fi>>a[i]>>b[i];
		MT[a[i]][b[i]]=MT[b[i]][a[i]]=1;
	}
	for(int j=1;j<=n;j++) cx[j]=1;
	fi.close();
}
void BFS(int u){
	int q[100],cq=1,dq=1;
	cx[u]=0;
	q[cq]=u;
	while(dq<=cq){
		int k=q[dq];
		dq++;
		for(int v=1;v<=n;v++)
		if(cx[v]==1&&MT[k][v]==1){
			dem++;
			tam1[dem]=k;tam2[dem]=v;
			cx[v]=0;cq++;
			q[cq]=v;
		}
	}
}
main(){
	int bd;
    nhap();
    cout<<"Nhap dinh bat dau:";cin>>bd;
    BFS(bd);
    for(int i=1;i<=dem;i++)
    cout<<tam1[i]<<" "<<tam2[i]<<endl;
	getch();
}
