#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct elementtype
{

}elementtype;

typedef struct node node;
typedef struct node
{
  elementtype element;
  node *next;
  node *prev;
}node;

node *root,*cur,*last;

node *MakeNewNode(elementtype add)
{
  node *new;
  new=(node *)malloc(sizeof(node));
  new->element=add;
  new->next=NULL;
  new->prev=NULL;
  return new;
}

void insert_after(elementtype e)
{
  node *new=MakeNewNode(e);
  if(root==NULL)
    {
      root=new; last=new; cur=root;
    }
  else
    {
      new->next=cur->next;
      if(cur->next!=NULL)
        cur->next->prev=new;
      cur->next=new;
      new->prev=cur;
      cur=new;
    }
  if(new->next==NULL) last=new;
}

void insert_before(elementtype e)
{
  node *new=MakeNewNode(e);
  if(root==NULL)
    {
      root=new; last=new; cur=root;
    }
  else
    {
      new->prev=cur->prev;
      if(cur->prev!=NULL)
        cur->prev->next=new;
      cur->prev=new;
      new->next=cur;
      cur=new;
      if(new->prev==NULL) root=new;
    }
}

void insert_begin(elementtype e)
{
  node *new=MakeNewNode(e);
  if(root==NULL)
    {
      root=new; last=new; cur=root;
    }
  else
    {
      new->next=root;
      root->prev=new;
      root=new;
      cur=new;
    }
}

void insert_last(elementtype e)
{
  node *new=MakeNewNode(e);
  if(root==NULL)
    {
      root=new; last=new; cur=root;
    }
  else
    {
      last->next=new;
      new->prev=last;
      last=new;
      cur=new;
    }
}

void delete_current(node *del) //delete 1 node tai vi tri hien tai.
{
  if(del==root)
    {
      root->next->prev=NULL;
      root=root->next;
      free(del);
    }
  else if(del==last)
    {
      last->prev->next=NULL;
      last=last->prev;
      free(del);
    }
  else
    {
      del->prev->next=del->next;
      del->next->prev=del->prev;
      free(del);
    }
}

void delete_choose()
{
  int n=0,x,i;
  node *del;
  del=root;
  while(del!=NULL)
    {
      n++; del=del->next;
    }
  del=root;
  do
    {
        printf("Nhap vao vi tri node muon xoa(0,1,2,3...): ");
        scanf("%d",&x);
        if(x>n || x<0)
          {
            printf("Khong ton tai vi tri node nay.\n");
          }
        else
          {
            for(i=0;i<n;i++)
              {
                if(i==x)
                  {
                    delete_current(del);
                  }
                del=del->next;
              }
          }
    }while(x>n || x<0);
  printf("_Delete node(%d) completed!\n",x);
}

void delete_all()
{
  node *del;
  del=root;
  while(del!=NULL)
    {
      root=del->next;
      free(del);
      del=root;
    }
}

void print_data(elementtype res)
{
  //printf("%-20s%-10s%-10s%-10s\n",res.model,res.memory,res.size,res.price);
}

void display()
{
  node *tmp;
  tmp=root;
  if(root==NULL)
    {
      printf("_Data is empty!\n ");
    }
  while(tmp!=NULL)
    {
      PrintData(tmp->element);
      tmp=tmp->next;
    }
}
