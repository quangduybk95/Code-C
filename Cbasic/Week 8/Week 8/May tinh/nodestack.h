#include<stdio.h>
#include<stdlib.h>
typedef struct node node;
typedef struct node {
  char data[20];
node *next;
}node;
node *push(node *p,int value)
{
  node *tmp;
  tmp=(node*)malloc(sizeof(node));
  tmp->data=value;
  tmp->next=p;
  p=tmp;
  return(p);
}
node *pop(node *p,int *value)
{
  node *tmp;
  *value=p->data;
  tmp=p;
  p=p->next;
  free(tmp);
  return(p);
}
