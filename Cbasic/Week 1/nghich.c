#include<stdio.h>
void nhap(int a[],int n)
{
  printf("Nhap so ptu cua mang : ");scanf("%d%*c",&n);
  for(i=0;i<n;i++)
    {
      printf("Nhap ptu thu %d : ",i+1);scanf("%d%*c",&a[i]);
    }
}
int xetmang(int a[],int b[])
{
  int n1,n2,i,k=0,t=0,j;
  printf("Nhap mang thu nhat :  \n");
  nhap(a,n1);
   printf("Nhap mang thu hai :  \n");
  nhap(a,n2);
   if(n1!=n2) return 0;
  for(i=0;i<n-1;i++)
    {
      if(a[i]==b[i]) k=1; else break;
    }
     if (k==1) return 1;
     for(i=0;i<n;i++)
       for(j=n-1;j>=0;j--)
         {
           if(a[i]==b[j]) t=1; else break;
         }
     if(t==1) return -1;
}
main()
{
  int a[10],b[10];
  xetmang(a,b);
}
