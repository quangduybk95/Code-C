#include<stdio.h>
#include<stdlib.h>
#include"linklist.h"
#include<string.h>
int size=0;
void export(node *x,char tenfile[])
{
  FILE *f;
  f=fopen(tenfile,"w+a");
  cur=x;
  while(cur!=NULL)
    {
      fprintf(f,"-------------------------\n");
      fprintf(f,"Model : %s\n",cur->element.model);
      fprintf(f,"Dung luong : %s\n",cur->element.dungluong);
      fprintf(f,"kich thuoc : %s\n",cur->element.kichthuoc);
      fprintf(f,"Gia : %s\n",cur->element.gia);
      cur=cur->next;
    }
}
void menu1()
{
  FILE *f1,*f2;int i;
  f1=fopen("nokiadb.txt","r");
  elementtype a,b[100];
  f2=fopen("nokiadb.dat","w+b");
for(i=0;i<size;i++)
  {
    fscanf(f1,"%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t",a.model,a.dungluong,a.kichthuoc,a.gia);
    insert_after(a);
    b[i]=a;
   }
 fwrite(b,sizeof(elementtype),size,f2);
printf("\nThanh cong :) \n");
fclose(f1);
 fclose(f2);
}
//menu2
/*void menu2()

{ int i;
  while(root!=NULL)
    {
      node *a;
      a=root;
      root=root->next;
      free(a);
    }
  FILE *f;elementtype *b;
  b=(elementtype*)malloc(sizeof(elementtype));
  f=fopen("nokiadb.dat","r");
  for(i=0;i>size;i++)
    {fread(b,sizeof(elementtype),1,f);
      insert_after(b[0]);
    }
  fclose(f);
  printf("\nThanh cong \n");
  }*/
void menu4(char m[])
  { int k=0;
    printf("Moi ban nhap ten model can tim : ");
    gets(m);
    cur=root;
    while(cur!=NULL)
      {
        if (strcmp(m,cur->element.model)==0)
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
void menu5(int x)
{ int k=0;
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
void menu6(int n)
{ int i;char tenfile1[100],tenfile2[100];
  printf("Nhap so ptu ma ban muon tach(n<tongsopt) ");
  scanf("%d%*c",&n);
  while(n>=size)
    {
        printf("Nhap lai so ptu ma ban muon tach(n<tongsopt) ");
        scanf("%d%*c",&n);
    }
  cur=root;root1=NULL;root2=NULL;
  for(i=0;i<n;i++)
    {
      cur=cur->next;
    }
  root2=cur;
  printf("Nhap ten file 1 : ");gets(tenfile1);
  export(root,tenfile1);
   printf("Nhap ten file 2 : ");gets(tenfile2);
  export(root2,tenfile2);
  /*  printf("Danh sach 1 : \n");
  printf("\n\n");
  read_data(root1);
   printf("Danh sach 2 : \n");
   printf("\n\n");
   read_data(root2);*/
}
main()
{ char lc;char c[100];
  char buff[81];FILE *f1;int x,n;
  do
    {
      printf("\nMENU\t\t\n");
      printf("1.Import from text\n");
      printf("2.Import from dat\n");
      printf("3.Display all\n");
      printf("4.Find by model\n");
      printf("5.Find by cost\n");
      printf("6.Tach danh sach  \n");
      printf("7. CHen them 1 model vao vi tri tuy chon\n");
      printf("8.Exit\n");
  printf("Nhap lua chon cua ban(1-7) : ");
  lc=getchar();
  while(getchar()!='\n');
  /* while(lc!='1'&&lc!='2'&&lc!='3'&&lc!='4'&&lc!='5'&&lc!='6'&&lc!='7')
    {
      printf("Nhap lai lua chon cua ban(1-7) : ");
      lc=getchar();
      while(getchar()!='\n');
      }*/
  f1=fopen("nokiadb.txt","r");
    while((fgets(buff,81,f1))!=NULL)
  {
    size++;
  }
    fclose(f1);
  switch(lc)
    {
    case '1' : menu1(); break;
      // case '2' : menu2();break;
    case '3' : read_data(root);break;
    case '4' : menu4(c);break;
    case '5' : menu5(x);break;
    case '6' : menu6(n);break;
    case '8' : printf("Exit \n");break;
    case '7' : printf("vi tri can chen : ");scanf("%d%*c",&n);insert_choose(write_data(),n);break;
    default  : printf("Ban nhap sai yeu cau(1-7), hay nhap lai. ");break;
    }

    }  while(lc!='8');
}
