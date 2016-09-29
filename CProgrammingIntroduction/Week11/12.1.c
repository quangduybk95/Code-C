#include<stdio.h>
main()
{
  int a,b,c;
  int *x;
  x=&a;
  printf("Nhap so thu 1 : ");scanf("%d",&a);
  printf("%d\n",*x);
  x=&b;
  printf("Nhap so thu 2 : ");scanf("%d",&b);
  printf("%d\n",*x);x=&c;
  printf("Nhap so thu 3 : ");scanf("%d",&c);
  printf("%d\n",*x);
}
