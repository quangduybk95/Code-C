#include <stdio.h>
#include <stdlib.h>


typedef struct node node;
typedef struct node
{
  elementtype element;
  node* next;
}node;

typedef node* position;
typedef struct
{
  position front, rear;
}queue;

void MakeNull_queue(queue *q)
{
  position header;
  header=(node*)malloc(sizeof(node));
  header->next=NULL;
  q->front=header;
  q->rear=header;
}

int empty_queue(queue q)
{
  return(q.front==q.rear);
}

void Enqueue(elementtype e, queue *q)
{
  q->rear->next=(node*)malloc(sizeof(node));
  q->rear=q->rear->next;
  q->rear->element=e;
  q->rear->next=NULL;
}

void Dequeue(queue *q)
{
  if(!empty_queue(*q))
    {
      position tmp;
      tmp=q->front;
      q->front=q->front->next;
      free(tmp);
    }
  else printf("Error! Queue rong!\n");
}
