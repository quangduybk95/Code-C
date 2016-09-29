#include<stdio.h>
#include<stdlib.h>
struct node {
  int data;
  struct node *lk;
};
struct node *push(struct node *p,int value)
{
  struct node *tmp;
  tmp=(struct node*)malloc(sizeof(struct node));
  if(tmp==NULL)
    {
      printf("Error\n");
      exit(0);
    }
  tmp->data=value;
  tmp->lk=p;
  p=tmp;
  return(p);
}
struct node *pop(struct node *p,int *value)
{
  struct node *tmp;
  *value=p->data;
  tmp=p;
  p=p->lk;
  free(tmp);
  return(p);
}
