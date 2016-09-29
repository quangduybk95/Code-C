#include<stdio.h>
main(){
  int a,b,c;
   for (a=0;a<20;a++)
  for (b=0;b<33;b++)
    for (c=0;c<100;c++) {if ((a+b+c==100)&&(5*a+3*b+c/3.0==100))
        printf("dung : %d nam : %d gia : %d \n",a,b,c);
  }
}
