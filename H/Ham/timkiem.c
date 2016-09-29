#include<string.h>
#include<stdio.h>
typedef struct xx
{
  char name[20];
  int old;
} info;
void nhap(info a[],int n)
{
  int i;
  for(i=0;i<=n-1;i++)
    {
      printf("Nhap thong tin nguoi thu %d \n: ",i+1);
      printf("Nhap ten : ");gets(a[i].name);
      while(strstr(a[i].name," ")==NULL)
        {
          printf("Nhap lai : ");gets(a[i].name);
        }
      printf("Nhap tuoi : ");scanf("%d%*c",&a[i].old);
    }
  printf("Thong ke \n");
    printf("%-20s%-5s\n","Name","Old");
  for(i=0;i<=n-1;i++)
    printf("%-20s%-5d\n",a[i].name,a[i].old);
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
  info a[100];int n=3,i,kt=0,k;char b[100][20];char c[100];
  nhap(a,n);
  printf("Nhap ten can tim : ");gets(c);
  for(i=0;i<=n-1;i++)
     tachten(a[i].name,b[i]);
   for(i=0;i<=n-1;i++)
      { if(strstr(b[i],c)!=NULL) k=1;else k=0;
      if(k==1) {printf("%-s\n",a[i].name);kt=1;}
    }
  if(kt!=1) printf("khong co\n");
}
