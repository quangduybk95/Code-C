#include<stdio.h>
#include<string.h>
void left(char a[])
{
  int i,n,tg;
  printf("Nhap xau : ");gets(a);n=strlen(a);
  tg=a[n-1];
   for(i=n-1 ;i>=1  ;i-- )
     a[i]=a[i-1];
  a[0]=tg;
  printf("Xau sau khi doi chieu : %s\n",a);
}
void right(char a[])
{
  int i,tg,n;
   printf("Nhap xau : ");gets(a);n=strlen(a);

  tg=a[0];
  for(i=0 ;i<=n-2  ;i++ )
    a[i]=a[i+1];
   a[n-1]=tg;
   printf("Xau sau khi doi chieu : %s \n",a);
}
main()
{
  char a[100];
  left(a);
  right(a);
}


