#include<stdio.h>
#include<stdlib.h>
void insertsort(int a[],int n)
{
  int i,j;
  int next;
  for(i=1;i<n;i++)
    {
      next=a[i];
      for(j=i-1;j>=0&&next<a[j];j--)
          a[j+1]=a[j];
          a[j+1]=next;
    }
}
void selectionsort(int a[],int n)
{
  int i,j, min,tmp;
  for(i=0;i<n-1;i++)
    {
      min=i;
      for(j=i+1;j<=n-1;j++)
        if(a[j]<a[min]) min=j;
      tmp=a[i];
      a[i]=a[min];
      a[min]=tmp;
    }
}
main()
{
  int a[10]={3,1,5,6,2,9,0,10};
  int i;
  selectionsort(a,8);
  for(i=0;i<8;i++)
    {
      printf("%d \n",a[i]);
    }
}
