#include<iostream>
#include<conio.h>
#include<fstream>
#include<stack>
using namespace std;
int A[100][100],cx[100],CE[100];
int n;
void nhap(){                                              
	fstream fi;
	fi.open("De_14.txt",ios::in);
	fi>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) fi>>A[i][j];
	}
	fi.close();
}

int kt(){
	int degr,degv;
	for(int i=1;i<=n;i++){
		degr=0; degv=0;
		for(int j=1;j<=n;j++){
			degr=degr+A[i][j];
			degv=degv+A[j][i];
		}
		if(degr!=degv) return 0;
	}
	return 1;
}
void CTeuler(){
	int dCE=0,bd;
	cout<<"Nhap dinh bat dau:";cin>>bd;
	stack<int> s1;
	s1.push(bd);
	while(!s1.empty()){
		int u=s1.top();
		int x=0;
		while(x<=n&&A[u][x]==0){
			x++;
		}
		if(x>n){
			dCE++;CE[dCE]=u;s1.pop();
		}else{
			A[u][x]=A[x][u]=0;
			s1.push(x);
		}
	}
	for(int v=dCE;v>0;v--){
		cout<<CE[v]<<" ";
	}
}
main(){
	nhap();
	if(kt()==1) CTeuler();
	else cout<<"G khong phai do thi euler";
	getch();
}
