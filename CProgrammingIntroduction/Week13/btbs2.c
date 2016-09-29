#include<stdio.h>
#include<string.h>
void left(char a[])
{ int n;char x;
  printf("Nhap xau : ");gets(a);
  n=strlen(a);
  x=a[0];
  a[0]=a[n-1];
  a[n-1]=x;
  printf("Xau sau khi sua : %s \n",a);
}
main()
{ char a[100];
  left(a);
}
