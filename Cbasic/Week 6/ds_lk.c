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
}node;

node *cur;
node *root;
node *pre;
node *make_new_node(elementtype a)//tao nut moi
{
  node *new=(node*)malloc(sizeof(node));
  new->element=a;
  new->next=NULL;
  return new;
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
  j=0;
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

    }while(j<i-1&&cur->next!=NULL);
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
      root=new;
    }
}

void delete_beginning(void)//xoa o vi tri dau
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
      if(cur->next!=NULL)
        {
          pre=cur;
          cur=cur->next;
        }
    }while(cur->next!=NULL);
  a=cur;
  cur=pre;
  free(a);
    }
}

void delete_choose(int i)
//Xoa phan tu o vi tri duoc chi dinh san.
{
  node *a;
  int j;
  j=0;
  if(root==NULL)
    {
      printf("Danh sach ko co phan tu de xoa .\n");
    }
  else
    {
  cur=root;
  while(j<i-1&&(cur->next!=NULL))
    {
           j++;
           pre=cur;
           cur=cur->next;
    }

  if(cur->next!=NULL)
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
  j=0;
  if(root==NULL)
    {
      printf("Danh sach ko co phan tu nao.\n");
    }
  else
    {
  cur=root;
  while(j<i-1&&(cur->next!=NULL))
    {
           j++;
           cur=cur->next;
    }

  if(cur->next!=NULL)
    {
      a=cur;
      printf("Du lieu cua phan tu nay la:\n");
      printf("%s\n",a->element.ten);
      printf("%s\n",a->element.sdt);
      printf("%s\n",a->element.email);
    }
  else
    {
      printf("Vi tri ban can tim nam ngoai danh sach.\n");
    }
    }
}

int main()
{
  int i;
  /*
    read_data(make_new_node(write_data()));
    //Doc ghi mot nut rieng le.
  */

  for(i=1;i<=3;i++)
    {
      insert_before(write_data());//chen truoc.
      //insert_after(write_data());//chen sau.
    }
    read_data();

    /*
    //chen mot phan tu vao 1 vi tri bat ky
    printf("Nhap vao vi tri ban muon chen vao:");
    scanf("%d",&i);
    while(getchar()!='\n');
    insert_choose(write_data(),i);
    read_data();
    */

    /*
    //chen phan tu vao dau danh sach
    printf("Vui long nhap vao pt can chen vao dau danh sach:\n");
    insert_beginning(write_data());
    read_data();
    */
    /*
    //Xoa phan tu dau tien cua danh sach
    delete_beginning();
    printf("Danh sach sau khi xoa phan tu dau tien la:\n");
    read_data();
    */

    /*
      //Xoa phan tu cuoi cung cua danh sach
    delete_beginning();
    printf("Danh sach sau khi xoa phan tu cuoi cung la:\n");
    read_data();
    */

    /*
    //Xoa o vi tri chi dinh truoc
    printf("Nhap vao vi tri ban muon xoa:");
    scanf("%d",&i);
    while(getchar()!='\n');
    delete_choose(i);
    printf("Danh sach sau khi xoa la:\n");
    read_data();
    */

    //tim kiem
    printf("Nhap vao vi tri ban muon tim kiem:");
    scanf("%d",&i);
    while(getchar()!='\n');
    search(i);


}
