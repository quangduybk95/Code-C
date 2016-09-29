#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;
int A[100],x[100];
int n,B,dem=0;
void nhap(){
	fstream fi;
	fi.open("De_03.txt",ios::in);
	fi>>n>>B;
	for(int i=0;i<n;i++){
		fi>>A[i];
	}
	fi.close();
}
void hienthi(){
	for(int i=0;i<n;i++)
	cout<<x[i]<<" ";
}
void Kt(){
	int tong=0;
	for(int i=0;i<n;i++){
		tong=tong+A[i]*x[i];
	}
	if(tong==B){
		dem++;
		hienthi();
		cout<<endl;
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
	nhap();
	Try(0);
	cout<<dem;
	getch();
}
