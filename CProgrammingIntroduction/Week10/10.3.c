#include<stdio.h>
int nhapmang(int a[])
{int i,n;
  printf("So phan tu cua mang la : ");scanf("%d",&n);
  for (i=0;i<=n-1;i++) {
    printf("Nhap phan tu thu %d : ",i+1);scanf("%d",a[i]);
  } return n;
}
int kt(){int a[10],b[10],x,y,i,j=0;
  x=nhapmang(a);
  y=nhapmang(b);
  for (i=1;i<=x;i++) {if (a[i]!=b[i]) return 0;else return 1;}
}
main()
{
  if (kt()==1) printf("2 mang = nhau\n");else printf("2 mang k = nhau\n");
}
