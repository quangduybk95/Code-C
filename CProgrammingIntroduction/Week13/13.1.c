#include<stdio.h>
#include<string.h>
int dem(char a[])
{int i,dem=0;int n;
  printf("Nhap xau : ");gets(a);
  n=strlen(a);
  for(i=0;i<=n-1;i++)
      if (a[i]==' ') dem=dem+1;
  return dem;
}
main()
{
  char b[100];int d;
  d=dem(b);
  printf("So ki tu trang la : %d\n ",d);
  printf("\n");
}
