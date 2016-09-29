#include<stdio.h>
#include<string.h>
#include<stdlib.h>



typedef struct node{
  elementtype element;
  struct node *next;
} stack;

typedef struct list {
  stack *top;
} stackList; 

stackList *initialize (stackList *sList) {
  (*sList).top=NULL;
  return sList;
}

stack *makeNode (elementtype e) {
  stack* tmp;
  tmp=(stack*)malloc(sizeof(stack));
  if (tmp != NULL) {
    tmp->element=e;
    tmp->next=NULL;
  }
  return tmp;  
}

elementtype readData (char c) {
  elementtype e;
  e.key=c;
  return e;
}

stack *push (stackList *sList, elementtype e) {
  stack *tmp=makeNode(e);
  if (tmp == NULL) return NULL;
  tmp->next=(*sList).top;
  (*sList).top=tmp;
  return tmp;
}

void outputData (elementtype e) {
  printf("%c",e.key);
}

void travelling (stackList sList) {
  stack *tmp=sList.top;
  while (tmp != NULL) {
    outputData(tmp->element);
    tmp=tmp->next;
  }
  printf("\n");
}

int pop (stackList *sList, elementtype *e) {
  if ((*sList).top == NULL) return -1;
  stack *tmp=(*sList).top; 
  (*sList).top=(*sList).top->next;
  tmp->next=NULL;
  *e=tmp->element;
  free(tmp);
  return 1;
}

void delete (stackList *sList) {
  while ((*sList).top != NULL) {
    stack *tmp=(*sList).top;
    (*sList).top=(*sList).top->next;
    tmp->next=NULL;
    free(tmp);
  }
}

