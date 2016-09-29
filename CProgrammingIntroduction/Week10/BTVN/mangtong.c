#include<stdio.h>
int max(int a, int b,int c){
  int max,x;
  x = a>b? a:b;
  max = x>c? x:c;
  return max;}
main()
{
  int a[10],n,i,t,dem;t=0;
  printf("Nhap so phan tu cua mang : ");scanf("%d",&n);
  for (i=0;i<=n-1;i++) {printf("Nhap phan tu thu %d cua mang : ",i+1);scanf("%d%*c",&a[i]);}
  for (i=0;i<=n-3;i++) {dem=max(a[i],a[i+1],a[i+2]) ;t=t+dem;}
  printf("Tong can tim la : %d\n",t);
}
