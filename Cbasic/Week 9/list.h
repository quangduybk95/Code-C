#include<stdio.h>
#include<stdlib.h>
typedef struct s
{
  char name[20];
  char sdt[15];
  char mail[15];
}eltype;
typedef struct node node;
typedef struct node
{
  eltype element;
  node *next;
}node;
typedef struct x
{
  node *head;
  node *tail;
}queue;
void makenullqueue(queue *q)
{
  node *header;
  header->next==NULL;
  q->head=header;
  q->tail=header;
}
int emptyqueue(queue q)
{
  return (q.head==q.tail);
}
void enqueue(eltype x,queue *q)
{
  q->tail->next=(node*)malloc(sizeof(node));
  q->tail=q->tail->next;
  q->tail->element=x;
  q->tail->next=NULL;
}
void dequeue(queue *q)
{
  if(!emptyqueue(*q))
    { node *t;
  t=q->head;
  q->head=q->head->next;
  free(t);}
  else printf("rong\n");
}
