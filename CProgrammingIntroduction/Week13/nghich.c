#include<stdio.h>

int dem(char a[])
{int i=0,dem=0;
  printf("Nhap xau : ");gets(a);
 do
   { if (a[i]==' ') dem=dem+1;i++;}
 while(a[i]!='\n');
  return dem;
}
main()
{
  char b[100];int d;
  d=dem(b);
  printf("So ki tu trang la : %d\n ",d);
  printf("\n");
}
