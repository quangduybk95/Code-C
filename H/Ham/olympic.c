#include<stdio.h>
#include<string.h>
typedef struct xx
{
  char hoten[30];
  int diem[5];
} ketqua;
void dk(ketqua a[],int n)
{
  int i;
  for(i=0;i<n;i++)
    {
      printf("Nhap day du ho ten vdv thu %d : ",i+1);gets(a[i].hoten);
      while(strstr(a[i].hoten," ")==NULL)
        {
          printf("ban phai nhap day du ho ten : ");gets(a[i].hoten);
          }
    }
        printf("%-5s%-30s\n","STT","Ho ten");
      for(i=0;i<=n-1;i++)
        printf("%-5d%-30s\n",i+1,a[i].hoten);

}
void thidau(ketqua a[],int n)
{ int i,j=0,k;
  for(i=0;i<=4;i++)
    {  printf("Bat dau luot ban thu %d \n",i+1);
      for(k=0;k<=n-1;k++)
        {
          printf("Nhap diem cua vdv thu %d (0-10) : ",k+1);
          scanf("%d%*c",&a[k].diem[j]);
          while((a[i].diem[j]<0)||(a[i].diem[j]>10))
            {
              printf("Diem tu 0-10 : ");scanf("%d%*c",&a[i].diem[j]);
}}
      j++;
    }
  printf("Danh sach ket qua : \n");
  printf("%-30s%-5s%-5s%-5s%-5s%-5s\n","Ho ten","L1","L2","L3","L4","L5");
  for(i=0;i<=n-1;i++) {printf("%-30s",a[i].hoten);
    for(j=0;j<=4;j++) printf("%-5d",a[i].diem[j]);
    printf("\n");}
}
void xephang(ketqua a[],int n)
{
  int b[10],i,j,tg;ketqua c;
  for(i=0;i<=n-1;i++) b[i]=0;
  for(i=0;i<=n-1;i++)
    {
      for(j=0;j<=4;j++)
        b[i]=b[i]+a[i].diem[j];
    }
  for(i=0;i<n;i++)
    for(j=i+1;j<n;j++)
      {
        if (b[i]<=b[j])
          { tg=b[i];
            b[i]=b[j];
            b[j]=tg;
            c=a[i];
            a[i]=a[j];
            a[j]=c;
          }
      }
  printf("In danh sach trao giai  \n");
  printf("%-30s%-15s%-10s\n","Ho ten","Huy chuong","Tong diem");
  printf("%-30s%-15s%-10d\n",a[0].hoten,"Gold",b[0]);
  printf("%-30s%-15s%-10d\n",a[1].hoten,"Silver",b[1]);
  printf("%-30s%-15s%-10d\n",a[2].hoten,"Bronze",b[2]);

}
void sieu(ketqua a[],int n)
{ int i,j=0,k=0;
  printf("Danh sach sieu xa thu : \n");
  printf("%-30s\n","Ho ten");
  for(i=0;i<=n-1;i++)
    {
      if(((a[i].diem[0]==10)&&(a[i].diem[1]==10)&&(a[i].diem[2]==10))||((a[i].diem[1]==10)&&(a[i].diem[2]==10)&&(a[i].diem[3]==10))||((a[i].diem[2]==10)&&(a[i].diem[3]==10)&&(a[i].diem[4]==10))||((a[i].diem[3]==10)&&(a[i].diem[4]==10)&&(a[i].diem[5]==10)))
        {k=1;  printf("%-30s\n",a[i].hoten);}}
  if (k!=1) printf("K co \n");
}

main()
{  int n,ch;ketqua a[10];
do
  {
    printf("\t\tMenu\n");
    printf("1.Bam phim 1 de dang ki van dong vien\n");
    printf("2.Bam phim 2 de bat dau thi dau\n");
    printf("3.Bam phim 3 de xep hang\n");
    printf("4.Bam phim 4 de xem danh sach sieu xa thu\n");
    printf("5.Bam phim 5 de thoat chuong trinh\n");
    printf("\n");
    printf("Nhap phim chuc nang (1-5) : ");scanf("%d%*c",&ch);
    while((ch!=1)&&(ch!=2)&&(ch!=3)&&(ch!=4)&&(ch!=5))
      {
        printf("Ban nhap sai ,moi ban nhap lai (1-5) : ");
        scanf("%d%*c",&ch);
      }
    switch(ch)
      {
      case 1 : printf("Nhap so vdv (1-10): ");scanf("%d%*c",&n);
        while((n<=0)||(n>10))
{
  printf("Ban nhap so vdv (1-10) : ");scanf("%d%*c",&n);
 }
        dk(a,n);break;
      case 2 : thidau(a,n);break;
      case 3 : xephang(a,n);break;
      case 4 : sieu(a,n);break;
      case 5 : printf("Ket thuc\n");break;
      }
  }
 while(ch!=5);


}
