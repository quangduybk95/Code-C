#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define not -1
typedef struct
{
  char name[20];
  char sdt[20];
  char mail[20];
}eltype;
int binarysearch(eltype a[],char x[],int lo,int hi)
{
  if(lo>hi) return not;
  int mid;
  mid=(lo+hi)/2;
  if(strcmp(a[mid].name,x)<0)
      return binarysearch(a,x,mid+1,hi);
  else if (strcmp(a[mid].name,x)>0)
           return binarysearch(a,x,lo,mid-1);
  else if(strcmp(a[mid].name,x)==0)
    return mid;
}
main()
{
  FILE *f;
  f=fopen("book.dat","rb");
  eltype *a;int i;
  a=(eltype *)malloc(10*sizeof(eltype));
  fread(a,sizeof(eltype),10,f);
  char c[100];
  printf("Nhap ten muon tim kiem : ");
  gets(c);
  if(binarysearch(a,c,0,9)==-1) printf("Not found\n");
  else
    {
      printf("Tim thay \n");
      printf("Name : %s\n",a[binarysearch(a,c,0,9)].name);
      printf("SDT : %s\n",a[binarysearch(a,c,0,9)].sdt);
    }
  printf("\n");
}
