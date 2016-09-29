#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct stacknode stacknode;
typedef struct stacknode
{
  s_elementtype element;
  stacknode *next;
}stacknode;

typedef struct stack
{
  stacknode *top;
}stack;

//stack *s;
void make_new_stack(stack *a)
{
  a=(stack*)malloc(sizeof(stack));
  if(a==NULL)
    {
      printf("Khong khoi tao duoc stack.\n");
      return;
    }
  a->top=NULL;
}
stacknode *make_new_stacknode(s_elementtype a)
{
  stacknode *new=(stacknode*)malloc(sizeof(stacknode));
  if(new==NULL)
    {
      printf("Khoi tao that bai.\n");
      return;
    }
  else
    {
      new->element=a;
      new->next=NULL;
      return new;
    }
}
void push(stack *a,s_elementtype b)
{
  stacknode *new=make_new_stacknode(b);
  if(a->top==NULL)
    {
      a->top=new;
    }
  else
    {
      new->next=a->top;
      a->top=new;
    }
}
void read_data(s_elementtype a)
{
printf("%s\n",a.biethieu);
}
void read_data_all(stack *a)
{
  stacknode *b;
  b=a->top;
  while(b!=NULL)
    {
      read_data(b->element);
      a->top=b->next;
      b=a->top;
    }
}
s_elementtype pop(stack *a)
{
  stacknode *b;
  s_elementtype c;
  if(a->top==NULL)
    {
      printf("ngan xep trong.\n");
      return c;
    }
  else
    {
      b=a->top;
      c=b->element;
      a->top=b->next;
      free(b);
      return c;
    }
}
s_elementtype pop2(stack *a)//lay ra gia tri,ko xoa khoi stack
{
  stacknode *b;
  s_elementtype c;
  if(a->top==NULL)
    {
      printf("ngan xep trong.\n");
      return c;
    }
  else
    {
      b=a->top;
      return b->element;
    }
}
int size(stack *a)
{
  int i;
  stacknode *b;
  if(a->top==NULL) return 0;
  b=a->top;
  i=1;
  while(b->next!=NULL)
    {
      b=b->next;
      i++;
    }
  return i;
}

int kiem_tra(stack *s)//tra ve 0 neu rong
{
  if(s->top==NULL) return 0;
  else return 1;
}

void huy(stack *a)
{
  while(kiem_tra(a)!=0)
    {
      pop(a);
    }
}
