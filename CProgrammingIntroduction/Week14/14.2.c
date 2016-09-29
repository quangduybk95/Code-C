#include<stdio.h>
#define sothang 2
typedef struct thoitiet
{
  int t,maxc,minc,ctb;
} thang;
main()
{ thang dulieu;
  float n=sothang,i,ttb=0,maxctb=0,minctb=0,ctbtb=0;float k=-40,t=50;
  for(i=1;i<=n;i++)
    {
      printf("Moi ban nhap du lieu thang %d : \n",i);
      printf("Nhap tong luong mua : ");scanf("%d",&dulieu.t);
      ttb=ttb+dulieu.t;
      printf("Nhap nhiet do cao nhat : ");scanf("%d",&dulieu.maxc);
     /* while ((dulieu.maxc<-40)||(dulieu.maxc>50)) {
        printf("Ban nhap sai , moi nhap lai (-40->50)");scanf("%d",&dulieu.maxc);}
      }*/
      if (dulieu.maxc>=k) k=dulieu.maxc;
      printf("Nhap nhiet do thap nhat : ");scanf("%d",&dulieu.minc);
     /*  while ((dulieu.minc<-40)||(dulieu.minc>50)) {
         printf("Ban nhap sai , moi nhap lai (-40->50)");scanf("%d",&dulieu.minc);}*/
      if (dulieu.minc<=t) t=dulieu.maxc;
      printf("Nhap nhiet do trung binh : ");scanf("%d",&dulieu.ctb);
      /* while ((dulieu.ctb<-40)||(dulieu.ctb>50)) {
         printf("Ban nhap sai , moi nhap lai (-40->50)");scanf("%d",&dulieu.ctb);}*/
}
  printf("Bang ket qua du lieu thoi tiet trung binh trong nam : \n");
  printf("| Tong luong mua tb| nhiet do max | nhiet do min | Tong luong mua |\n");
  printf("|%-14.2f(mm)|%-8.2f(do C)|%-8.2f(do C)|%-12.2f(mm)|\n",ttb/n,k,t,ttb);
}
