#include<stdio.h>
main()
{
  char s[100];int i;i=1;
  printf("Nhap noi dung : ");scanf("%s",&s);
  while (i<=100)
    { if ((s[i]==' ')&&(s[i+1]==' ')) s[i]=getchar();i=i+2;
    }printf("%s\n",s);
}
