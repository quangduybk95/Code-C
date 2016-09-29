#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;
int A[100],x[100],B[100][100];
int n,K,dem=0;
void nhap(){
	fstream fi;
	fi.open("De_06.txt",ios::in);
	fi>>n>>K;
	for(int i=1;i<=n;i++)
	fi>>A[i];
	fi.close();
}
void hienthi(){
	for(int i=1;i<=dem;i++){
		for(int j=1;j<=K;j++)
		cout<<B[i][j]<<" ";
		cout<<endl;
	}
}
void thuchien(){
	dem++;
	for(int i=1;i<=K;i++)
	B[dem][i]=A[x[i]];
}
int kt(){
	for(int i=1;i<K;i++){
		if(A[x[i]]<A[x[i+1]]) return 0;
	}
	return 1;
}
void Try(int i){
	for(int j=x[i-1]+1;j<=n-K+i;j++){
		x[i]=j;
		if(i==K){
			if(kt()==1)thuchien();
		}
		else Try(i+1);
	}
}
main(){
	nhap();
	Try(1);
	hienthi();
	cout<<dem;
	getch();
}
