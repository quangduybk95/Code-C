/*gia sach*/
#include<stdio.h>

main()
{
  int a,b,c,d;
  char e[50];
  printf("Nhap so luong:\n");
  scanf("%d",&a);
  printf("Nhap ma so:\n");
  scanf("%d",&b);
  printf("Nhap ten sach:\n");
  scanf("%[^\n]",e);
  printf("Nhap gia tien:\n");
  scanf("%d%*c", &c);
  d=a*c*1.1;
  printf(" ____________________________________________________\n");
  printf("|                     BK Booksel                     |\n");
  printf("|                                                    |\n");
  printf("|Qty    ISBN    Title            Prince      Total   |\n");
  printf("| _________________________________________________  |\n");
  printf("|%-7d%-8d%-17s%-12d%-8d|\n",a,b,e,c,d);
  printf("|                                                    |\n");
  printf("|VAT 10%%                                             |\n");
  printf("|You pay:%-8d                                    |\n",d);
  printf("|____________________________________________________|\n");

     }
