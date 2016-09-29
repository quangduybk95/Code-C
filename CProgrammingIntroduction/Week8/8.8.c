#include<stdio.h>
main(){int i,n,k;i=1;k=1;
  printf("Nhap so n ");scanf("%d",&n);
  while (i<=n)
    {k=k*i;i=i++;}
  printf("n! la : %d\n",k);
}
