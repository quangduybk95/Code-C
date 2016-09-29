#include<stdio.h>
#include<string.h>
#define max 100
void chuyendoi(char a[])
{ char x,y;int n,i=0;
  printf("Nhap xau : ");gets(a);
  n=strlen(a);
  printf("Nhap ki tu thu nhat thuoc xau : ");scanf("%c%*c",&x);
  while(x!=a[i])
  {i++;printf("Ban nhap sai , moi nhap lai phan tu thuoc xau tren : ");
    scanf("%c%*c",&x);}
   printf("Nhap ki tu thu hai : ");scanf("%c%*c",&y);
   for(i=0;i<=n-1;i++)
     if (a[i]==x) a[i]=y;
   printf("Xau sau khi sua doi chuyen  : %s\n",a);
}
main()
{ char a[max];
  chuyendoi(a);
}
