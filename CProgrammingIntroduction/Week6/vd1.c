#include<stdio.h>
main()
{
  int d;
  printf("Nhap diem cua ban : ");scanf("%d",&d);
  if (d>=90) printf("Loai A \n"); else if (d>=80) printf("Loai B\n");
  else if (d>=70) printf("Loai C\n");else if (d>=60) printf("Loai D\n");
      else printf("Loai F\n");
}
