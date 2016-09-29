#include<stdio.h>
typedef struct x
{
  char  id[6];
  char name[30];
  float grade;
  char class;
} student;
main()
{
  int n,i,j;student a[30],g;
  printf("Nhap so sinh vien : ");scanf("%d%*c",&n);
  while (n<=0) {printf("Ban nhap sai moi ban nhap lai n>0 : ");scanf("%d%*c",&n);}
  for(i=0;i<=n-1;i++)
    { printf("Nhap thong tin sinh vien thu %d : \n",i+1);
      printf("Nhap ten sinh vien : ");scanf("%[^\n]*c",&a[i].name);
      printf("Nhap so hieu sinh vien thu : ");scanf("%s%*c",a[i].id);
      printf("Nhap diem cua sinh vien : ");scanf("%f%*c",&a[i].grade);
      while ((a[i].grade<0)||(a[i].grade>10)) {printf("Ban nhap sai moi ban nhap lai (0-10) : ");scanf("%d%*c",&a[i].grade);}
 if (a[i].grade>=9) a[i].class='A'; else
        if (a[i].grade>=8) a[i].class='B';else
          if (a[i].grade>=6.5) a[i].class='C';else a[i].class='D';
}

   for(i=0;i<=n-1;i++)
    for(j=i+1;j<=n-1;j++)
      if (a[i].grade<=a[j].grade)
        {
          g=a[i];
          a[i]=a[j];
          a[j]=g;
        }

   printf("| ID | Name | Grade | Class |\n");

  for(i=0;i<=n-1;i++)
 printf("|%-4s|%-6s|%-7.2f|%-7c|\n",a[i].id,a[i].name,a[i].grade,a[i].class);
}
