#include<stdio.h>
#include<stdlib.h>
typedef struct
{
  char ten[81];
  char sdt[81];
  char email[81];
}elementtype;

typedef struct node node;
typedef struct node
{
  elementtype element;
  node* next;
  node* prev;
}node;

node *head;
node *tail;
node *head1;
node *tail1;
node *make_new_node(elementtype a)//tao nut moi
{
  node *new=(node*)malloc(sizeof(node));
  new->element=a;
  new->next=NULL;
  new->prev=NULL;
  return new;
}
void read_data(node *h)//doc du lieu
{ node *p=h;
  do
    {
  printf("-------------------------\n");
  printf("Ho va ten :%s\n",p->element.ten);
  printf("So dien thoai:%s\n",p->element.sdt);
  printf("Email:%s\n",p->element.email);
  p=p->next;
    }while(p!=NULL);
}
void inserttail(elementtype x)//chen cuoi danh sach
{
  node *new=make_new_node(x);
  if(head==NULL)
    {
      head=new;
      tail=new;
    }
  else
    {
      new->prev=tail;
      tail->next=new;
      tail=new;
    }
}
elementtype write_data()//nhap du lieu
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
void deltail()//xoa ptu cuoi
{
  node *p;
  if(tail!=NULL)
    {
      p=tail;
      tail=tail->prev;
      tail->next=NULL;
      free(p);
      if(head==NULL) tail=NULL;
      else {
        head->prev=NULL;
      }
    }
  }
void del(int i)//xoa ptu bat ki
{
  node *p=head;node *tmp;int j;
  for(j=0;j<i-1;j++)
    p=p->next;
  if(p!=NULL)
    {
      tmp=p;
      p->prev->next=p->next;
      p->next->prev=p->prev;
      free(tmp);
    }
    }
void delhead()//xoa ptu dau
{
  node *p;
  if(head!=NULL)
    {
      p=head;
      head=head->next;
      head->prev=NULL;
      free(p);
 }
}
void insert(elementtype x,int i)//chen vi tri bat ki
{ node *p=head;int j;
  node *new= make_new_node(x);
  //  if(i>=n) inserttail(x);
  //else
   if(head==NULL)
    {
      head=new;
      tail=new;
    }
    else
      {
        for(j=0;j<i;j++)
        new->prev=p;
        new->next=p->next;
        p->next=new;
}
}
void inserthead(elementtype x)//chen dau ds
{
  node* new= make_new_node(x);
  if(head==NULL)
    {
      head=new;
      tail=new;
    }
  else
    {
      new->next=head;
      head->prev=new;
      head=new;
    }
}
/*main()
{
  int i,n;
  printf("Nhap so ng : ");
  scanf("%d%*c",&n);
  for(i=0;i<n;i++)
    {
      printf("Nhap thong tin nguoi thu %d \n",i+1);
      inserttail(write_data());
    }
  del(2);
  insert(write_data(),3);

  read_data(head);
  // insert(write_data(),2);
  // read_data();
  }
