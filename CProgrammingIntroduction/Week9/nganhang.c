#include<stdio.h>
main()
{ int i,n;float lai,sodu,tisuat,tiengui;char tk[30];i=1;
  printf("Nhap ten tai khoan ngan hang : ");gets(tk);
  printf("Nhap ti suat lai hang thang(%%) : ");scanf("%f",&tisuat);
  printf("Nhap so tien ban muon gui(VND) : ");scanf("%f",&tiengui);
  printf("Nhap so thang muon xem bao cao : ");scanf("%d",&n);
  printf("\tBao cao thong tin tai khoan qua %d thang vua qua \n",n);
  printf("\n");
  printf("Ten tai khoan ngan hang : %-30s \n",tk);
  printf("____________________________________________________________\n");
  printf("|Thang \t Tien dau ki(VND) \t tien lai(VND) \t so du(VND) \t \n");
do {lai=tiengui*tisuat/100; sodu=tiengui+lai;
  printf("|%d \t %.2f \t\t %.2f \t %.2f  \n",i,tiengui,lai,sodu); tiengui=sodu;i=i+1;}
  while (i<=n);
  printf("|___________________________________________________________ \n");
}
