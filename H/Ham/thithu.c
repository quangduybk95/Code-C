#include<stdio.h>
#include<string.h>
typedef struct xx
{
  char name[25];
  int suggest[4];

} result;

void nhap(result a[],int n,int m)
{
  int i;
  for(i=0;i<=m-1;i++)
    {
      printf("Nhap ten nguoi choi thu %d (Phai day du ho ten) : ",i+1);
      gets(a[i].name);
      while(strstr(a[i].name," ")==NULL)
      {
        printf("Ban nhap sai, Nhap ten nguoi choi thu %d (Phai day du ho ten): ",i+1);
        gets(a[i].name);
      }

    }
    printf("%-5s%-25s\n","STT","Name");
  for(i=0;i<=m-1;i++)
    printf("%-5d%-25s\n",i+1,a[i].name);
}
void doanso(result a[],int n,int m)
{
  int i,j;
  for(i=0;i<=m-1;i++)
    {
      printf("Luot choi cua nguoi choi thu %d : \n",i+1);
      for(j=0;j<=3;j++)
        {
          printf("Moi ban doan luot %d : ",j+1);scanf("%d%*c",&a[i].suggest[j]);
          if(a[i].suggest[j]==n) {printf("Ban doan dung : \n");break;}
      else     if(a[i].suggest[j]>n) printf("Ban can doan so nho hon : \n");
             else     if(a[i].suggest[j]<n) printf("Ban can doan so lon hon : \n");
        }
    }
  printf("%-25s%-4s%-4s%-4s%-4s\n","Name","L1","L2","L3","L4");

  for(i=0;i<=m-1;i++){
  printf("%-25s",a[i].name);
      for(j=0;j<=3;j++)
        { if(a[i].suggest[j]>0)
           if (a[i].suggest[j]==n)
                                {
                                  printf("%-4d",a[i].suggest[j]);
                                  break;
                                } else  printf("%-4d",a[i].suggest[j]);
          else printf("    ");}
      printf("\n");


    }
}
main()
{ int ch,n,m,i;result a[6];
  do
  {
    printf("\t\tMenu\n");
    printf("1.Bam phim 1 khoi tao tro choi \n");
    printf("2.Bam phim 2 de choi doan so\n");
    printf("3.Bam phim 3 de tong hop ket qua\n");
    printf("4.Bam phim 4 de ket thuc tro choi\n");
    printf("\n");
    printf("Nhap phim chuc nang (1-4) : ");scanf("%d%*c",&ch);
    while((ch!=1)&&(ch!=2)&&(ch!=3)&&(ch!=4))
      {
        printf("Ban nhap sai ,moi ban nhap lai (1-5) : ");
        scanf("%d%*c",&ch);
      }
    switch(ch)
      {
      case 1 : printf("Nhap so can doan : ");scanf("%d%*c",&n);
        printf("Nhap so nguoi choi : ");scanf("%d%*c",&m);
        nhap(a,n,m);   break;
      case 2 : doanso(a,n,m);break;

      }
  }
 while(ch!=5);
}
