#include <stdio.h>
main(){
int c;
do {
printf("\tMenu\n");
printf("1.In ra so 1\n");
printf("2.In ra so 2\n");
printf("3.In ra so 3\n");
printf("4.In ra so 4\n");
printf("5.In ra so 5\n");
printf("6.Quit\n");
printf("Moi ban nhap so thu tu cua yeu cau: ");scanf("%d",&c);
switch (c) {
 case 1 : printf("1\n");break;
 case 2 : printf("2\n");break;
 case 3 : printf("3\n");break;
 case 4 : printf("4\n");break;
 case 5 : printf("5\n");break;
 case 6 : printf("Quit\n");break;}}
 while (c!=6);
 }
