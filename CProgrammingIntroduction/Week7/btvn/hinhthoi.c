#include<stdio.h>
main()
{
int j,k,i,n,d,m;
printf("Nhap chieu cao: ");scanf("%d",&n);
d=1;
for(i=1 ;i<=n ;i++)
{
for(j=2*n-d ;j>=0 ;j-- ) printf(" ");
for(k=1 ;k<=d ;k++ ) printf("* ");
printf("\n");
d=d+2;
}
d=d-2;
m=4;
for(i=n-1 ;i>=1 ;i-- )
{
d=d-2;
for(j=1 ;j<=m ;j++ ) printf(" ");m=m+2;
for(k=1 ;k<=d ;k++ ) printf("* ");
printf("\n");
}
}
