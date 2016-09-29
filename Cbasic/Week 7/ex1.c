#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
  char ten[30];
  char sdt[20];
  char email[30];
}elementtype;

typedef struct node node;
typedef struct node
{
  elementtype element;
  node* next;
  node* prev;
}node;
node *root=NULL;
node *cur=NULL;
node *tail;
/*void Insert_List(elementtype x,position p,doubluelist *dl)
{
  if(*dl==NULL)
    {
      (*dl)=(node*)malloc(sizeof(node));
      (*dl)->element=x;
      (*dl)->prev=NULL;
      (*dl)->next=NULL;
    }
  else
    {
      position tmp;
      tmp=(node*)malloc(sizeof(node));
      tmp->element=x;
      tmp->next=p;
      tmp->prev=p->prev;
      if(p->prev!=NULL)
        p->prev->next=tmp;
      p->prev=tmp;
    }
    }*/
node *make_new_node(elementtype a)//tao nut moi
{
  node *new=(node*)malloc(sizeof(node));
  new->element=a;
  new->next=NULL;
  return new;
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
      new->prev=cur;
      cur=cur->next;
    }
}

elementtype write_data()//viet du lieu
{
  elementtype a;
  printf("Vui long nhap vao ten:");
  gets(a.ten);
  printf("Vui long nhap vao sdt:");
  gets(a.sdt);
  printf("Vui long nhap vao email:");
  gets(a.email);
  return a;
}

void read_data()//doc du lieu
{ cur=root;
  do
    {
  printf("-------------------------\n");
  printf("Ho va ten :%s\n",cur->element.ten);
  printf("So dien thoai:%s\n",cur->element.sdt);
  printf("Email:%s\n",cur->element.email);
  cur=cur->next;
    }while(cur!=NULL);
}
void insert_beginning(elementtype a)
//chen vao vi tri dau tien cua danh sach
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
      new->prev=NULL;
      root=new;
    }
}
main()
{
  int n,i;
  printf("Nhap so ptu ban muon tao : ");
  scanf("%d",&n);
   while(getchar()!='\n');
   for(i=0;i<n;i++)
     {
       insert_after(write_data());
     }
}
