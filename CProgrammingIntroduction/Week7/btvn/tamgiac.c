#include<stdio.h>
main()
{
int j,k,i,n,d;
printf("Nhap chieu cao: ");scanf("%d",&n);
d=1;
for(i=1 ;i<=n ;i++)
{
for(j=2*n-d ;j>=0 ;j-- ) printf(" ");
for(k=1 ;k<=d ;k++ ) printf("* ");
printf("\n");
d=d+2;
}
}
