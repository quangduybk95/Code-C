#include<stdio.h>
#include<stdlib.h>
#define MAX 50
typedef struct x
{
  char model[20];
  char dungluong[10];
  char kichthuoc[10];
  char giatien[10];
}info;
//menu 1
void menu1(info *a,int size)
{ int i;size=0;char buff[81];
  a=(info*)malloc(MAX*sizeof(info));
  FILE *f1,*f2;
  if((f1=fopen("nokiadb.txt","r"))==NULL)
    {
      printf("khong the mo file nokiadb.txt\n");
    }
  while(fgets(buff,81,f1)!=NULL)
    {
      size++;
    }
  printf("%d\n",size);
  fseek(f1,0,SEEK_SET);
  for(i=0;i<size;i++)
    {
      fscanf(f1,"%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t",a[i].model,a[i].dungluong,a[i].kichthuoc,a[i].giatien);
    }
   f2=fopen("nokiadb.dat","w+b");
   fwrite(a,sizeof(info),size,f2);
   printf("thanh cong\n");
   fclose(f2);
   fclose(f1);
}
//menu3
void menu3(int size)
{ FILE *f;info *a;int i,num;
  a=(info*)malloc(size*sizeof(info));
  f=fopen("nokiadb.dat","rb");

   printf("%-20s%-15s%-15s%-15s\n","Model","Dung luong","Kich thuoc","Gia tien");
   fread(a,sizeof(info),size,f);
     for(i=0;i<size;i++)
    {
      printf("%-20s%-15s%-15s%-15s\n",a[i].model,a[i].dungluong,a[i].kichthuoc,a[i].giatien);
    }

  fclose(f);
}
main()
{ char lc;int size;
  info *list;
  do
    {
      printf("\n\t\tMENU\n");
      printf("1.Import DB from text\n");
      printf("2.Import from DB\n");
      printf("3.In\n");
      printf("4.Tim kiem theo model\n");
      printf("5.Exit\n");

  printf("Nhap lua chon (1-5) : ");
  lc=getchar();
  while(getchar()!='\n');
  while(lc!='1'&&lc!='2'&&lc!='3'&&lc!='4'&&lc!='5')
    {
      printf("Nhap lai lua chon (1-5) : ");
      lc=getchar();
      while(getchar()!='\n');
    }
  switch(lc)
    {
    case '1' : menu1(list,size);break;
     case '3' : menu3(size);break;
    }
}
  while(lc!='5');
}
