#include<stdio.h>
#include<string.h>
float luythua(float a,int n)
{
int i,lt=1;
for (i=1;i<=n;i++)
lt=lt*a;
return lt;
}
void main()
{
int j,k, n,thuong,du,kq=0,dem=0;
char c,s[20];
do
{
printf("Moi ban nhap mot so nguyen duong can doi co so: ");
scanf("%d",&n);
if (n<=0) printf("Ban da nhap sai, hay nhap mot so nguyen duong \n");
} while (n<=0);
k=n;
do
{
printf("Ban hay chon mot trong so cac chuc nang sau: \n 1. Nhan 1 de doi sang he nhi phan \n 2. Nhan 2 de doi sang he co so 8 \n 3. Nhan 3 de doi sang he hexa \n 4. Nhan Q de thoat\n");
scanf("%*[\n\t]%c",&c);
if ((c!='1')&&(c!='2')&&(c!='3')&&(c!='Q')) printf("Ban da chon sai, moi ban chon lai \n");
} while ((c!='1')&&(c!='2')&&(c!='3')&&(c!='Q'));
switch (c)
{
case '1':
{
printf("Ban da chon doi sang he nhi phan \n");
do 
{
thuong=n/2;du=n%2;
n=thuong;
kq=kq+du*luythua(10,dem);
dem++;
} while (thuong>0);
printf("Gia tri nhi phan cua %d la:%d\n ",k,kq);
break;
} 
case '2':
{ 
printf("Ban da chon doi sang he co so 8\n");
do
{
thuong=n/8;du=n%8;
n=thuong;
kq=kq+du*luythua(10,dem);
dem++;
} while (thuong>0);
printf("Gia tri cua %d trong he co so 8 la: %d \n",k,kq);
break;
}
case '3': 
{
printf("Ban da chon doi sang he hexa\n");
do
{
thuong=n/16;du=n%16;
n=thuong;
switch (du)
{
case 1: s[dem]='1';break;
case 2: s[dem]='2';break;
case 3: s[dem]='3';break;
case 4: s[dem]='4';break;
case 5: s[dem]='5';break;
case 6: s[dem]='6';break;
case 7: s[dem]='7';break;
case 8: s[dem]='8';break;
case 9: s[dem]='9';break;
case 10: s[dem]='A';break;
case 11: s[dem]='B';break;
case 12: s[dem]='C';break;
case 13: s[dem]='D';break;
case 14: s[dem]='E';break;
case 15: s[dem]='F';break;
}
dem++;
} while (thuong>0);
printf("Gia tri cua %d trong he Hexa la: ",k);
for (j=dem-1;j>=0;j--) printf("%c",s[j]);
printf("\n");
break;
}
case 'Q':
{
break;
}
}
}
