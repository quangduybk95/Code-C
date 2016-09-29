#include<stdio.h>
#include<stdlib.h>
#define not -1;
typedef int eltype;
int binarysearch(eltype a[],eltype x,int lo,int hi)
{
  if(lo>hi) return not;
  int mid;
  mid=(lo+hi)/2;
  if(a[mid]<x) return binarysearch(a,x,mid+1,hi);
  else if(a[mid]>x) return binarysearch(a,x,lo,mid-1);
  else
    return mid;
}
main()
{
  int i,j,a[100],b[100],n1,n2;
 printf("--------------------------\n");
  printf("Nhap so phan tu day 1 : ");scanf("%d%*c",&n1);
  printf("Nhap ptu day 1 : \n");
  for(i=0;i<n1;i++)
    {
      printf("Nhap key ptu thu %d : ",i+1);
      scanf("%d%*c",&a[i]);
    }
   printf("--------------------------\n");
  printf("Nhap so phan tu day 2 : ");scanf("%d%*c",&n2);
  printf("Nhap ptu day 2 : \n");
  for(j=0;j<n2;j++)
    {
      printf("Nhap key ptu thu %d : ",j+1);
      scanf("%d%*c",&b[j]);
    }
  printf("Cac ptu co trong a ma co trong b la : ");
  for(i=0;i<n1;i++)
    {
      if(binarysearch(b,a[i],0,n1-1)!=-1) printf("%d ",a[i]);
    }
    printf("\n");

   printf("Cac ptu co trong a ma k co trong b la : ");
  for(i=0;i<n2;i++)
    {
      if(binarysearch(b,a[i],0,n1-1)==-1) printf("%d ",a[i]);
    }
    printf("\n");
   printf("Cac ptu co trong b ma co trong a la : ");
  for(i=0;i<n2;i++)
    {
      if(binarysearch(a,b[i],0,n2-1)==-1) printf("%d ",b[i]);
    }
  printf("\n");
}
