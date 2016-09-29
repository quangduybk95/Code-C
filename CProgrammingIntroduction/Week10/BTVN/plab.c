#include<stdio.h>
main(){
  int i,j,a[11][11],so,ch,dem,diennang,giatien,c[11][11],max,min,n=0;char *b[11][11];dem=0;max=0;
for (i=1;i<=10;i++)
    for (j=1;j<=4;j++)
      {   a[i][j]=(i-1)*4+j;
	b[i][j]="OFF";
	c[i][j]=0;}
  do{printf("\t\t\tMENU \n");
  printf("\n");
  printf("1. Xem trang thai phong may nhap so 1\n");
  printf("2. Muon su dung may nhap so 2 \n");
  printf("3. Muon dung su dung may nhap so 3 \n");
  printf("4. Xem may su dung nhieu lan nhat va it lan nhat an phim 4 \n");
  printf("5. Xem tich luy dien o thoi diem hien tai cua tung may bam phim 5 \n");
  printf("6. In ra tong dien nang tieu thu va tien dien hien tai bam phim 6 \n");
  printf("7. Quit \n");
  printf("\n");
  printf("Moi ban nhap chuc nang : ");scanf("%d",&ch);printf("\n");
  while  ((ch!=1)&&(ch!=2)&&(ch!=3)&&(ch!=4)&&(ch!=5)&&(ch!=6)&&(ch!=7)) {printf("Ban nhap sai moi ban nhap lai (1-7) ");scanf("%d",&ch);}
  switch (ch) {
  case 1 : {
  printf("\t\t\tMoi ban xem mo hinh va trang thai phong may : \n ");
  printf("\n");
  for (i=1;i<=10;i++)
    for (j=1;j<=4;j++)
      {
	printf("\t%-2d - %3s - %d lan\t",a[i][j],b[i][j],c[i][j]);
	if (a[i][j]%4==0) printf("\n");}break;}
  case 2 : {
    printf("Moi ban nhap hang cua may muon dung(1-10) : ");scanf("%d",&i);while ((i>10)||(i<1)) {printf("Ban nhap sai , moi ban nhap lai (1-10) : ");scanf("%d",&i);}
    printf("Moi ban nhap cot cua may muon dung(1-4) : ");scanf("%d%*c",&j);while ((j>4)||(j<1)) {printf("Ban nhap sai , moi ban nhap lai (1-4) : ");scanf("%d",&j);} printf("\n");
    while(b[i][j]=="ON")  {printf("May dang su dung , moi ban chon may khac \n");printf("\n");
printf("Moi ban nhap hang cua may muon dung(1-10) : ");scanf("%d",&i);while ((i>10)||(i<1)) {printf("Ban nhap sai , moi ban nhap lai (1-10) : ");scanf("%d",&i);}
 printf("Moi ban nhap cot cua may muon dung(1-4) : ");scanf("%d%*c",&j);while ((j>4)||(j<1)) {printf("Ban nhap sai , moi ban nhap lai (1-4) : ");scanf("%d",&j);} printf("\n");}
    if (b[i][j]=="OFF") {printf("Moi ban su dung \n");printf("\n");b[i][j]="ON";c[i][j]++;}break;}
  case 3 : {printf("Nhap hang` cua may ban muon tat : ");scanf("%d",&i);while ((i>10)||(i<1)) {printf("Ban nhap sai , moi ban nhap lai (1-10) : ");scanf("%d",&i);}
      printf("Nhap cot cua may ban muon tat : ");scanf("%d",&j);while ((j>4)||(j<1)) {printf("Ban nhap sai , moi ban nhap lai (1-4) : ");scanf("%d",&j);} printf("\n");
b[i][j]="OFF";printf("Da dung su dung \n");break;}
  case 5 : { printf("\t\t\tMoi ban trang thai tich luy dien su dung cua phong may : \n ");
  printf("\n");
  for (i=1;i<=10;i++)
    for (j=1;j<=4;j++)
      {
	printf("\t%-2d - %d watt\t",a[i][j],c[i][j]*400);
	if (a[i][j]%4==0) printf("\n");}break;}

  case 4 : {    printf("Nhung may dung nhieu lan nhat la : may ");
 for (i=1;i<=10;i++)
   for (j=1;j<=4;j++) if (c[i][j]>=max) {max=c[i][j];printf("%d, ",a[i][j]);}
 printf("\n");
 printf("Nhung may dung it lan nhat la : may ");    min=c[1][1];
 for (i=1;i<=10;i++)
   for (j=1;j<=4;j++) if (c[i][j]<=min) {min=c[i][j];printf("%d, ",a[i][j]);}
printf("\n");
     printf("\n");break;}

  case 6 : { for (i=1;i<=10;i++)
	for (j=1;j<=4;j++) n=n+c[i][j];
      printf("Tong dien nag tieu thu : %d watt\n",n*400);
      printf("Tien dien hien tai     : %d dong(750d/1kw)\n",n*400*750/1000);printf("\n");break;}
  case 7 : {printf("Quit \n");break;}}}
while (ch!=7);
}
