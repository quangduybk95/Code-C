#include<stdio.h>
#include<string.h>
void innguoc(char a[],char c[])
{ int i,n,j=0;
  n=strlen(a);
  for(i=n-1;i>=0;i--)
    {
      c[j]=a[i];j++;
    }
}
void tachten(char a[],char c[])
{ int i,j=0,n,m=0,x;
  n=strlen(a);i=n-1;
  while(a[i]!=' ') i--;
  for(j=i;j<=n-1;j++)
    {
      c[m]=a[j];m++;
    }
  x=strlen(c);
  for(i=0;i<=x-1;i++)
    {
      c[i]=c[i+1];
    }
}
main()
{
  char a[100],c[100];
   printf("Nhap a : ");gets(a);
  while(strstr(a," ")==NULL)
    {
      printf("Nhap sai : ");gets(a);
    }
  tachten(a,c);
  printf("%s\n",a);
  printf("%s\n",c);
}
