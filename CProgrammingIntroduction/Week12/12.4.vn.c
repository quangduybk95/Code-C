#include<stdio.h>
int nhap(int a[],int n)
{ int i;
  printf("Nhap so ptu cua mang : ");scanf("%d",&n);
  for (i=0;i<=n-1;i++)
    {printf(" nhap ptu thu %d cua mang : ",i+1);scanf("%d",&a[i]);
    }
  return n;
}
main()
{ int n,a[100],i,j,k;
  n=nhap(a,n);
  for(i=0;i<=n-1;i++)
    {
      k=i;
      while (k<=n)
   {
    for(j=i;j<=k;j++)
     printf("%d",a[j]);
   }
      printf("\n");}}
