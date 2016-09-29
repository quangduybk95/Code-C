#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;
int a[100],b[100],c[100],f[100],tam1[20],tam2[20];
int n,m,t,dem=0;
void nhap(){
	fstream fi;
	fi.open("De_19.txt",ios::in);
	fi>>n>>m;
	for(int i=1;i<=m;i++)
	fi>>a[i]>>b[i]>>c[i];
	fi.close();
}
void doicho(int *a,int *b){
	t=*a;
	*a=*b;
	*b=t;
}
void sapxep(){
	for(int i=1;i<=m;i++)
	for(int j=i+1;j<=m;j++)
	if(c[i]>c[j]){
		doicho(&c[i],&c[j]);
	    doicho(&a[i],&a[j]);
	    doicho(&b[i],&b[j]);
	}
}
int get(int d){
	if(f[d]<0) return d;
	return get(f[d]);
}
void ghikq(int u,int v){
	dem++;
	tam1[dem]=u;tam2[dem]=v;
}
void Kruskal(){
	int s=0,v,u;
	for(int i=1;i<=m;i++){
		u=a[i],v=b[i];
		if(f[u]*f[v]==0){
			if(f[u]==0&&f[v]==0){
				ghikq(u,v);
				s=s+c[i];
				f[u]=-1;f[v]=u;
			}
			if(f[u]!=0&&f[v]==0){
				ghikq(u,v);
				s=s+c[i];
				f[v]=u;
			}
			if(f[v]!=0&&f[u]==0){
				ghikq(u,v);
				s=s+c[i];
				f[u]=v;
			}
		}
		else{
			int x=get(u);int y=get(v);
			if(x!=y){
				ghikq(u,v);
				s=s+c[i];
				f[x]=y;
			}
		}
	}
	cout<<s<<endl;
}
void hienthi(){
	for(int i=1;i<=dem;i++)
	cout<<tam1[i]<<" "<<tam2[i]<<endl;
}
main(){
	nhap();
	sapxep();
	Kruskal();
	hienthi();
	getch();
}
