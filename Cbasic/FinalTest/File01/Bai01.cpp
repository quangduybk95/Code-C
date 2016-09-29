#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;
int A[100],x[100],c[100],tam[100];
int n,b,mx=0;
void Nhap(){
	fstream fi;
	fi.open("De_01.txt",ios::in);
	fi>>n>>b;
	for(int i=0;i<n;i++) fi>>A[i];
	for(int i=0;i<n;i++) fi>>c[i];
	fi.close();
}
void Hienthi(){
	cout<<mx<<endl;
	for(int i=0;i<n;i++)cout<<tam[i]<<" ";
}
void Kt(){
	int tong1=0,tong2=0;
	for(int i=0;i<n;i++){
		tong1=tong1+A[i]*x[i];
		tong2=tong2+c[i]*x[i];
	}
	if(tong2<=b){
		if(tong1>mx){
			mx=tong1;
			for(int i=0;i<n;i++)tam[i]=x[i];
		}
	}
}
void Try(int i){
	for(int j=0;j<=1;j++){
		x[i]=j;
		if(i==n-1)Kt();
		else Try(i+1);
	}
}
main(){
	Nhap();
	Try(0);
	Hienthi();
	getch();
}
