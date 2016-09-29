#include<stdio.h>
main()
{
  float a,b,c,f;
  printf("Chuong trinh chuyen doi do C sang do F\n");
  printf("Nhap diem dau(do C): ");
  scanf("%f", &a);
  printf("Nhap diem cuoi(do C): ");
  scanf("%F", &b);
  printf("Nhap buoc nhay: ");
  scanf("%f", &c);
  f=(a-32)/1.8;
  printf("  |%-20s|%-20s|\n","Do C","Do F");
  printf("  |%-20g|%-20g|\n",a,f);
  while((a+c)<b)
    {
      a=a+c;
      f=(a-32)/1.8;
      printf("   |%-20g|%-20g|\n",a,f);
    }
  printf("  |%-20g|%-20g|\n",b,(b-32)/1.8);
}
