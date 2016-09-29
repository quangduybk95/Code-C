#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;
int A[100],x[100];
int n,K,m=0,dem=0;
void nhap(){
	fstream fi;
	fi.open("De_02.txt",ios::in);
	fi>>n>>K;
	for(int i=0;i<n;i++) fi>>A[i];
	fi.close();
}
void hienthi(){
	for(int i=0;i<n;i++)
	if(x[i])cout<<A[i]<<" ";
}
void tinh_m(){
	int tong=0;
	for(int i=0;i<n;i++){
		tong=tong+A[i]*x[i];
	}
	if(tong==K){
	
		m++;
		
	}
}
void Try1(int i){
	for(int j=0;j<=1;j++){
		x[i]=j;
		if(i==n-1)tinh_m();
		else Try1(i+1);
	}
}
void kt(){
	int tong=0;
	for(int i=0;i<n;i++){
		tong=tong+A[i]*x[i];
	}
	if(tong==K){
		hienthi();
		m++;
		cout<<endl;
	}
}
void Try(int i){
	for(int j=0;j<=1;j++){
		x[i]=j;
		if(i==n-1)kt();
		else Try(i+1);
	}
}
main(){
	nhap();
	Try1(0);
	cout<<m<<endl;
	Try(0);
	getch();
}
