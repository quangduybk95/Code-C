#include<stdio.h>
main()
{
int a;
char str[30];
printf("Nhap so a : ");scanf("%d%*c",&a);
printf("nhap xau str :");
gets(str);
printf("ket qua la : \n%s\n%d\n",str,a);
}
