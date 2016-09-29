#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;
int A[100][100];
int n,socanh=0;
void nhap(){
	fstream fi;
	fi.open("De_09.txt",ios::in);
	fi>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) fi>>A[i][j];
	}
	fi.close();
}
void timcanh(){
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++){
		if(A[i][j]==1) socanh++;
	}
}
void Dscanh(){
	cout<<n<<" "<<socanh/2<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(A[i][j]==1){
				cout<<i+1<<" "<<j+1<<endl;
				A[i][j]=A[j][i]=0;
			}
		}
	}
}
main(){
	nhap();
	timcanh();
	Dscanh();
	getch();
}
