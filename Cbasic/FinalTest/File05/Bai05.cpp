#include<iostream>
#include<conio.h>
#include<fstream>
#include<stack>
using namespace std;
string posfix;
int n,n1,n2,kq;
void Nhap(){
	fstream fi;
	fi.open("De_05.txt",ios::in);
	fi>>posfix;
	fi.close();
}
void Hauto(){
	stack<char> s;
	for(int i=0;i<posfix.length();i++){
		if(posfix[i]<='9'&&posfix[i]>='0'){
			n=posfix[i]-'0';
			s.push(n);
		}
		else if(posfix[i]=='+'||posfix[i]=='*'||posfix[i]=='/'||posfix[i]=='-'){
			n1=s.top();
			s.pop();
			n2=s.top();
			s.pop();
			switch(posfix[i]){
				case '+':{
					n1=n2+n1;
					break;
				}
				case '-':{
					n1=n2-n1;
					break;
				}
				case '*':{
					n1=n2*n1;
					break;
				}
				case '/':{
					n1=n2/n1;
					break;
				}
			}
			s.push(n1);
        }   
	}
	kq=s.top();
	cout<<kq;   
}
main(){
	Nhap();
	Hauto();
	getch();
}
