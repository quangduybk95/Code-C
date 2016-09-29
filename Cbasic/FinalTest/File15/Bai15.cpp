#include<iostream>
#include<conio.h>
#include<fstream>
#include<stack>
using namespace std;
int A[100][100],n;
int Pi[100],Di[100],danhdau[100];
int D,C;
void nhap(){
	fstream fi;
	fi.open("De_15.txt",ios::in);
	fi>>n>>D>>C;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			fi>>A[i][j];
			if(A[i][j]==0) A[i][j]=32000;
	    }
	}
	fi.close();
}
void Dijkstra(int D,int C){
	int u;
	for(int v=0;v<n;v++){
		Di[v]=A[D][v];
		Pi[v]=D;
		danhdau[v]=0;
	}

	Pi[D]=0;danhdau[D]=1;Di[D]=0;
	while(!danhdau[C]){
		int minp=2000;
		for(int v=0;v<n;v++){
			if(danhdau[v]==0&&minp>Di[v]){
				u=v;
				minp=Di[v];
			}
		}
		danhdau[u]=1;
		if(!danhdau[C]){
			for(int v=0;v<n;v++){
				if(danhdau[v]==0&&Di[u]+A[u][v]<Di[v]){
					Di[v]=Di[u]+A[u][v];
					Pi[v]=u;
				}
			}
		}
	}
}
void Ketqua(int D,int C){
	cout<<Di[C]<<endl;
	cout<<D+1<<" ";
	int i=Pi[C],dem=0,tam[100];
	while(i!=D){
		tam[dem]=i;
		dem++;
		i=Pi[i];
	}
	for(int j=dem-1;j>=0;j--)cout<<tam[j]+1<<" ";
	cout<<C+1;
}
main(){
    nhap();
    Dijkstra(D,C);
    Ketqua(D,C);
    getch();
}
