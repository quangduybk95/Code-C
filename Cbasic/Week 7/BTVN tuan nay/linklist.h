#include<stdio.h>
#include<stdlib.h>
typedef struct
{
  char model[20];
  char dungluong[15];
  char kichthuoc[15];
  char gia[15];
}elementtype;

typedef struct node node;
typedef struct node
{
  elementtype element;
  node* next;
}node;

node *cur;
node *root;node* root1;node *root2;
node *pre;
node *make_new_node(elementtype a)//tao nut moi
{
  node *new=(node*)malloc(sizeof(node));
  new->element=a;
  new->next=NULL;
  return new;
}

elementtype write_data()
{
  elementtype a;
  printf("Nhap model : ");gets(a.model);
  printf("Nhap dung luong : ");gets(a.dungluong);
  printf("Nhap kich thuoc : ");gets(a.kichthuoc);
  printf("Nhap gia : ");gets(a.gia);
  return a;
}
void read_data(node *x)//doc du lieu
{ cur=x;
  do
    {
  printf("-------------------------\n");
  printf("Model : %s\n",cur->element.model);
  printf("Dung luong : %s\n",cur->element.dungluong);
  printf("kich thuoc : %s\n",cur->element.kichthuoc);
  printf("Gia : %s\n",cur->element.gia);
  cur=cur->next;
    }while(cur!=NULL);
}
void insert_after(elementtype a)//chen sau
{
  node *new=make_new_node(a);
  if(root==NULL)
    {
      root=new;
      cur=new;
    }
  else
    {
      new->next=cur->next;
      cur->next=new;
      cur=cur->next;
    }
}

void insert_before(elementtype a)//chen truoc
{
  node *new=make_new_node(a);
  if(root==NULL)
    {
      root=new;
      cur=new;
    }
  else
    {
      new->next=root;
      root=new;
      cur=root;
    }
}

void insert_choose(elementtype a,int i)
//insert vao vi tri i tuy chon
{
  int j;
  j=-1;
   node *new=make_new_node(a);
  if(root==NULL)
    {
      root=new;
      cur=new;
    }
  else
    {
  cur=root;
  do
    {
      j++;
      if(cur->next!=NULL)
        {
           pre=cur;
           cur=cur->next;
        }

    }while(j<i-2&&cur->next!=NULL);
  if(cur->next!=NULL)
    {
  new->next=pre->next;
  pre->next=new;
    }
  else
    {
      printf("Vi tri ban can chen nam ngoai danh sach.\n");
      printf("Chuong trinh se dua no ve vi tri cuoi cung.\n");
      insert_after(a);
      }
    }
}
void insert_beginning(node *x,elementtype a)
//chen vao vi tri dau tien cua danh sach
{
  node *new=make_new_node(a);
  if(x==NULL)
    {
      x=new;
      cur=new;
    }
  else
    {
      new->next=x;
      x=new;
    }
}

void insert_last(node *x,elementtype a)
{
  node *new=make_new_node(a);
  if(x==NULL)
    {
      x=new;
      cur=new;
    }
  else
    {
      cur=x;
  do
    {
      if(cur->next!=NULL)
        {
          pre=cur;
          cur=cur->next;
        }
    }while(cur->next!=NULL);
    }
  cur->next=new;
  cur=cur->next;
}

void delete_beginning()//xoa o vi tri dau
{
  if(root==NULL)
    {
      printf("danh sach khong co phan tu de xoa.\n");
    }
  else
    {
  node *a;
  a=root;
  root=root->next;
  free(a);
    }
}

void delete_last(void)//xoa o vi tri cuoi
{
  node *a;
  if(root==NULL)
    {
      printf("danh sach khong co phan tu de xoa.\n");
    }
  else
    {
      cur=root;
  do
    {
          pre=cur;
          cur=cur->next;
    }while(cur->next!=NULL);
  a=cur;
  cur=pre;
  pre->next=NULL;
  free(a);
    }
}

void delete_choose(int i)
//Xoa phan tu o vi tri duoc chi dinh san.
{
  node *a;
  int j;
  j=-1;
  if(root==NULL)
    {
      printf("Danh sach ko co phan tu de xoa .\n");
    }
  else
    {
  cur=root;
  while(j<i-2)
    {
           j++;
           pre=cur;
           cur=cur->next;
           if(cur==NULL)
             break;
    }

  if(cur!=NULL)
    {
      a=cur;
      pre->next=cur->next;
      cur=cur->next;
      free(a);
    }
  else
    {
      printf("Vi tri ban can xoa nam ngoai danh sach.\n");
    }
    }

}

void search(int i)//tim kiem
{
  node *a;
  int j;
  j=-1;
  if(root==NULL)
    {
      printf("Danh sach ko co phan tu nao.\n");
    }
  else
    {
  cur=root;
  while(j<i-2)
    {
           j++;
           cur=cur->next;
    }

  if(cur!=NULL)
    {
      a=cur;
      printf("Du lieu cua phan tu nay la:\n");
      printf("%s\n",a->element.model);
      printf("%s\n",a->element.kichthuoc);
      printf("%s\n",a->element.dungluong);
      printf("%s\n",a->element.gia);
    }
  else
    {
      printf("Vi tri ban can tim nam ngoai danh sach.\n");
    }
    }
}
