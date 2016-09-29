#include<stdio.h>
#include<string.h>
void xoakitu(char *xau,int vitri , int soluong)
{
    if (vitri+soluong-1>strlen(xau)) xau[0]=NULL;
    else
    {
        while (xau[vitri+soluong]!=NULL)
        {
            xau[vitri]=xau[vitri+soluong];
            vitri++;
        }
        xau[vitri]=NULL;
    }
}
void trimMiddle(char a[])
{
  int n,i,x;
  n=strlen(a);
  for(i=0;i<=n-1;i++)
    if (a[i]==' ') {x=i;while(a[x+1]==' ') {xoakitu(a,x+2,1);x++;}}
}
void trimRight(char a[])
{
  int n,i;
  n=strlen(a);i=n-1;
  while(a[i]==' ') {xoakitu(a,i+1,1);i--;}
}
void trimLeft(char a[])
{
  int n,i;
  n=strlen(a);i=0;
  while(a[i]==' ') {xoakitu(a,i+1,1);i++;}
}
main()
{ char a[100];int n;
  printf("Nhap xau :");gets(a);n=strlen(a);
  trimRight(a);trimMiddle(a);trimLeft(a);
  xoakitu(a,0,1); xoakitu(a,n-1,1);
  printf("Xau sau khi sua :%s\n",a);
}
