#include<stdio.h>
#include<string.h>
typedef struct x
{
  char  id[6];
  char name[30];
  float grade;
  char class;
} student;
void nhap(){
  int n,i,j;student a[30],g;
  printf("Nhap so sinh vien : ");scanf("%d%*c",&n);
  while (n<=0) {printf("Ban nhap sai moi ban nhap lai n>0 : ");scanf("%d%*c",&n);}
  for(i=0;i<=n-1;i++)
    { printf("Nhap thong tin sinh vien thu %d : \n",i+1);
      printf("Nhap ten sinh vien : ");scanf("%[^\n]*c",&a[i].name);
      printf("Nhap so hieu sinh vien thu : ");scanf("%s%*c",a[i].id);
      printf("Nhap diem cua sinh vien : ");scanf("%f%*c",&a[i].grade);
