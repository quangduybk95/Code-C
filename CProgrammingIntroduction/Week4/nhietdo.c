#include<stdio.h>
main()
{
  float c,f;
  int a;
  printf("Nhan 1 de doi tu do C sang do F, nhan 2 de doi tu do F sang do C:");
  scanf("%d",&a);
  if(a!=1&&a!=2)
    printf("Khong hop le. Moi ban nhap lai:\n");
  else
  if (a=1)
         {
           printf("Nhap nhiet do C can doi: ");
          scanf("%f",&c);
          f=c*1.8+32;
           printf("Nhiet do F tuong ung la: %-4.2f\n",f);
         }
  if (a=2)
    {
      printf("Moi nhap nhiet do F can doi: ");
      scanf("%f",&f);
      c=f*5.0/9.0-160.0/9.0;
      printf("Nhiet do C tuong ung la: %-4.2f\n",c);
    }
}
