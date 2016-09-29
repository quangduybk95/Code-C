#include<stdio.h>
#include<stdlib.h>
#include"nodestack.h"
int dao(int a)
{
  int s=0;
  while(a!=0)
    {
      s=10*s+a%10;
      a=a/10;
    }
  return s;
}
struct node *top1=NULL;
struct node *top2=NULL;
struct node *top=NULL;
main()
{ int i,so1,so2,t1,t2,kt=0,a,b,d1=0,d2=0;

  printf("Nhap so 1 : ");scanf("%d%*c",&so1);a=dao(so1);
  printf("Nhap so 2 : ");scanf("%d%*c",&so2);b=dao(so2);
  while(so1!=0)
    {
      if(so1%10==0) d1++;
      so1=so1/10;
    }
   while(so2!=0)
    {
      if(so2%10==0) d2++;
      so2=so2/10;
    }
  while(a!=0)
    {
      top1=push(top1,a%10);
      a=a/10;
    }
  while(d1>0) {top1=push(top1,0);d1--;}
  while(b!=0)
    {
      top2=push(top2,b%10);
      b=b/10;
    }
  while(d2>0) {top2=push(top2,0);d2--;}
   while(top1!=NULL||top2!=NULL)
     { if(top1!=NULL)
       top1=pop(top1,&t1);
       else t1=0;
       if(top2!=NULL)
        top2=pop(top2,&t2);
       else t2=0;
       i=t1+t2;
       if(kt==1) i=i+1;
       if(i>=10)
         {
           top=push(top,(i-10));
           kt=1;
         }
       else
         {
           top=push(top,i);
           kt=0;
         }
     }
   while(top!=NULL)
     {
       top=pop(top,&i);
       printf("%d",i);
     }
   printf("\n");
}
