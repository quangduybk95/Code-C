#include<stdio.h>
#include<string.h>
void doixau(char a[],char b[])
{ char tg[100];int x,y,i;
  x=strlen(a);
  y=strlen(b);
   strcpy(tg,a);
  strcat(a,b);
  strcat(b,tg);
  for(i=0;i<=x+y-1;i++)
    { b[i]=b[i+y];
      a[i]=a[i+x];
    }
}
