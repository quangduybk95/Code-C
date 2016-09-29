#include<stdio.h>
void nhap(int a[],int n);
void sapxep(int a[],int n);
void nhap(int a[],int n)
{
  int i;
  for(i=0;i<=n-1;i++)
    {
      printf("Nhap phan tu thu %d :",i+1);scanf("%d%*c",&a[i]);
    }
}
void sapxep(int a[],int n)
{
  int i,j,tg;
  for(i=0;i<n;i++)
    for(j=i+1;j<n;j++)
      if(a[i]<=a[j])
        {
          tg=a[i];
          a[i]=a[j];
          a[j]=tg;
        }
  for(i=0;i<=n-1;i++)
    printf("%-4d",a[i]);
  printf("\n");
}
main()
{
  int a[100],n=3;
  nhap(a,n);
  sapxep(a,n);
}
