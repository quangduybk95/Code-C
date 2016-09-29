#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct elementtype
{

}elementtype;

typedef struct node node;
typedef struct node
{
  elementtype element;
  node *next;
}node;
node *root,*cur,*prev;

node *MakeNewNode(elementtype add)
{
  node *new;
  new=(node *)malloc(sizeof(node));
  new->element=add;
  new->next=NULL;
  return new;
}

elementtype read_data()
{
  elementtype res;
  /*printf("Nhap name: ");
  scanf("%[^\n]%*c",res.name);
  printf("Nhap so dien thoai : ");
  scanf("%[^\n]%*c",res.name);
  printf("Nhap email sinh vien : ");
  scanf("%[^\n]%*c",res.name);
  */
  return res;
}

void InsertAfter(elementtype e)
{
  node *new=MakeNewNode(e);
  if(root==NULL)
    {
      root=new; cur=root;
    }
  else
    {
      new->next=cur->next;
      cur->next=new;
      prev=cur;
      cur=new;
    }
}

void insertBefore(elementtype e)
{
  node *new=MakeNewNode(e);
  if(root==NULL)
    {
      root=new; cur=root;
    }
  else
    {
      new->next=cur;
      if(prev!=NULL)
        prev->next=new;
      if(cur==root)
        {root=new;}
      cur=new;
    }
}

void insertBegin(elementtype e)
{
  node *new=MakeNewNode(e);
  if(root==NULL)
    {
      root=new; cur=root;
    }
  else
    {
      new->next=root;
      root=new;
      cur=root;
    }
}

void insert_choose(elementtype e,int i)
{
  int j;
  node *new=MakeNewNode(e);
  if(root==NULL)
    {
      root=new; cur=root;
    }
  else
    {
      cur=root;
      if(i==1 || i==0)
        {
          new->next=root;
          root=new; cur=root;
        }
      else
        {
          for(j=1;j<i;j++)
            {
              prev=cur; cur=cur->next;
              if(cur->next==NULL && j!=i)
                {
                  printf("Vi tri nam ngoai danh sach.\nTu dong chen vao cuoi.\n");
                  insertAfter(e);
                }
              else
                if(j==i-1)
                  {
                    new->next=prev->next;
                    prev->next=new;
                  }
            }
        }
    }
}

void deleteroot()
{
  node *del;
  if(root==NULL)
    {
      printf("Danh sach khong co phan tu nao de xoa.\n");
    }
  else
    {
      del=root;
      root=del->next;
      cur=del->next;
      free(del);
    }
}

void deletelast()
{
  node *del;
  cur=root;
  while(cur->next!=NULL)
    {
      prev=cur;
      cur=cur->next;
    }
  del=cur;
  cur=prev;
  prev->next=NULL;
  free(del);
}

void deleteall()
{
  node *del;
  while(root!=NULL)
    {
      del=root;
      root=del->next;
      free(del);
      root=NULL;
    }
}

void PrintData(elementtype res)
{
  //printf("%-30s%-15s%-30s\n",res.name,res.tel,res.email);
}

void duyet()
{
  node *temp;
  temp=root;
  while(temp!=NULL)
    {
      PrintData(temp->element);
      temp=temp->next;
    }
}

void FindNode(char *s)
{
  /*node *temp; char *str;
  temp=root;
  if(root==NULL)
    printf("Khong co du lieu.\n");
  else
    {

      while(temp!=NULL)
        {
          if(str=strstr(temp->element.tel,s)!=NULL)
            printf("Da tim duoc sinh vien %s.\nSDT: %-15s\tEmail: %-30s\n----------------------\n",temp->element.name,temp->element.tel,temp->element.email);
          temp=temp->next;
        }
    }
  */
}
