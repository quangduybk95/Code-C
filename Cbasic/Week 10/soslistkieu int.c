#include<stdio.h>
#define MAX 100
typedef struct
{
  int key;
  int data;
}tk;
int tknhiphan(tk a[],int k,int first,int last)
{
  int mid;
  if(first>last) return -1;
  mid=(first+last)/2;
  if(a[mid].key>k) return tknhiphan(a,k,mid+1,last);
  else
    if(a[mid].key<k) return tknhiphan(a,k,first,mid-1);
    else if(a[mid].key==k)return mid;
}
main()
{
  tk a[MAX],b[MAX];int i,j,n1,n2;
  printf("--------------------------\n");
  printf("Nhap so phan tu day 1 : ");scanf("%d%*c",&n1);
  printf("Nhap ptu day 1 : \n");
  for(i=0;i<n1;i++)
    {
      printf("Nhap key ptu thu %d : ",i+1);
      scanf("%d%*c",&a[i].key);
      printf("Nhap ten ptu thu %d : ",i+1);
      scanf("%d%*c",&a[j].data);
    }
   printf("--------------------------\n");
  printf("Nhap so phan tu day 2 : ");scanf("%d%*c",&n2);
  printf("Nhap ptu day 2 : \n");
  for(j=0;j<n2;j++)
    {
      printf("Nhap key ptu thu %d : ",j+1);
      scanf("%d%*c",&b[j].key);
      printf("Nhap ten ptu thu %d : ",j+1);
      scanf("%d%*c",&b[j].data);
    }
  printf("Ptu co key thuoc list1 nhung khong thuoc list2 la : ");
   for(i=0;i<n1;i++)
    {
      if(tknhiphan(b,a[i].key,0,n1-1)==-1)
     printf("%d ",a[i].key);
    }
   printf("\n");
   printf("Ptu co key thuoc list2 nhung khong thuoc list1 la : ");
   for(j=0;j<n2;j++)
    {
      if(tknhiphan(a,b[j].key,0,n2-1)==-1)
     printf("%d ",b[j].key);
    }
   printf("\n");
    printf("Phan tu thuoc ca list1 va list 2 nhung khac nhau 1 truong bat ki ,co khoa chung la : ");
  for(i=0;i<n1;i++)
    {
      if(tknhiphan(b,a[i].key,0,n1-1)!=-1&&a[i].data!=b[i].data)
     printf("%d ",a[i].key);
    }
  printf("\n");
}
