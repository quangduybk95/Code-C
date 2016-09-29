#include<stdio.h>
main()
{
  char a,b,c,max;
  printf("Nhap chuoi 3 ki tu : ");scanf("%c%c%c",&a,&b,&c);
  max = (a < b ? a:b)<c? (a < b ? a:b) : c;
  printf("ki tu dau tien la : %c\n",max);
}
