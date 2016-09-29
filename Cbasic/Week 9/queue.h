#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct x
{
  char name[20];
  char sdt[15];
  char mail[15];
}eltype;
typedef struct node
{
  eltype element[MAX];
  int front,rear;
}queue;
void makenull_queue(queue *q)
{
  q->front=-1;
  q->rear=-1;
}
int empty_queue(queue q)
{
  return q.front==-1;
}
int full_queue(queue q)
{
  return (q.rear-q.front+1)==MAX;
}
void enqueue(eltype x,queue *q)
{
  if(!full_queue(*q))
    {
      if(empty_queue(*q)) q->front=0;
      q->rear=q->rear+1;
      q->element[q->rear]=x;
    }
  else printf("Queue tran\n");
}
void dequeue(queue *q)
{
  if(!empty_queue(*q))
    {
      q->front=q->front+1;
      if(q->front>q->rear)
        makenull_queue(q);
    }
  else printf("Queue rong\n");
}
