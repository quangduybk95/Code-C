#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
  int key;
} elementtype;

typedef struct node{
  elementtype element;
  struct node *next;
} queue;

typedef struct list {p
  queue *front;
  queue *rear;
} queueList; 

queueList *creat(queueList *qList) {
  (*qList).front=(*qList).rear=NULL;
  return qList;
}

queue *makeNode (elementtype e) {
  queue* tmp;
  tmp=(queue*)malloc(sizeof(queue));
  if (tmp != NULL) {
    tmp->element=e;
    tmp->next=NULL;
  }
  return tmp;  
}

elementtype readData () {
  elementtype e;
  printf("nhap so : "); scanf("%d",&e.key);
  return e;
}

queue *insertQueue (queueList *qList, elementtype e) {
  queue *tmp=makeNode(e);
  if (tmp == NULL) return NULL;
  if ((*qList).front == NULL) 
    (*qList).front=(*qList).rear=tmp;
  else {
    (*qList).rear->next=tmp;
    (*qList).rear=tmp;
  }
  return tmp;  
}

void outputData (elementtype e) {
  printf("%5d",e.key);
}

void travelling (queueList qList) {
  queue *tmp=qList.front;
  while (tmp != NULL) {
    outputData(tmp->element);
    tmp=tmp->next;
  }
  printf("\n");
}

int getQueue (queueList *qList, elementtype *e) {
  if ((*qList).front == NULL) return -1;
  queue *tmp=(*qList).front;
  (*qList).front=(*qList).front->next;
  tmp->next=NULL;
  *e=tmp->element;
  if ((*qList).front == NULL)
    (*qList).rear=NULL;
  free(tmp);
  return 1;
} 

void delete (queueList *qList) {
  (*qList).rear=NULL;
  while ((*qList).front != NULL) {
    queue *tmp=(*qList).front;
    (*qList).front=(*qList).front->next;
    tmp->next=NULL;
    free(tmp);
  } 
}




