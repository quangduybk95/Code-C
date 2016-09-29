#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct one_element {
  int key;
} elementtype;

typedef struct one_node {
  elementtype element;
  struct one_node *next;
  struct one_node *prev;
} node;

typedef struct one_list {
  node *head;
  node *tail;
} nodeList;

nodeList *initialize (nodeList *list) {
  (*list).head=NULL;
  (*list).tail=NULL;
  return list;
}

node *makeNode (elementtype e) {
  node *tmp;
  tmp=(node*)malloc(sizeof(node));
  if (tmp != NULL) {
    tmp->element=e;
    tmp->next=NULL;
    tmp->prev=NULL;
  }
  return tmp;
}

elementtype readData () {
  elementtype e;
  printf("nhap so : "); scanf("%d",&e.key);
  return e;
}

node *insertFirst (nodeList *list, elementtype e) {
  node *tmp=makeNode(e);
  if (tmp == NULL) return NULL;
  if ((*list).head == NULL) 
    (*list).head=(*list).tail=tmp;
  else {
    tmp->next=(*list).head;
    (*list).head->prev=tmp;
    (*list).head=tmp;
  }
  return tmp;
}

node *insertLast (nodeList *list, elementtype e) {
  node *tmp=makeNode(e);
  if (tmp == NULL) return NULL;
  if ((*list).tail == NULL) 
    (*list).head=(*list).tail=tmp;
  else {
    (*list).tail->next=tmp;
    tmp->prev=(*list).tail;
    (*list).tail=tmp;
  }
  return tmp;
}

node *insertMid (nodeList *list, elementtype e, node *cur) {
  node *tmp=makeNode(e);
  if (tmp == NULL) return NULL;
  if (cur->next == NULL) {
    cur->next=tmp;
    tmp->prev=cur;
    (*list).tail=tmp;
  }
  else {
    tmp->next=cur->next;
    cur->next->prev=tmp;
    cur->next=tmp;
    tmp->prev=cur;
  }
  return tmp;
}

void outputData (elementtype e) {
  printf("%5d",e.key);
}

void travelling (nodeList list) {
  node *tmp=list.head;
  while (tmp != NULL) {
    outputData(tmp->element);
    tmp=tmp->next;
  }
  printf("\n");
}

node *searching (nodeList list, int seaKey) {
  node *tmp=list.head;
  while (tmp != NULL) {
    if (tmp->element.key == seaKey) 
      break;
    tmp=tmp->next;
  }
  return tmp;
}

int deleteNode (nodeList *list, int delKey) {
  node *tmp=searching(*list,delKey);
  if (tmp == NULL) return -1;
  if (tmp->next == NULL && tmp->prev == NULL) 
    (*list).head=(*list).tail=NULL;
  else {
    if (tmp->prev == NULL) {
      (*list).head=(*list).head->next;
      (*list).head->prev=NULL;
    }
    else {
      if (tmp->next == NULL) {
	(*list).tail=(*list).tail->prev;
	(*list).tail->next=NULL;
      }
      else {
	tmp->prev->next=tmp->next;
	tmp->next->prev=tmp->prev;
      }
    }
  }
  tmp->next=tmp->prev=NULL;
  free(tmp);
  return 1;
}

void delete (nodeList *list) {
  node *tmp=(*list).head;
  while (tmp != NULL) {
    (*list).head=(*list).head->next;
    tmp->next=NULL;
    if ((*list).head != NULL) 
      (*list).head->prev=NULL;
    free(tmp);
    tmp=(*list).head;
  }
}

nodeList *create (nodeList *list, int n) {
  initialize (list);
  int i;
  for (i=0;i<n;i++) {
    if (insertLast(list,readData()) == NULL) {
      delete(list);
      break ;
    }
  }
  return list;
}

main() {
  nodeList list;

  create(&list,5);
  travelling(list);

  insertFirst(&list,readData());
  travelling(list);

  int seaKey;
  printf("nhap phan tu can tim: "); scanf("%d",&seaKey);
  insertMid(&list,readData(),searching(list,seaKey));
  travelling(list);

  int delKey;
  printf("nhap phan tu muon xoa : "); scanf("%d",&delKey);
  deleteNode(&list,delKey);
  travelling(list);

  delete(&list);
}
