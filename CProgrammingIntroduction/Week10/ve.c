#include<stdio.h>
void tamgiac(int n){ int j,k,i,d;
d=1;
for(i=1 ;i<=n ;i++)
{
for(j=2*n-d ;j>=0 ;j-- ) printf(" ");
for(k=1 ;k<=d ;k++ ) printf("* ");
printf("\n");
d=d+2;
 }}
void hinhvuong(int n)
{
  int i,j;
  for (j=1;j<=(n-1)/2;j++){
    for (i=1;i<=n;i++)
    printf("* ");
  printf("\n");
  }for (i=1;i<=(n-1)/2;i++) printf("* ");printf("  ");for (i=1;i<=(n-1)/2;i++) printf("* ");printf("\n");
 for (j=1;j<=(n-1)/2;j++){
    for (i=1;i<=n;i++)
    printf("* ");
    printf("\n");}
}
void nhap(){char c;
  printf("Nhap ki tu : \n");scanf("%c%*c",&c);
  if ((('a'<=c)&&('z'>=c))||(('A'<=c)&&('Z'>=c))||(('0'<=c)&&('9'>=c))) printf("%c%*c\n",c);
  else
    printf("Ban nhap sai \n");
}


main(void){int a;int x,y;
   do{  printf("1.Ve tam giac vuong can(phim 1)\n");
   printf("2.Ve hinh vuong (phim 2)\n");
   /* printf("3.Nhap ki tu(phim 3)\n");*/
   printf("3.Thoat(phim 3)\n");
   printf("Moi ban chon chuc nang : ");scanf("%d%*c",&a);
    switch (a){
     case 1 : {printf("Moi ban nhap canh tam giac: ");scanf("%d",&y);
         tamgiac(y);printf("\n");}break;
     case 2 : {printf("Moi ban nhap canh hinh vuong(le): ");scanf("%d",&x);
         hinhvuong(x);printf("\n");}break;
       /*case 3 : {nhap();}break;*/
     case 3 : {printf("Thoat\n");}break;
     default : {printf("ban nhap sai\n");}break;
     }
   }    while(a!=3);


   }
