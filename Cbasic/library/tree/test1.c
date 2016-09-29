#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
  char user[30];
  char pass[10];
  float diem;
}elementtype;
#include"treebst.h"
treetype t;
void docfile()
{
  FILE *f;char buff[81];
  if((f=fopen("sinhvien.txt","r"))==NULL)
    printf("Khong tim thay file\n");
  int n=0,i;
  while(fgets(buff,81,f)!=NULL)
    n++;
  rewind(f);
  make_null_tree(&t);
  for(i=0;i<n;i++)
    {
      elementtype tmp;
      fscanf(f,"%s\t%s\t%f\t",tmp.user,tmp.pass,&tmp.diem);
      insert(&t,tmp);
    }
  fclose(f);
  print_LNR(t);
  //  printf("Success\n");
}
main()
{
  int lc,lc1;elementtype tmp;treetype tmp1;
  int kt=0,sl=0;char mk1[10],mk2[10];
  do
    {
      printf("###################\n");
      printf("MENU\n");
      printf("1.Dang nhap\n");
      printf("2.Thoat\n");
      printf("\n");
      printf("Moi ban nhap lua chon : ");
      scanf("%d%*c",&lc);
      switch(lc)
        {
        case 1 :
          {
          docfile();
          /*  while(kt==0&&sl<=3)
            {
          printf("Moi ban nhap username : ");
          gets(tmp.user);
          if(search1(tmp.user,t)==NULL)
            {
            printf("Nhap sai username\n");
            sl++;
            break;
            }
          printf("Moi ban nhap password(>6 ki tu) : ");
          gets(tmp.pass);
           if(search2(tmp.pass)==NULL)
            {
            printf("Nhap sai password\n");
            sl++;
            break;
            }
            }*/
         printf("Moi ban nhap username : ");
          gets(tmp.user);
           printf("Moi ban nhap password(>6 ki tu) : ");
          gets(tmp.pass);
          if(strcmp(tmp.user,"Admin")!=0)
            {
               do
    {
      printf("###################\n");
      printf("Chao ban \n");
      printf("1.Xem diem sinh vien do\n");
      printf("2.Thay doi mat khau\n");
      printf("3.Ghi lai thong tin ra file va thoat\n");
      printf("\n");
      printf("Moi ban nhap lua chon : ");
      scanf("%d%*c",&lc1);
      switch(lc1)
        {
        case 1 :
          tmp1=search(tmp,t);
          printf("Diem cua ban la : %f\n",tmp1->element.diem);
          break;
        case 2 :
          do{
          printf("Nhap mat khau moi lan 1: ");
          gets(mk1);
          printf("Nhap mat khau moi lan 2: ");
          gets(mk2);
          if(strcmp(mk1,mk2)!=0) printf("Ban nhap sai , hay nhap lai \n");
          }
          while(strcmp(mk1,mk2)!=0);
          doimk(mk1,tmp,t);
          print_LNR(t);
          break;
        case 3 : printf("Thoat\n");break;
        }
    }
  while(lc1!=3);
            }
          }
        case 2 : printf("Thoat\n");freetree(t);break;
        default : printf("Ban nhap sai yeu cau nhap lai \n");break;
        }

    }
  while(lc!=2);
}
