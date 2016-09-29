#include<stdio.h>
#include<stdlib.h>
#include"linklist.h"
#include<string.h>
#define MAX 100
node *p;
void menu5()
{ int k=0,x;
  printf("Nhap gia ma ban can tim : ");
  scanf("%d%*c",&x);
  printf("Danh sach dien thoai gia < gia ban nhap la : \n");
   cur=root;
    while(cur!=NULL)
      {
        if ((atof(cur->element.gia))<=x)
          {  printf("-------------------------\n");
             printf("Model : %s\n",cur->element.model);
             printf("Dung luong : %s\n",cur->element.dungluong);
             printf("kich thuoc : %s\n",cur->element.kichthuoc);
             printf("Gia : %s\n",cur->element.gia);
             k=1;
          }
  cur=cur->next;
      }
    if(k==0) printf("khong co model can tim \n");
}
void menu1()
{
  FILE *f;
  f=fopen("nokiadb.dat","rb");
  elementtype *a;
  a=(elementtype*)malloc(sizeof(elementtype));
  while(fread(a,sizeof(elementtype),1,f)!=0)
    {
      insert_after(a[0]);
    }
  printf("Thanh cong\n");
  fclose(f);
}
void menu3()
{ int k=0;char m[100];
    printf("Moi ban nhap ten model can tim : ");
    gets(m);
    cur=root;
    while(cur!=NULL)
      {
        if (strstr(cur->element.model,m)!=NULL)
          {  printf("-------------------------\n");
             printf("Model : %s\n",cur->element.model);
             printf("Dung luong : %s\n",cur->element.dungluong);
             printf("kich thuoc : %s\n",cur->element.kichthuoc);
             printf("Gia : %s\n",cur->element.gia);
             k=1;
          }
  cur=cur->next;
      }
    if(k==0) printf("khong co model can tim \n");
  }
void menu4()
{ int i,j;char lc;char m[100];
  printf("Nhap vao vi tri ban muon tim kiem : ");
  scanf("%d%*c",&i);
  cur=root;
  for(j=0;j<i;j++)
    cur=cur->next;
  printf("Thong tin :\n");
  printf("-------------------------\n");
  printf("Model : %s\n",cur->element.model);
  printf("Dung luong : %s\n",cur->element.dungluong);
  printf("kich thuoc : %s\n",cur->element.kichthuoc);
  printf("Gia : %s\n",cur->element.gia);
  do
    { printf("\nMENU\n");
      printf("1. Thay doi ten model \n");
      printf("2. Thay doi dung luong\n");
      printf("3. Thay doi kich thuoc\n");
      printf("4. Thay doi gia\n");
      printf("5. Ket thuc\n");
      printf("Moi ban nhap lc :(1-5) ");
      lc= getchar();
      while(getchar()!='\n');
      switch(lc)
        {
        case '1' :
          printf("Nhap ten model muon thay doi : ");
          gets(m);
          strcpy(cur->element.model,m);
          printf("\nThanh cong \n");
          printf("Thong tin :\n");
  printf("-------------------------\n");
  printf("Model : %s\n",cur->element.model);
  printf("Dung luong : %s\n",cur->element.dungluong);
  printf("kich thuoc : %s\n",cur->element.kichthuoc);
  printf("Gia : %s\n",cur->element.gia);break;
   case '4' :
          printf("Nhap gia muon thay doi : ");
          gets(m);
          strcpy(cur->element.gia,m);
          printf("\nThanh cong \n");
          printf("Thong tin :\n");
  printf("-------------------------\n");
  printf("Model : %s\n",cur->element.model);
  printf("Dung luong : %s\n",cur->element.dungluong);
  printf("kich thuoc : %s\n",cur->element.kichthuoc);
  printf("Gia : %s\n",cur->element.gia);break;
   case '2' :
          printf("Nhap ten dung luong muon thay doi : ");
          gets(m);
          strcpy(cur->element.dungluong,m);
          printf("\nThanh cong \n");
          printf("Thong tin :\n");
  printf("-------------------------\n");
  printf("Model : %s\n",cur->element.model);
  printf("Dung luong : %s\n",cur->element.dungluong);
  printf("kich thuoc : %s\n",cur->element.kichthuoc);
  printf("Gia : %s\n",cur->element.gia);break;
   case '3' :
          printf("Nhap kich thuoc muon thay doi : ");
          gets(m);
          strcpy(cur->element.kichthuoc,m);
          printf("\nThanh cong \n");
          printf("Thong tin :\n");
  printf("-------------------------\n");
  printf("Model : %s\n",cur->element.model);
  printf("Dung luong : %s\n",cur->element.dungluong);
  printf("kich thuoc : %s\n",cur->element.kichthuoc);
  printf("Gia : %s\n",cur->element.gia);
  break;
        case '5' : printf("EXIT\n");break;
        }
    }
  while(lc!='5');
}
/*void menu6()
{
  char m[100];int i=0;int j;
  printf("Nhap cum tu co trong ten model ban muon xoa : ");
  gets(m);
  cur=root;p=root;
  while(cur!=NULL)
    {
      if(strstr(cur->element.model,m)!=NULL)
        {
          for(j=0;j<i-1;j++)
            p=p->next;
              node *tmp=p->next;
              p->next=tmp->next;
              free(tmp);
        }
      cur=cur->next;
      i++;
    }
  printf("\nThanh cong :)\n");
  }*/
main()
{ char lc;
  do
    {
      printf("\nMENU\t\t\n");
      printf("1.Import from dat\n");
      printf("2.Display all\n");
      printf("3.Find by model\n");
      printf("4.Upadte info for a model\n");
      printf("5.Find by cost\n");
      printf("6.Exit\n");
  printf("Nhap lua chon cua ban(1-6) : ");
  lc=getchar();
  while(getchar()!='\n');
  switch(lc)
    {
    case '1' : menu1();break;
    case '2' : read_data(root);break;
    case '3' : menu3();break;
    case '4' : menu4();break;
    case '5' : menu5();break;
      //     case '6' : menu6();break;
    case '7' : printf("EXIT\n");break;
    default  : printf("Ban nhap sai, hay nhap lai (1-6)\n");
    }
    }
  while(lc!='7');
}
