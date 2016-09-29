#include<stdio.h>
main()
{
  int n,r;
  printf("Nhap so sinh vien: ");scanf("%d",&n);

  r = n%7;
  printf("so luong sinh vien trong nhom nho nhat : %d\n",n/7);
  printf("so luong sinh vien trong nhom lon nhat : %d\n",(n+6)/7);
  printf("so luong sinh vien trung binh cua moi nhom : %.2f\n",n/7.0);
  printf("So nhom tren kick thuoc trung binh la : %d\n",r);
  printf("So nhom duoi kick thuoc trung binh la : %d\n",7-r);
  printf("So sinh vien trong cac nhom co kick thuong >=tb la %d:\n",r*(n/7)+(7-r)*((n+6)/7));
  printf("So sv con` lai : %d \n",n-r*(n/7)-(7-r)*((n+6)/7));
}

