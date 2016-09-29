#include<stdio.h>
main(){
char c;float a,b;
 printf("Nhap phep tinh can tinh toan : ");scanf("%c",&c);
switch (c) {
 case '+' : {
   printf("Nhap 2 toan hang : ");scanf("%f%*c%f",&a,&b);
   printf("Ket qua : %.2f + %.2f = %.2f \n",a,b,a+b);break;
 }
 case '-' : {
   printf("Nhap 2 toan hang : ");scanf("%f%*c%f",&a,&b);
   printf("Ket qua : %.2f - %.2f = %.2f \n",a,b,a-b);break;
 }
 case '*' : {
   printf("Nhap 2 toan hang : ");scanf("%f%*c%f",&a,&b);
   printf("Ket qua : %.2f * %.2f = %.2f \n",a,b,a*b);break;
 }
 case '/' : {
   printf("Nhap 2 toan hang : ");scanf("%f%*c%f",&a,&b);
   if (b==0) printf("K co ket qua\n"); else  
     printf("Ket qua : %.2f / %.2f = %.2f \n",a,b,a/b);break;
 }
 default : printf("K co phep tinh can thuc hien\n");break;
 }}
