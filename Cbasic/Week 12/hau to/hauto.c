#include<stdio.h>

typedef struct {
  char key;
} elementtype;
#include "stackList0.h"
#include "singleList1.h"
#include "treeList3.h"
#include "stackList1.h"

int kt_so_hang(char c)
{
  if(c>='0' && c<='9')
    return 1;
  else return 0;
}

int kt_phep_toan(char c)
{
  if(c == '+' || c == '-' || c == '*' || c == '/' || c == '!')
    return 1;
  else return 0;
}
/*
float tinh (nodeTreeT e, nodeTreeT e1, nodeTreeT e2) {
  char c=e->element.key;
  float x=(float)e1->element.key,y=(float)e2->element.key;
  if (c == '+') return x+y;
  else if (c == '-') return x-y;
  else if (c == '*') return x*y;
  else if (c == '/') return x/y;
}

float calculator (nodeTreeT root) {
  if (root != NULL) {
    calculator(root->left);
    calculator(root->right);
    tinh(root,root->left,root->right);
  }
  return (float)root->element.key;
  }*/

main() {
  stackList sList;
  initialize(&sList);
  char p[100];
  printf("nhap bieu thuc: "); gets(p);
  int i;
  elementtype e;
  printf("bieu thuc hau to: \n");
  nodeListL list;
  initializeL(&list);
  for (i=0;i<strlen(p);i++) {
    if (p[i] == '(') continue;
    if (kt_so_hang(p[i]) == 1) {
      //printf("%c ",p[i]);
      insertListL(&list,readDataL(p[i]));
    }
    if (kt_phep_toan(p[i]) == 1) push(&sList,readData(p[i]));
    if (p[i] == ')') {
      pop(&sList,&e);
      //printf("%c ",e.key);
      insertListL(&list,e);
    }
  }
  travellingL(list);
  stackListS sList1;
  initializeS(&sList1);
  nodeL *tmp=list.root;
  nodeTreeT t1,t2,t;
  elementtype ee;
  float x,y,z;
  while (tmp != NULL) {
    ee=tmp->element;
    if (kt_so_hang(ee.key) == 1) {
      pushS(&sList1,makeNodeT(ee));
    }
    if (kt_phep_toan(ee.key) == 1) {
      popS(&sList1,&t2); popS(&sList1,&t1);
      pushS(&sList1,createfrom2(ee,t1,t2));
    }
    tmp=tmp->next;
  }
  popS(&sList1,&t);
  LRRoot_TravellingT(t);
  printf("\n");

  // tinh

  //printf("ket qua la: %.1f\n",calculator(t));

  delete(&sList);
  deleteL(&list);
  deleteS(&sList1);
  deleteT(&t);
}
