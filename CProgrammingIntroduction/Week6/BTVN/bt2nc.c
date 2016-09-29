#include<stdio.h>
#include<math.h>
main()
{
  int x1,y1,x2,y2;float d;
  printf("Nhap hoanh do cua ban : ");scanf("%d",&x1);
  printf("Nhap tung do cua ban : ");scanf("%d",&y1);
   printf("Nhap hoanh do diem can den : ");scanf("%d",&x2);
   printf("Nhap tung do diem can den : ");scanf("%d",&y2);
  d = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
  printf("Khoang cach cua ban den diem do la : %.2f\n",d);
  if (x1>0 && y1>0) printf("ban o goc dong bac cua ban do\n");else
  if (x1>0 && y1<0) printf("ban o goc dong nam cua ban do\n");else
  if (x1<0 && y1>0) printf("ban o goc tay bac cua ban do\n");else
  if (x1<0 && y1<0) printf("ban o goc tay nam cua ban do\n");else
  if (x1==0 && y1>0) printf("ban o goc dong cua ban do\n");else
  if (x1==0 && y1<0) printf("ban o goc nam cua ban do\n");else
  if (x1>0 && y1==0) printf("ban o goc dong cua ban do\n");else
  if (x1<0 && y1==0) printf("ban o goc tay cua ban do\n");else
  if (x1==0 && y1==0) printf("Ban o tam ban do");



        }
