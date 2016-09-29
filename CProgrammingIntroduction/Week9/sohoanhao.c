#include<stdio.h>
main()
{
  int t,i,a,n;
  printf("Nhap khoang : ");scanf("%d",&n);
  for (i=1;i<=n;i++) {t=0;
    for (a=1;a<=i/2;a++) 
      {if (i%a==0) t=t+a;}
    if (t==i) printf("%d \n",i);}}
