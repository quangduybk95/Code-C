#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"nodestack.h"
node *top1=NULL;
node *top2=NULL;
node *top=NULL;
main()
{ int i,t1,t2,kt=0,s;
  char k[10];
  char so1[50],so2[50];

  printf("Nhap so 1 : ");gets(so1);
  printf("Nhap so 2 : ");gets(so2);
  for(i=0;i<strlen(so1);i++)
    { k[0]=so1[i];
      s=atof(k);
      top1=push(top1,s);
    }
  for(i=0;i<strlen(so2);i++)
    { k[0]=so2[i];
      s=atof(k);
      top2=push(top2,s);
    }
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
   if (kt==1) top=push(top,1);
   while(top!=NULL)
     {
       top=pop(top,&i);
       printf("%d",i);
     }
   printf("\n");
}
