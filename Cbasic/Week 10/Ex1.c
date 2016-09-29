#include<stdio.h>
#define not -1;
typedef int eltype;
int k=0,b[100],j=0;
int binarysearch(eltype a[],eltype x,int lo,int hi)
{
  if(lo>hi) return not;
  int mid;
  mid=(lo+hi)/2;
  b[j]=mid;j++;
  if(a[mid]<x) {k++;return binarysearch(a,x,mid+1,hi);}
  else if(a[mid]>x) {k++;return binarysearch(a,x,lo,mid-1);}
  else {
    k++;
  return mid;
  }
}
main()
{
  int a[100];
  int i,tk;
  for(i=0;i<100;i++)
    a[i]=i+1;
  printf("Nhap so can tim kiem : ");scanf("%d%*c",&tk);
  if(binarysearch(a,tk,0,99)==-1) printf("Not found\n");
 else printf("Tim thay \n");
  printf("So phep so sanh : %d\n",k);
  printf("Cac chi so mang dc so sanh vs dau ra : ");
  for(i=0;i<j;i++)
    printf("%d ",b[i]);
  printf("\n");
}
 xshel
