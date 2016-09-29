#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#define MAX 10
typedef struct
{
  char caller[30];
  char called[30];
  // char begin[10];
  int during;
}element;
void swap(element *a, element *b){
  element temp;
  temp=*a;
  *a=*b;
  *b=temp;
}

void quicksort(element a[],int left,int right)
{
  int pivot,i,j;
  if(left<right)
    {
      i=left;
      j=right+1;
      pivot=a[left].during;
      do{
      do i++ ; while (a[i].during<pivot);
      do j--; while(a[j].during>pivot);
      if(i<j) swap(&a[i],&a[j]);
    }
      while (i<j);
      swap(&a[left],&a[j]);
      quicksort(a,left,j-1);
      quicksort(a,j+1,right);
    }
}
main()
{
  int i,x,j;
  FILE *f;
  f=fopen("phone.txt","w+");
   element a[MAX];
  for(j=0;j<MAX;j++)
    {
      element tmp;
      char p[9],q[9];
       p[0]='0';
    for(i=1;i<10;i++)
      {
            x=rand()%10;
            if(x==0) p[i]='0';
           else if(x==1) p[i]='1';
           else if(x==2) p[i]='2';
           else if(x==3) p[i]='3';
           else if(x==4) p[i]='4';
           else if(x==5) p[i]='5';
           else if(x==6) p[i]='6';
           else if(x==7) p[i]='7';
           else if(x==8) p[i]='8';
           else if(x==9) p[i]='9';
      }
    strcpy(tmp.caller,p);
    q[0]='0';
     for(i=1;i<10;i++)
      {
            x=rand()%10;
            if(x==0) q[i]='0';
           else if(x==1) q[i]='1';
           else if(x==2) q[i]='2';
           else if(x==3) q[i]='3';
           else if(x==4) q[i]='4';
           else if(x==5) q[i]='5';
           else if(x==6) q[i]='6';
           else if(x==7) q[i]='7';
           else if(x==8) q[i]='8';
           else if(x==9) q[i]='9';
      }
     strcpy(tmp.called,q);
         do
           {
             tmp.during=rand()%3600;
           }
           while(tmp.during==0);
         a[j]=tmp;
    }
  quicksort(a,0,MAX-1);
  for(i=0;i<MAX;i++)
  fprintf(f,"%-9s\t%-9s\t%-2d:%-2d:%-2d\t%-4d\n",a[i].caller,a[i].called,rand()%24,rand()%60,rand()%60,a[i].during);
  fclose(f);
}
