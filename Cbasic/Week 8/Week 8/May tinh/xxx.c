#include "stackarray.h"

int priority(char x);
int getInt();
int menu();
void postfix(char bieuthuc[]);
//ham kiem tra do uu tien cua phep toan
int priority(char x){
  if(x=='(')
    return 0;
  if(x=='+'||x=='-')
    return 1;
  if(x=='*'||'/'||x=='%')
    return 2;
  if(x=='^')
    return 3;
  return 4;
}
main(){
  stacktype s;
  int choice;
  int token,i=0;
  char bieuthuc[MAX];
  elementtype x;
  char a[100];
  do{
    choice=menu();
    switch(choice){
    case 1:
      printf("Nhap 1 bieu thuc: ");
      scanf("%s%*c",bieuthuc);
      break;
    case 2:
      printf("Bieu thuc ban dau la %s\n",bieuthuc);
      printf("Bieu thuc chuyen sang dang hau to la ");
     postfix(bieuthuc);
      break;
    case 3:

      break;
    }
  }while(choice!=4);
}


void postfix(char bieuthuc[]){
  stacktype s;
  elementtype x;
  int token,i=0;
  char a[100];int j=0;
  initialize(&s);
  //ham isalnum nam trong thu vien ctype.h de ktra ki tu nhap vao co la chu so hoac chu cai ko. neu ko phai tra ve 0

  while((token=bieuthuc[i++])!='\0'){
    if(isalnum(token))
      // printf("%c",token);
      {a[j]=token;j++;}
    else if(token=='(')
      push('(',&s);
    else{
      if(token==')')
	while((a[j]=pop(&s))!='('){
      j++;
       	  if(token=='('){
	    //   printf(")####\nBieu thuc loi do thieu hoac thua dau (,)\n");
	    break;
	  }
	}
      else{
	//khi phep toan o dinh co do uu tien >= phep toan hien tai thi pop toan tu do ra. Sau push toan tu hien tai vao
	while(priority(token)<=priority(top(&s))&&(!empty(&s))){
	  a[j]=pop(&s);j++;
	}
	push(token,&s);
      }
    }
  }
  while(!empty(&s)){
    a[j]=pop(&s);j++;
    //  printf("%c",x);
  }
  printf("%s \n",a);
  printf("\nExit\n");
}

int menu(){
  int cn;
  printf("\n\t---MENU---\n");
  printf("\t1. Nhap bieu thuc so hoc\n");
  printf("\t2. Doi sang dang hau to\n");
  printf("\t3. Tinh gia tri\n\t4. Exit\n\tYou choose? ");
  do{
    cn=getInt();
    if(cn<1||cn>9)
      printf("Please choose again(1-4): ");
  }while(cn<1||cn>4);
  return cn;
}

int getInt(){
  int re;
  while(scanf("%d%*c",&re)!=1){
    printf("This is not an integer number. Please retype the input: ");
    while(getchar()!='\n');
  }
  return re;
}
