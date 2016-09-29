#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;
int MT[100][100],cx[10],tam1[10],tam2[10];
int n,m,dem;
void nhap(){
	fstream fi;
	fi.open("De_20.txt",ios::in);
	fi>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
		fi>>MT[i][j];
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
    nhap();
    BFS(m);
    cout<<n<<" "<<dem<<endl;
    for(int i=1;i<=dem;i++)
    cout<<tam1[i]<<" "<<tam2[i]<<endl;
	getch();
}
