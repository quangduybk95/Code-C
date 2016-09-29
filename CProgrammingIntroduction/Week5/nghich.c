#include<stdio.h>
main()
{
  int a,b,c,d,e,max1,max2;
  printf("Nhap vao 3 so : ");scanf("%d %d %d",&a,&b,&c);
  d = (a+b+c)/3;
  e= d > 10 ? (a+b) : (b-c);
  max1 = a > b ? a : b;
  max2 = max1 > c ? max1 : c;
  printf("So lon nhat la ; %d\n",max2);
  printf("So can tim la : %d\n",e);
}
