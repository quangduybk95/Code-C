#include<stdio.h>
main()
{ int ran,stt1,stt2,d1,d2,k,t;
  	srand ( time ( NULL ));
	ran = 1 + rand () % 10;
    if (ran%2==0) {stt1=1 ; stt2=2;} else {stt1=2;stt2=1;}
    t=0;
    printf("ICT GAME CENTER - SMART STRAEGY\n");
    printf("start : 0 <-\n");
    printf("destination : 30 <- \n");
    printf("who play first (randomly) : %d\n",stt1);
    do{do{
    printf("P%d - turn\n",stt1);
    printf("Choose a number : %d");scanf("%d",&d1);
    if ((d1>=0)&&(d1<=5)) t=t+d1;if (d1>5) printf("<value ... >5\n");
    if (d1<0) printf("invalue .. so>0\n");
      printf("Now the value is : %d \n",t);
      if (t==30) printf("Nguoi thang cuoc la nguoi choi %d\n",stt1);
    else if (t>30) printf("Nguoi thang cuoc la nguoi choi %d\n",stt2 );}  while (d1>5);
      do{
    printf("P%d - turn\n",stt2);
    printf("Choose a number : %d");scanf("%d",&d2);
    if ((d2>=0)&&(d2<=5)) t=t+d2;
    if (d2>5) printf("<value ... >5\n");
    if (d2<0) printf("invalue .. so >0\n"); printf("Now the value is : %d \n",t);if (t==30) printf("Nguoi thang cuoc la nguoi choi %d\n",stt2);
    else if (t>30) printf("Nguoi thang cuoc la nguoi choi %d\n",stt1 );
   } while (d2>5);}
      while (t<=30);
}
