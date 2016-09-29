#include<iostream>
#include<conio.h>
#include<fstream>
#include<stack>
using namespace std;
string posfix="";
string infix;
int DoUuTien(char v){
	if(v=='+'||v=='-') return 1;
	else if(v=='*'||v=='/'||v=='^')return 2;
	else return 0;
}
void Nhap(){
	fstream fi;
	fi.open("De_04.txt",ios::in);
	fi>>infix;
	fi.close();
}
void InfixtoPosfix(){
	stack<char>s;
	for(int i=0;i<infix.length();i++){
		if(infix[i]>='a'&&infix[i]<='z')posfix=posfix+infix[i];
		else if(infix[i]=='(')s.push(infix[i]);
		else if(infix[i]==')'){
			while(!s.empty()){
				char u=s.top();
				if(u!='('){
					posfix=posfix+u;
					s.pop();
				}
				else{
					break;
				}
			}
			s.pop();
		}
		else{
			while(!s.empty()){
				char z=s.top();
				if(DoUuTien(z)>=DoUuTien(infix[i])){
					posfix=posfix+z;
					s.pop();
				}
				break;
			}
			s.push(infix[i]);
		}
	}
	while(!s.empty()){
		char v=s.top();
		posfix=posfix+v;
		s.pop();
	}
}
main(){
	Nhap();
	InfixtoPosfix();
	cout<<posfix;
	getch();
}
