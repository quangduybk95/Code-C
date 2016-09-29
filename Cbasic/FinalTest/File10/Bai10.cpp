#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;
int MT[100][100],a[100],b[100],c[100];
int n,m;
void nhap(){
	fstream fi;
	fi.open("De_10.txt",ios::in);
	fi>>n>>m;
	for(int i=0;i<m;i++){
		fi>>a[i]>>b[i]>>c[i];
		MT[a[i]][b[i]]=c[i];
	}
	fi.close();
}
void matranke(){
	cout<<n<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<MT[i][j]<<" ";
		}
		cout<<endl;
	}
}
main(){
	nhap();
	matranke();
	getch();
}
