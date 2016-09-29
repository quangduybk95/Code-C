#include<stdio.h>
main()
{ int ran,stt1,stt2,d1,d2,t;
  	srand ( time ( NULL ));
	ran = 1 + rand () % 10;
    if (ran%2==0) {stt1=1 ; stt2=2;} else {stt1=2;stt2=1;}
    t=0;
    printf("ICT GAME CENTER - SMART STRAEGY\n");
    printf("start : 0 <-\n");
    printf("destination : 30 <- \n");
    printf("who play first (randomly) :P%d\n",stt1);
  do  { printf("P%d - turn\n",stt1);
     printf("Choose a number : ");scanf("%d",&d1);
      if ((d1>0)&&(d1<=5)) t=t+d1;if (d1>5) printf("Ban can nhap so <5 \n");
    if (d1<=0) printf("Ban can nhap so >0 \n");
      printf("Now the value is : %d \n",t);}  while ((d1>5)||(d1<=0));
      do{
    printf("P%d - turn\n",stt2);
    printf("Choose a number : ");scanf("%d",&d2);
    if ((d1-d2)%2==0) printf("Ban can nhap so co tinh chan le khac voi nguoi choi truoc\n");
    if ((d2>0)&&(d2<=5)&&((d1-d2)%2!=0)) t=t+d2;
    if (d2>5) printf("Ban can nhap so <5\n");
    if (d2<=0) printf("Ban can nhap so >0\n"); printf("Now the value is : %d \n",t);
      } while ((d2>5)||(d2<=0)||((d1-d2)%2==0));
    do{do{
    printf("P%d - turn\n",stt1);
    printf("Choose a number : ");scanf("%d",&d1);
    if ((d1-d2)%2==0) printf("Ban can nhap so co tinh chan le khac voi nguoi choi truoc\n");
    if ((d1>0)&&(d1<=5)&&((d1-d2)%2!=0)) t=t+d1;if (d1>5) printf("Ban can nhap so <5 \n");
    if (d1<0) printf("Ban can nhap so >0 \n");
      printf("Now the value is : %d \n",t);
      if ((t==30)&&((d1-d2)%2!=0)) printf("Nguoi thang cuoc la nguoi choi %d\n",stt1);
      else if ((t>30)&&((d1-d2)%2!=0)) printf("Nguoi thang cuoc la nguoi choi %d\n",stt2 );if (t>=30) break;}  while ((d1>5)&&(d1<=0)&&(d1-d2)%2!=0);
      do{
    printf("P%d - turn\n",stt2);
    printf("Choose a number : ");scanf("%d",&d2);
    if ((d1-d2)%2==0) printf("Ban can nhap so co tinh chan le khac voi nguoi choi truoc\n"); 
    if ((d2>=0)&&(d2<=5)&&((d1-d2)%2!=0)) t=t+d2;
    if (d2>5) printf("Ban can nhap so <5\n");
    if (d2<0) printf("Ban can nhap so >0\n"); printf("Now the value is : %d \n",t);if ((t==30)&&((d1-d2)%2!=0)) printf("Nguoi thang cuoc la nguoi choi %d\n",stt2);
    else if ((t>30)&&((d1-d2)%2!=0)) printf("Nguoi thang cuoc la nguoi choi %d\n",stt1 );if (t>=30) break;
      } while ((d2>5)&&(d2<=0)&&((d1-d2)%2!=0));}
      while (t<30);
}

