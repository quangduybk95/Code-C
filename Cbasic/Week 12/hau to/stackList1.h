#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef nodeTreeT elementtypeT;

typedef struct one_nodeS{
  elementtypeT element;
  struct one_nodeS *next;
} stackS;

typedef struct listS {
  stackS *top;
} stackListS; 

stackListS *initializeS (stackListS *sList) {
  (*sList).top=NULL;
  return sList;
}

stackS *makeNodeS (elementtypeT e) {
  stackS* tmp;
  tmp=(stackS*)malloc(sizeof(stackS));
  if (tmp != NULL) {
    tmp->element=e;
    tmp->next=NULL;
  }
  return tmp;  
}

stackS *pushS (stackListS *sList, elementtypeT e) {
  stackS *tmp=makeNodeS(e);
  if (tmp == NULL) return NULL;
  tmp->next=(*sList).top;
  (*sList).top=tmp;
  return (*sList).top;
}

stackS *popS (stackListS *sList, elementtypeT *e) {
  if ((*sList).top == NULL) return NULL;
  stackS *tmp=(*sList).top; 
  (*sList).top=(*sList).top->next;
  tmp->next=NULL;
  *e=tmp->element;
  free(tmp);
  return (*sList).top;
}

void deleteS (stackListS *sList) {
  while ((*sList).top != NULL) {
    stackS *tmp=(*sList).top;
    (*sList).top=(*sList).top->next;
    tmp->next=NULL;
    free(tmp);
  }
}
/*
main() {
  stackListS sList;
  initializeS(&sList);
  pushS(&sList,readDataS());
  pushS(&sList,readDataS());
  pushS(&sList,readDataS());
  pushS(&sList,readDataS());
  travellingS(sList);
  elementtype e;
  popS(&sList,&e); outputDataS(e); printf("\n");
  popS(&sList,&e); outputDataS(e); printf("\n");
  popS(&sList,&e); outputDataS(e); printf("\n");
  travellingS(sList);
  deleteS(&sList);
}
*/
