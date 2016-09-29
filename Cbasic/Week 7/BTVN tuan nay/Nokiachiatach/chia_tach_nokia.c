//Duong Quang Duy
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "thuvienlk2.h"

int kt_create=0; //kiem tra viec creat danh sach.
int create_new_list();
void chia(int n);
int tach(int n1, int n2);
void display1();
void display2();
void print_list_1();
void print_list_2();
int tach_output();
node *root2c,*last1c;
node *root2t,*last2t,*tg;
int N=26;
int main()
{
  int a,kt=1,n,n1,n2;
  do
    {
        printf("\n\t~MENU~\n");
        printf("1. Create new list.\n");
        printf("2. Display list.\n");
        printf("3. Chia thanh hai danh sach con.\n");
        printf("4. Tach thanh hai danh sach con.\n");
        printf("5. In danh sach 1.\n");
        printf("6. In danh sach 2.\n");
        printf("7. Thoat.\n");
        printf("Chon: "); scanf("%d%*c",&a);
        switch(a)
          {
          case 1:
            create_new_list();
            break;
          case 2:
            printf("%-20s%-10s%-10s%-10s\n","Model","Memory","Size","Price");
            display();
            break;
          case 3:
            do
              {
                printf("Nhap vi tri ban muon chia: ");
                scanf("%d%*c",&n);
                if(n<= 0 || n>=N)
                  printf("Khong the chia tu vi tri node(%d)\n",n);
              }while(n<=0|| n>=N);
            chia(n);
            break;
          case 4:
            do
              {
                printf("Nhap vi tri ban muon chia: ");
                scanf("%d%*c",&n1);
                printf("Nhap so nut ban muon chia: ");
                scanf("%d%*c",&n2);
                if(n1<= 0 || n1>=N)
                  printf("Khong the chia tu vi tri node(%d)!\n",n);
                if(n2>N-n1)
                  printf("Nhap lai so nut can chia!\n");
              }while(n1<=0|| n1>=N || n2>(N-n1));
            tach(n1,n2);
            break;
          case 5:
            printf("%-20s%-10s%-10s%-10s\n","Model","Memory","Size","Price");
            display1();
            break;
          case 6:
            printf("%-20s%-10s%-10s%-10s\n","Model","Memory","Size","Price");
            display2();
            break;
          case 7:
            kt=0; break;
          default:
            kt=0; break;
          }
    }while(kt);
}

int create_new_list()
{
  int i;
  FILE *fin;
  elementtype *p;
  fin=fopen("nokiadb.dat","rb");
  if(fin==NULL)
    {
      printf("Loi mo tep!\n"); return 1;
    }
  p=(elementtype *)malloc(sizeof(elementtype)*N);
  fread(p,sizeof(elementtype),N,fin);
  //Dua du lieu vao list.
  for(i=0;i<N;i++)
    {
      insert_after(p[i]);
    }
  printf("Create completed!\n");
  kt_create=1;
  fclose(fin);
}

void display1()
{
  node *tmp;
  tmp=root;
  if(root==NULL)
    {
      printf("_Data is empty!\n ");
    }
  while(tmp!=last1c)
    {
      print_data(tmp->element);
      tmp=tmp->next;
    }
  print_data(tmp->element);
}

void display2()
{
  node *tmp;
  tmp=root2c;
  if(root2c==NULL)
    {
      printf("_Data is empty!\n ");
    }
  while(tmp!=NULL)
    {
      print_data(tmp->element);
      tmp=tmp->next;
    }
}

void chia(int n)
{
  int i;
  node *tmp;
  tmp=root;
  for(i=0;i<n-2;i++)
    {
      tmp=tmp->next;
    }
  root2c=tmp->next;
  last1c=tmp;
  printf("Completed!\n");
}

int tach(int n1, int n2)
{
  if(kt_create==0)
    {
      printf("Ban hay tao lai list de co the tach danh sach.\n");
      return 1;
    }
  node *tmp; int i;
  tmp=root;
  for(i=0;i<n1-2;i++)
    {
      tmp=tmp->next;
    }
  root2t=tmp->next;
  tg=tmp;
  for(i=0;i<n2-1;i++)
    {
      tmp=tmp->next;
    }
  last2t=tmp->next;
  tg->next=last2t->next;
  printf("Completed!\n<View in output.txt>\n");
  tach_output();
  kt_create=0;
  root2t=NULL;
  last2t=NULL;
  root=NULL;
}

int tach_output()
{
  FILE *fout;
  fout=fopen("output.txt","w");
  if(fout==NULL)
    {
      printf("Loi mo tep!\n"); return 0;
    }
  node *tmp; elementtype res;
  fprintf(fout,"%s","_Danh sach duoc tach ra:\n");
  fprintf(fout,"%-20s%-10s%-10s%-10s\n","Model","Memory","Size","Price");
  tmp=root2t;
  while(tmp!=last2t)
    {
      fprintf(fout,"%-20s%-10s%-10s%-10s\n",tmp->element.model,tmp->element.memory,tmp->element.size,tmp->element.price);
      tmp=tmp->next;
    }
  fprintf(fout,"%-20s%-10s%-10s%-10s\n",tmp->element.model,tmp->element.memory,tmp->element.size,tmp->element.price);
  fprintf(fout,"%s","\n_Danh sach duoc con lai:\n");
  tmp=root;
  while(tmp!=NULL)
    {
      fprintf(fout,"%-20s%-10s%-10s%-10s\n",tmp->element.model,tmp->element.memory,tmp->element.size,tmp->element.price);
      tmp=tmp->next;
    }
}
