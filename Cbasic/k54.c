#include<stdio.h>
#include<string.h>
typedef struct xx
{
  char cauhoi[128];
  char pa1[30];
  char pa2[30];
  char pa3[30];
  int dapan;
} qt;
void doixau(char a[],char b[])
{
  char  tg[100];int x,y,i;
  x=strlen(a);
  y=strlen(b);
   strcpy(tg,a);
  strcat(a,b);
  strcat(b,tg);
  for(i=0;i<=x+y-1;i++)
    { b[i]=b[i+y];
      a[i]=a[i+x];
    }
}

void nhap(qt a[])
{
      strcpy(a[0].cauhoi,"Vua bong da ten la");
      strcpy(a[0].pa1,"Pele");
      strcpy(a[0].pa2,"Maradona");
      strcpy(a[0].pa3,"Ronaldo");
      a[0].dapan=1;
      strcpy(a[1].cauhoi,"Tran chung ket CL 2010 to chuc tai san");
      strcpy(a[1].pa1,"My Dinh");
      strcpy(a[1].pa2,"Arena");
      strcpy(a[1].pa3,"Bernabeu");
      a[1].dapan=3;
       strcpy(a[2].cauhoi,"Doi tuyen chu nha worldcup 2010 la ");
      strcpy(a[2].pa1,"Anh");
      strcpy(a[2].pa2,"Nam Phi");
      strcpy(a[2].pa3,"Hy Lap");
      a[2].dapan=2;
       strcpy(a[3].cauhoi,"Luat ban thang vang tu nam nao");
      strcpy(a[3].pa1,"2000");
      strcpy(a[3].pa2,"1995");
      strcpy(a[3].pa3,"1996");
      a[3].dapan=3;
       strcpy(a[4].cauhoi,"Tuyen nao la xe tang");
      strcpy(a[4].pa1,"Nga");
      strcpy(a[4].pa2,"Duc");
      strcpy(a[4].pa3,"Phap");
      a[4].dapan=2;


}
void incauhoi(qt a[],int sohieu)
{ int i;
  for(i=0;i<=4;i++)
    if((i+1)==sohieu)
      {
        printf("Cau hoi : %-128s\n",a[i].cauhoi);
        printf("Dap an : \n");
        printf("1.%-30s\n",a[i].pa1);
        printf("2.%-30s\n",a[i].pa2);
        printf("3.%-30s\n",a[i].pa3);
      }
  }
void daodapan(qt a[])
{ int i,x,y;
  printf("Nhap so hieu cau hoi muon sua(1-5) : ");scanf("%d%*c",&x);
   while((x!=1)&&(x!=2)&&(x!=3)&&(x!=4)&&(x!=5))
 {
        printf("Ban nhap sai ,moi ban nhap lai (1-5) : ");
        scanf("%d%*c",&x);}
   printf("Nhap so hieu dap an moi (1-3) : ");scanf("%d%*c",&y);
     while((y!=1)&&(y!=2)&&(y!=3))
 {
        printf("Ban nhap sai ,moi ban nhap lai (1-3) : ");
        scanf("%d%*c",&y);}
     for(i=0;i<=2;i++)
     while(y==a[x-1].dapan)
        {
        printf("Ban nhap sai(trung voi dap an cu) ,moi ban nhap lai (1-3) : ");
        scanf("%d%*c",&y);}
     if((y==1)&&(a[x-1].dapan==2)) doixau(a[x-1].pa1,a[x-1].pa2);
     if((y==1)&&(a[x-1].dapan==3)) doixau(a[x-1].pa1,a[x-1].pa3);
     if((y==2)&&(a[x-1].dapan==1)) doixau(a[x-1].pa1,a[x-1].pa2);
     if((y==2)&&(a[x-1].dapan==3)) doixau(a[x-1].pa3,a[x-1].pa2);
     if((y==3)&&(a[x-1].dapan==1)) doixau(a[x-1].pa1,a[x-1].pa3);
     if((y==3)&&(a[x-1].dapan==2)) doixau(a[x-1].pa3,a[x-1].pa2);
     printf("Cau hoi : %-128s\n",a[x-1].cauhoi);
     printf("Dap an : \n");
     printf("1.%-30s\n",a[x-1].pa1);
     printf("2.%-30s\n",a[x-1].pa2);
     printf("3.%-30s\n",a[x-1].pa3);
}
void choi(qt a[])
{ char name[2][30];int i,j,d=0,k;
  int x[3];
  for(i=0;i<=2;i++)
    {
      printf("Nhap ten nguoi choi thu %d : ",i+1);gets(name[i]);
      printf("Chon so hieu 3 cau hoi dang x/x/x : ");scanf("%d%*c%d%*c%d%*c",&x[0],&x[1],&x[2]);
      printf("Bat dau choi \n");
      for(j=0;j<=2;j++)
        {
          printf("Cau %d : \n",j+1);
      incauhoi(a,x[j]);
      printf("Moi ban chon phuong an tra loi : ");scanf("%d%*c",&k);
           while((k!=1)&&(k!=2)&&(k!=3))
 {
        printf("Ban nhap sai ,moi ban nhap lai (1-3) : ");
        scanf("%d%*c",&k);}

      if(k==a[x[j]-1].dapan) {printf("ban da dung \n");d=d+1;} else printf("ban tra loi sai \n");
        }

      printf("\n");
      printf("Nguoi choi : %-30s - Tong diem : %d\n",name[i],d);d=0;
      printf("\n");
    }
}

main()
{
  int sh,ch;qt  a[100];
    do
  {
    printf("\t\tMenu\n");
    printf("1.Bam phim 1 de tao cau hoi \n");
    printf("2.Bam phim 2 de in cau hoi\n");
    printf("3.Bam phim 3 de dao ap an\n");
    printf("4.Bam phim 4 de thuc hien choi\n");
    printf("5.Bam phim 5 de ket thuc\n");
    printf("\n");
    printf("Nhap phim chuc nang (1-5) : ");scanf("%d%*c",&ch);
    while((ch!=1)&&(ch!=2)&&(ch!=3)&&(ch!=4)&&(ch!=5))
      {
        printf("Ban nhap sai ,moi ban nhap lai (1-5) : ");
        scanf("%d%*c",&ch);
      }
    switch(ch)
      {
      case 1 : nhap(a);break;
      case 2 : printf("Nhap so hieu cau hoi muon in : " );scanf("%d%*c",&sh);
            while((sh!=1)&&(sh!=2)&&(sh!=3)&&(sh!=4)&&(sh!=5))
 {
        printf("Ban nhap sai ,moi ban nhap lai (1-5) : ");
        scanf("%d%*c",&sh);
      }
            incauhoi(a,sh);break;
      case 3 : daodapan(a);break;
      case 4 : choi(a);break;
      case 5 : printf("ket thuc \n");break;
      }
  }
 while(ch!=5);

}
