#include<stdio.h>
int countEven(int* a,int n);
int countEven(int* a,int n)
{
  int i,dem=0;
  printf("Nhap so ptu : ");scanf("%d",&n);

  for(i=0;i<=n-1;i++)
    { printf("Nhap pt thu %d ",i+1); scanf("%d",&a[i]);
      if (*(a+i)%2==0) dem++;
  }
  printf("so ptu chan la %d\n" ,dem);
  return n;
}
main()
{
  int n,a[20];
 n=countEven(a,n);
}
