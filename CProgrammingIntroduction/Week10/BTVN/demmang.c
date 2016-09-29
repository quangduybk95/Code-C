#include<stdio.h>
main()
{
  int n,i,j,a[10],dem=0,max=0,tg,kt;
  printf("Nhap so phan tu cua mang : ");scanf("%d",&n);
  for (i=0;i<=n-1;i++) {printf("Nhap phan tu thu %d cua mang : ",i+1);scanf("%d",&a[i]);}
  for (i=0;i<=n-1;i++) {if (a[i]==0) dem=dem+1;}
  printf("So phan tu = 0 cua mang la : %d\n",dem);
  dem=0;
for (j=0;j<=n-1;j++)
{
if (a[j]==0)
{
i=j;
do
{
dem++;
i++;
} while (a[i]==0);
if (dem>=max) max=dem;dem=0;
 }
 }
printf("Day dai nhat cac so = 0 la : %d\n",max);
do
{
kt=1;dem=0;
for (i=0;i<=n-1;i++)
{ if (a[i]!=0) 
{
kt=0;
tg=a[i];
a[i]=0;
dem++;
for (j=i;j<=n-1;j++)
if (a[j]==tg)
{
dem++; a[j]=0;
}
printf("So lan xuat hien phan tu %d la: %d\n",tg,dem);dem=0;
};
}
} while (kt==0);
}
