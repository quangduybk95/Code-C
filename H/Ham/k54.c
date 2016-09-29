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
void nhap(qt a[])
{
  int i;
  for(i=0;i<=4;i++)
    {
      printf("Nhap cau hoi so %d : ",i+1);gets(a[i].cauhoi);
      printf("Nhap phuong an 1 : ");gets(a[i].pa1);
      printf("Nhap phuong an 2 : ");gets(a[i].pa2);
      printf("Nhap phuong an 3 : ");gets(a[i].pa3);
      printf("Nhap dap an cau hoi so %d : ",i+1);scanf("%d%*c",&a[i].dapan);
    }
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
{ int i,x,y;qt tg;
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

     while(y==a[x-1].dapan)
        {
        printf("Ban nhap sai(trung voi dap an cu) ,moi ban nhap lai (1-3) : ");
        scanf("%d%*c",&y);}


}
void doi(char a[],char b[])
{

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
      }
  }
 while(ch!=5);

}
