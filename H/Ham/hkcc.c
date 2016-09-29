#include<stdio.h>
#include<string.h>
#define m 15
#define n 10
typedef struct x
{
  char hoten[30];
  char mau[10];
} info;
void vietHoaTen(char *s)
{
int i = 0;
while (s[i] != '\0')
{
if ((i == 0 || s[i-1] == ' ') && s[i] >= 'a' && s[i] <= 'z')
{
s[i] = s[i] + 'A' - 'a';
}
i++;
}
}
void choi(info a[],int b[])
{
  int i,j;
  int p;
  for(i=0;i<4;i++)
    {
      printf("Luot choi cua nguoi thu %d \n",i+1);
      printf("Ten nguoi choi(Day du ho ten, viet hoa dung chinh ta : ");
      gets(a[i].hoten);
      while(strstr(a[i].hoten," ")==NULL)
        {
          printf("Nhap lai ten (Day du ho ten, viet hoa dung chinh ta : ");
          gets(a[i].hoten);
        }
      /*     p=strlen(a[i].hoten);
       if((a[i].hoten[0]>='a')&&(a[i].hoten[0]<='z'))
         a[i].hoten[0]=a[i].hoten[0] +'A'-'a';
      for(j=1;j<p;j++)
        {
          if((a[i].hoten[j]=' ')&&(a[i].hoten[j+1]>='a')&&(a[i].hoten[j+1]<='z'))
            a[i].hoten[j+1]=a[i].hoten[j+1]+'A'-'a';
            }*/
      vietHoaTen(a[i].hoten);
      printf("Ten : %-30s \n",a[i].hoten);
    }
}
main()
{ char a[m][n];int i,j,ch,b[20];info x[4];
do
  {
    printf("\t\tMenu\n");
    printf("1.Bam phim 1 de tao ma tran\n");
    printf("2.Bam phim 2 de thay doi ma tran\n");
    printf("3.Bam phim 3 de choi\n");
    printf("4.Bam phim 4 de in ra nguoi co diem cao nhat thap nhat\n");
    printf("5.Bam phim 5 de thoat\n");
    printf("\n");
    printf("Nhap phim chuc nang (1-5) : ");scanf("%d%*c",&ch);
    while((ch!=1)&&(ch!=2)&&(ch!=3)&&(ch!=4)&&(ch!=5))
      {
        printf("Ban nhap sai ,moi ban nhap lai (1-5) : ");
        scanf("%d%*c",&ch);
      }
    switch(ch)
      {
      case 1 :   strcpy(a[0],"Xanh");
   strcpy(a[1],"Vang");
   strcpy(a[2],"Do");
    strcpy(a[5],"Xanh");
   strcpy(a[3],"Vang");
   strcpy(a[4],"Do");
    strcpy(a[7],"Xanh");
   strcpy(a[8],"Vang");
   strcpy(a[6],"Do");
    strcpy(a[9],"Xanh");
   strcpy(a[11],"Vang");
   strcpy(a[10],"Do");
    strcpy(a[14],"Xanh");
   strcpy(a[12],"Vang");
   strcpy(a[13],"Do");
   for(i=0;i<=14;i++)
     {
       printf("%-8s",a[i]);
       if(i%3==2) printf("\n");}
   break;
      case 2 : choi(x,b);
      }
  }
 while(ch!=5);

 }

