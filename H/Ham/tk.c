#include<stdio.h>
#include<string.h>
#define MAX 10
typedef struct xx
{
  char matkhau[25];
  char ten[80];
} taikhoan;
void doixau(char a[],char b[])
{ char tg[100];int x,y,i;
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
void nhap(taikhoan a[])
{
      strcpy(a[0].ten,"quangduy1");
      strcpy(a[0].matkhau,"100895");
      strcpy(a[1].ten,"quangduy2");
      strcpy(a[1].matkhau,"123456");
      strcpy(a[2].ten,"quangduy3");
      strcpy(a[2].matkhau,"081995");
}
int dangnhap(taikhoan a[],char ten[],char matkhau[],int j)
{
  int i=0,k=0;
  do{
    if((strcmp(a[i].ten,ten)==0)&&(strcmp(a[i].matkhau,matkhau)==0))
      {k=1;j=i;return 1;break;}
    i++;
  } while(i<=MAX);
  if(k!=1) return 0;
}
void menu_admin(taikhoan a[],int x)
{ int ch,i,m=0,t=3,j;taikhoan b;char k[80];
do
  {
    printf("\t\tMenu\n");
    printf("1.Bam phim 1 de them nguoi su dung \n");
    printf("2.Bam phim 2 de xoa nguoi su dung \n");
    printf("3.Bam phim 3 de in danh sach nguoi su dung\n");
    printf("4.Bam phim 4 de thoat\n");
    printf("\n");
    printf("Nhap phim chuc nang (1-4) : ");scanf("%d%*c",&ch);
    while((ch!=1)&&(ch!=2)&&(ch!=3)&&(ch!=4))
      {
        printf("Ban nhap sai ,moi ban nhap lai (1-4) : ");
        scanf("%d%*c",&ch);
      }
    switch(ch)
      {
      case 1 :
        printf("Nhap ten muon them : ");gets(b.ten);
        printf("Nhap mat khau  : ");gets(b.matkhau);
        a[x]=b;x++;t++;break;
      case 2 :
        printf("Nhap ten muon xoa : ");gets(k);
        for(i=0;i<=t-1;i++)
          if(strcmp(a[i].ten,k)==0)
            {for(j=i;j<=t-1;j++)
                { a[j]=a[j+1];m=1;}}
        if(m!=1) printf("khong co ten \n");break;
      case 3 :
        printf("Danh sach \n");
        printf("%-30s%-25s\n","Ten","Mat khau");
    for(i=0;i<=t-1;i++)
         printf("%-30s%-25s\n",a[i].ten,a[i].matkhau);
    printf("\n");
         break;
      case 4 : printf("Ket thuc\n");break;
      }}
 while(ch!=4);
  }
void menu_user(taikhoan a[],int j)
{ char x[25];int ch;
  do
  {
    printf("\t\tMenu\n");
    printf("1.Bam phim 1 de doi mat khau \n");
    printf("2.Bam phim 2 de thoat ct\n");
    printf("\n");
    printf("Nhap phim chuc nang (1-2) : ");scanf("%d%*c",&ch);
    while((ch!=1)&&(ch!=2))      {
        printf("Ban nhap sai ,moi ban nhap lai (1-2) : ");
        scanf("%d%*c",&ch);
      }
    switch(ch)
      {
      case 1 : printf("Nhap mat khau moi  ");gets(x);
        doixau(a[j].matkhau,x);
        printf("Doi mat khau thanh cong \n");
        break;
      case 2 : printf("ket thuc \n");break;
      }
  }
 while(ch!=2);
}


main()
{
  taikhoan a[MAX];char tk[80],mk[25];int k,t=0,j=0,m,h=3;
  nhap(a);
  do{
    printf("XIN CHAO \n");
    printf("Bam 1 de dang nhap  \n");
    printf("Bam 2 de thoat \n");
    printf("Nhap chuc nang : ");scanf("%d%*c",&m);
     while((m!=1)&&(m!=2))
       {
        printf("Ban nhap sai ,moi ban nhap lai (1-2) : ");
        scanf("%d%*c",&m);
      }
    switch(m)
      {
      case 1 :  do{ printf("Moi ban nhap ten muon dang nhap : ");gets(tk);
                    printf("Moi ban nhap mat khau : ");gets(mk);
                    k=dangnhap(a,tk,mk,j);printf("j=%d\n",j);
      if(k==1) printf("Ban dang nhap thanh cong\n");
      else
        {printf("Ban dang nhap that bai ,hay dang nhap lai \n");t++;}
        }

        while((t<3)&&(k!=1));printf("j= %d\n",j);
        if(j==0) menu_admin(a,h);else menu_user(a,j);
        break;
      case 2 : {printf("Ket thuc \n");break;}
      }
  }
    while(m!=2);
}
