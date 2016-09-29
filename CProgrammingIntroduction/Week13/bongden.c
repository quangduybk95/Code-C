#include<stdio.h>
main()
{ int i,j,a[7][7],ch,b[7][7],t=0;
  for (i=1;i<=5;i++)
    for (j=1;j<=3;j++)
      {a[i][j]=0;b[i][j]=0;}
do
  { printf("\t\tMenu\n");
    printf("1.Xem trang thai gian den bam phim 1 \n");
    printf("2.Bat den theo hang bam phim 2 \n");
    printf("3.Tat den theo hang bam phim 3 \n");
    printf("4.Bat den theo cot bam phim 4 \n");
    printf("5.Tat den theo cot bam phim 5 \n");
    printf("6.Bat den theo vi tri bam phim 6 \n");
    printf("7.Tat den theo vi tri bam phim 7 \n");
    printf("8.Xem cong suat tieu thu cua dan den theo trang thai hien thoi bam phim 8 \n");
    printf("9.Ket thuc chuong trinh bam phim 9 \n");
    printf("\n");
    printf("Moi ban nhap so chuc nang (1-9) : ");scanf("%d",&ch);
    while((ch!=1)&&(ch!=2)&&(ch!=3)&&(ch!=4)&&(ch!=5)&&(ch!=6)&&(ch!=7)&&(ch!=8)&&(ch!=9)) {printf("Moi ban nhap lai chuc nang (1-9) : "); scanf("%d",&ch);}
    switch (ch) {
    case 1 : { 
      printf("Trang thai phong may \n"); 
      for (i=1;i<=5;i++)
	  for (j=1;j<=3;j++)
	    {printf("%d\t ",a[i][j]);if(j==3) printf("\n");}break;}
    case 2 : {
      printf("Moi ban nhap hang den muon bat(1-5) : ");scanf("%d",&i);
      while((i>5)||(i<1)) {printf("Nhap sai, Moi ban nhap hang lai den muon bat(1-5) : ");scanf("%d",&i);}
      for(j=1;j<=3;j++) a[i][j]=1;
      printf("Da bat den o hang %d \n",i);
      printf("\n");break;} 
    case 3 :  {
      printf("Moi ban nhap hang den muon tat (1-5) : ");scanf("%d",&i);
      while((i>5)||(i<1)) {printf("Nhap sai, Moi ban nhap lai hang den muon tat (1-5) : ");scanf("%d",&i);}
      for(j=1;j<=3;j++) a[i][j]=0;
      printf("Da tat den o hang %d \n",i);
      printf("\n");break;} 
case 4 :  {
      printf("Moi ban nhap cot den muon bat (1-3) : ");scanf("%d",&j);
      while((j>3)||(j<1)) {printf("Nhap sai, Moi ban nhap lai cot den muon bat (1-3) : ");scanf("%d",&j);}
      for(i=1;i<=5;i++) a[i][j]=1;
      printf("Da bat den o cot %d \n",j);
      printf("\n");break;} 
case 5 :  {
      printf("Moi ban nhap cot den muon tat (1-3) : ");scanf("%d",&j);
      while((j>3)||(j<1)) {printf("Nhap sai, Moi ban nhap lai cot den muon tat (1-3) : ");scanf("%d",&j);}
      for(i=1;i<=5;i++) a[i][j]=0;
      printf("Da tat den o cot %d \n",j);
      printf("\n");break;} 
case 6 :  {
      printf("Moi ban nhap hang cua den muon bat (1-5) : ");scanf("%d",&i);
      while((i>5)||(i<1)) {printf("Nhap sai, Moi ban nhap lai hang cua den muon bat (1-5) : ");scanf("%d",&i);}
 printf("Moi ban nhap cot cua den muon tat (1-3) : ");scanf("%d",&j);
      while((j>3)||(j<1)) {printf("Nhap sai, Moi ban nhap lai cot cua den muon bat (1-3) : ");scanf("%d",&j);}
     a[i][j]=1;
      printf("Da bat den o hang %d cot %d \n",i,j);
      printf("\n");break;} 
case 7 :  {
      printf("Moi ban nhap hang cua den muon tat (1-5) : ");scanf("%d",&i);
      while((i>5)||(i<1)) {printf("Nhap sai, Moi ban nhap lai hang cua den muon tat (1-5) : ");scanf("%d",&i);}
 printf("Moi ban nhap cot cua den muon tat (1-3) : ");scanf("%d",&j);
      while((j>3)||(j<1)) {printf("Nhap sai, Moi ban nhap lai cot cua den muon tat (1-3) : ");scanf("%d",&j);}
     a[i][j]=0;
      printf("Da tat den o hang %d cot %d \n",i,j);
      printf("\n");break;} 
    case 8 : {for (i=1;i<=5;i++)
    for (j=1;j<=3;j++)
      { if (a[i][j]==0) b[i][j]=0;
	if (a[i][j]==1){ 
	  if ((i%2==1)&&(j%2==1)) b[i][j]=10; else 
	    if ((i%2==0)&&(j%2==0)) b[i][j]=20; else b[i][j]=15;}
	t=t+b[i][j];
	printf("%d - %d W\t",a[i][j],b[i][j]);
	if (j==3) printf("\n");
      }	
 printf("\n");
 printf("Tong cong suat dang su dung cua dan den la : %d W \n",t);   break;}
    case 9 : printf("Ket thuc chuong trinh \n");printf("\n");break;
}} while (ch!=9);
  }


