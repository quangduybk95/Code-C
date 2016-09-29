#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"stack2.h"
int doi(char a)
{
  if(a=='/'||a=='*') return 2;
  if(a=='+'||a=='-') return 1;
  if(a=='('||a==')') return 3;
  return 0;
}
void chuyendoi(char a[],char b[])
{
  stacktype x;
  x.top=0;
  int i,j=-1,n,m;
  n=strlen(a);
  for(i=0;i<n;i++)
    {
      if(doi(a[i])==0) {j++;b[j]=a[i];}
    else  if(a[i]=='(') push('(',&x);
      else if(a[i]==')')
        { while(x.storage[x.top-1]!='(')
           {
             j++;b[j]=pop(&x);
           }
          pop(&x);
        }
     else if(doi(a[i])==1||doi(a[i])==2)
        {
          if(x.top==0) push(a[i],&x);
          else
            {m=doi(x.storage[x.top-1]);
              while(m>=doi(a[i]))
                {
                  j++;b[j]=pop(&x);m=doi(x.storage[x.top-1]);
                }
              }
        }
    }
  while(x.top>=0)
    { j++;b[j]=pop(&x);}
}
int main()
{
  int lc;char s[100],s1[100];
  do
    {
      printf("\nMENU\n");
      printf("1.Nhap bieu thuc \n");
      printf("2.Chuyen sang hau to\n");
      printf("3.Tinh gia tri\n");
      printf("4.Thoat\n\n");
      printf("Nhap lua chon(1-4) : ");
      scanf("%d%*c",&lc);
      switch(lc)
        {
        case 1 :
          printf("Moi ban nhap bieu thuc : ");
          scanf("%[^\n]s",s);
          //  gets(s);
          break;
        case 2 :
          printf("%s\n",s);
          chuyendoi(s,s1);
          printf("%s\n",s1);
          break;
        case 4 : printf("\nEXIT\n");
        default : printf("ban nhap sai\n");break;
        }
    }
  while(lc!=4);
  return 0;
}
