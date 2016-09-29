#include<stdio.h>
#include<string.h>
main()
{
  char a[100],b[100],tg[100];int x,y,i;
  printf("Nhap a : ");gets(a);
  printf("Nhap b : ");gets(b);
  x=strlen(a);
  y=strlen(b);
   strcpy(tg,a);
  strcat(a,b);
  strcat(b,tg);
  for(i=0;i<=x+y-1;i++)
    { b[i]=b[i+y];
      a[i]=a[i+x];
    }
  printf("%s\n",a);
  printf("%s\n",b);
}
