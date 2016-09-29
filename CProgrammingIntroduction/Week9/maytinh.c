#include<stdio.h>
#include<math.h>
float luythua(float a,int n)
{
int i,lt=1;
for (i=1;i<=n;i++)
lt=lt*a;
return lt;
}
int giaithua(int n)
{
int i,gt=1;
for (i=1;i<=n;i++)
gt=gt*i;
return gt;
}
void main()
{
float x,saiso,sinx,ex,sqrtx,kq;
char kt,yn;
int c=1;

printf("Xin ban hay nhap sai so: ");
scanf("%f",&saiso);
do
{
printf("Ban hay chon mot trong 4 chuc nang sau: \n 1. Nhan C de tinh can bac 2 cua x \n 2. Nhan S de tinh sinx \n 3. Nhan E de tinh e mu x \n 4. Nhan Q de thoat \n");
scanf("%*[ \n\t]%c",&kt);
if ((kt!='C')&&(kt!='S')&&(kt!='Q')&&(kt!='E')) printf("Ban da chon sai, moi ban chon lai\n");
} 
while ((kt!='C')&&(kt!='S')&&(kt!='Q')&&(kt!='E'));
switch(kt)
{
case 'S': 
{
printf("Ban da chon chuc nang tinh sinx\n");printf("Moi ban nhap mot so x : ");
scanf("%f",&x);
sinx=x;
do 
{
kq=sinx;
sinx=sinx+luythua(-1,c)*(luythua(x,2*c+1))/(giaithua(2*c+1));
c++;
}
while (fabs(kq-sinx)>saiso);
printf("Gia tri gan dung cua sinx la: %f\n",sinx);
break;
}
case 'E':
{
printf("Ban da chon chu nang tinh e mu x: \n");
printf("Moi ban nhap mot so x : ");
scanf("%f",&x);
ex=1;c=1;
do
{
kq=ex;
ex=ex+luythua(x,c)/giaithua(c);
c++;
}
while (fabs(kq-ex)>saiso);
printf("Gia tri gan dung cua e mu x la: %f\n",ex);
break;
}
case 'C':
{
printf("Ban da chon chuc nang tinh can bac 2 cua x \n");
do
{
printf("Moi ban nhap mot so x duong: ");
scanf("%f",&x);
if (x<0) printf("Xin hay nhap mot so x duong\n");
} 
while (x<0);
sqrtx=(x+1)/2;
do
{
kq=sqrtx;
sqrtx=0.5*(sqrtx+x/sqrtx);
}
while (fabs(kq-sqrtx)>saiso);printf("Can bac 2 cua x la: %f",sqrtx);
break;
}
case 'Q': 
{
break;
}
}
}
