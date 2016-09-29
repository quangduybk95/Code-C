#include<stdio.h>
typedef struct infonhanvat
{char ten[30];
  float sucmanh,nhanhnhen,mau,satthuong,phongthu,mau1;} info;
  info  nhapthongtin(info nv);
  info nhapthongtin(info nv)
  { 
  printf("Nhap ten nhan vat : ");scanf("%[^\n]*c",&nv.ten);
  printf("Nhap chi so suc manh cua nhan vat (10-20) : ");scanf("%f",&nv.sucmanh);
  while ((nv.sucmanh<10)||(nv.sucmanh>20)) {printf("Ban nhap sai moi ban nhap lai chi so suc manh (10-20) : ");scanf("%f",&nv.sucmanh);} 
  printf("Nhap chi so mau (50-100) : ");scanf("%f",&nv.mau);
while ((nv.mau<50)||(nv.mau>100)) {printf("Ban nhap sai moi ban nhap lai chi so mau (50-100) : ");scanf("%f",&nv.mau);} 
  printf("Nhap chi so nhanh nhen (>0) : ");scanf("%f%*c",&nv.nhanhnhen);
while (nv.nhanhnhen<0) {printf("Ban nhap sai moi ban nhap lai chi so nhanh nhen (>0) : ");scanf("%f%*c",&nv.nhanhnhen);}
 nv.satthuong=nv.sucmanh*1.2; 
 nv.phongthu=nv.sucmanh*0.8;
 nv.mau1=nv.mau;
 return nv;
}
int turn(info x1,info x2)
{ srand(time(NULL));int ran;
  ran=1+ rand()%2;
  if (x1.nhanhnhen>x2.nhanhnhen) {printf("Nguoi choi %s danh truoc\n",x1.ten);return 1;}else 
    if (x1.nhanhnhen<x2.nhanhnhen) {printf("Nguoi choi %s danh truoc\n",x2.ten);return 2;}
    else {if (ran==1) {printf("2 nguoi nhanh nhen = nhau , Ngau nhien chon nguoi choi %s danh truoc \n",x1.ten);return 1;}else   
	{printf("2 nguoi nhanh nhen = nhau , Ngau nhien chon nguoi choi %s danh truoc \n",x2.ten);return 2;}
    }}
void solo(info x1,info x2)
{ srand(time(NULL));int ran;int t;float a;
  ran=1+ rand()%2;
   t=turn(x1,x2);
   do { if (t==1) {x2.mau=x2.mau-(x1.satthuong-x2.phongthu);x1.mau=x1.mau-(x2.satthuong-x1.phongthu);}
     else  {x1.mau=x1.mau-(x2.satthuong-x1.phongthu);x2.mau=x2.mau-(x1.satthuong-x2.phongthu);}
if (ran==1) a=0.01;else a=0.02;
       if ((x1.mau>0)&&(x2.mau<=0)) 
	 {printf("Nguoi choi %s thang cuoc \n",x1.ten);break;}
       if ((x1.mau<=0)&&(x2.mau>0)) 
	 {printf("Nguoi choi %s thang cuoc \n",x2.ten);break;}
    }
 while ((x1.mau>0)&&(x2.mau>0)); 
if (ran==1) a=0.01;else a=0.02;
       if ((x1.mau>0)&&(x2.mau<=0)) 
	 {x1.sucmanh=x1.sucmanh*(1.02+a);x1.satthuong=x1.satthuong*(1.02+a);x1.phongthu=x1.phongthu*(1.02+a);x1.mau1=x1.mau1*(1.02+a);x1.nhanhnhen=x1.nhanhnhen*(1.02+a);x2.sucmanh=x2.sucmanh*(1.01+a);x2.satthuong=x2.satthuong*(1.01+a);x2.phongthu=x2.phongthu*(1.01+a);x2.mau1=x2.mau1*(1.01+a);x2.nhanhnhen=x2.nhanhnhen*(1.01+a);}
       if ((x1.mau<=0)&&(x2.mau>0)) 
	 {x2.sucmanh=x2.sucmanh*(1.02+a);x2.satthuong=x2.satthuong*(1.02+a);x2.phongthu=x2.phongthu*(1.02+a);x2.mau1=x2.mau1*(1.02+a);x2.nhanhnhen=x2.nhanhnhen*(1.02+a);x1.sucmanh=x1.sucmanh*(1.01+a);x1.satthuong=x1.satthuong*(1.01+a);x1.phongthu=x1.phongthu*(1.01+a);x1.mau1=x1.mau1*(1.01+a);x1.nhanhnhen=x1.nhanhnhen*(1.01+a);}
   if (ran==1) printf("Moi nguoi choi dc thuong ngau nhien 1%% kinh nghiem \n");else printf("Moi nguoi choi dc thuong ngau nhien 2%% kinh nghiem \n");
   printf("\t\tChi so sau cuoc dau la : \n");
   printf("|Nguoi choi| Suc manh | Mau  | Nhanh nhen |\n");
   printf("|%-10s|%-10.3f|%-6.3f|%-12.3f|\n",x1.ten,x1.sucmanh,x1.mau1,x1.nhanhnhen);
   printf("|%-10s|%-10.3f|%-6.3f|%-12.3f|\n",x2.ten,x2.sucmanh,x2.mau1,x2.nhanhnhen);

}

main()
{ info nv1,nv2,nv3;int n,i;
 /* printf("\t\tSO LUOC TRO CHOI : \n");
  printf("\tChi so sat thuong = 120%% chi so suc manh \n");
  printf("\tChi so phong thu = 80%% chi so suc manh");
  printf("\tChi so nhanh nhen cao hon duoc danh truoc \n");
  printf("\tMoi luot danh so mau nguoi choi bi mat = sat thuong cua doi thu tru di phong thu cua minh \n");
  printf("\tAi het mau truoc nguoi do thua \n");
  printf("\n");*/
  printf("Nhap thong tin nhan vat 1 : \n");
  nv1=nhapthongtin(nv1);printf("\n");
printf("Nhap thong tin nhan vat 2 : \n");
  nv2=nhapthongtin(nv2);printf("\n");
printf("Nhap thong tin nhan vat 3 : \n");
  nv3=nhapthongtin(nv3);printf("\n");
  printf("Nhap so vong dau : ");scanf("%d",&n);
  for(i=1;i<=n;i++)
    {
      solo(nv1,nv2);
      solo(nv2,nv3);
      solo(nv3,nv1);
    }
  /*  printf("\t\tChi so cuoi cung sau cuoc dau la : \n");
   printf("|Nguoi choi| Suc manh | Mau  | Nhanh nhen |\n");
   printf("|%-10s|%-10.3f|%-6.3f|%-12.3f|\n",nv1.ten,nv1.sucmanh,nv1.mau1,nv1.nhanhnhen);
   printf("|%-10s|%-10.3f|%-6.3f|%-12.3f|\n",nv2.ten,nv2.sucmanh,nv2.mau1,nv2.nhanhnhen);
   printf("|%-10s|%-10.3f|%-6.3f|%-12.3f|\n",nv3.ten,nv3.sucmanh,nv3.mau1,nv3.nhanhnhen);*/
}
