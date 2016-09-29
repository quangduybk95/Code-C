#include<stdio.h>
void xep(int *p,int *q,int *r);
void xep(int *p,int *q,int *r)
{ int tmp;tmp=*p;*p=*q;*q=*r;*r=tmp;}
main(void)
{int a,b,c;
  printf("Nhap 3 so : ");scanf("%d%*c%d%*c%d%*c",&a,&b,&c);
  xep(&a,&b,&c);
  printf("day sap xep :a=%d b=%d c=%d \n",a,b,c);
}

