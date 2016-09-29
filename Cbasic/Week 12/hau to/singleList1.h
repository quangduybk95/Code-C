#include<stdio.h>
#include<stdlib.h>
#include<string.h>



typedef struct one_nodeL {
  elementtype element;
  struct one_nodeL *next;
} nodeL;

typedef struct one_listL {
  nodeL *root;
} nodeListL;

nodeListL *initializeL (nodeListL *list) {
  (*list).root=NULL;
  return list;
}

nodeL *makeNodeL (elementtype e) {
  nodeL* tmp;
  tmp=(nodeL*)malloc(sizeof(nodeL));
  if (tmp != NULL) {
    tmp->element=e;
    tmp->next=NULL;
  }
  return tmp;  
}

elementtype readDataL (char c) {
  elementtype e;
  e.key=c;
  return e;
}

nodeL *insertListL (nodeListL *list, elementtype e) {
  nodeL *tmp=makeNodeL(e);
  if (tmp == NULL) return NULL;
  if ((*list).root == NULL) {
    (*list).root=tmp;
    return (*list).root;
  } 
  nodeL *cur=(*list).root;
  while (cur->next != NULL)
    cur=cur->next;
  cur->next=tmp;
  return (*list).root;
}

nodeL *insertFirstL (nodeListL *list, elementtype e) {
  nodeL *tmp=makeNodeL(e);
  if (tmp == NULL) return NULL;
  if ((*list).root == NULL) {
    (*list).root=tmp;
    return (*list).root;    
  }
  tmp->next=(*list).root;
  (*list).root=tmp;
  return (*list).root;
}

// chen ngay sau nut co dia chi cur
nodeL *insertMidL (nodeListL *list, elementtype e, nodeL *cur) {
  nodeL *tmp=makeNodeL(e);
  if (tmp == NULL) return NULL;
  if (cur->next == NULL) {
    cur->next=tmp;
    return (*list).root;
  }
  tmp->next=cur->next;
  cur->next=tmp;
  return (*list).root;
}

void outputDataL (elementtype e) {
  printf("%c",e.key);
}

void travellingL (nodeListL list) {
  nodeL *tmp=list.root;
  while (tmp != NULL) {
    outputDataL(tmp->element);
    tmp=tmp->next;
  }
  printf("\n");
}

void deleteL (nodeListL *list) {
  nodeL *tmp=(*list).root; 
  while ((*list).root != NULL) {
    (*list).root=(*list).root->next;
    tmp->next=NULL; 
    free(tmp); 
    tmp=(*list).root;
  }
}

int deleteNodeL (nodeListL *list, int delKey) {
  nodeL *tmp=(*list).root;
  nodeL *before=NULL;
  while (tmp != NULL) {
    if (tmp->element.key == delKey)
      break;
    before=tmp;
    tmp=tmp->next;
  }
  if (tmp == NULL) return -1;
  if (before == NULL) (*list).root=(*list).root->next;
  else
    before->next=tmp->next;
  tmp->next=NULL;
  free(tmp);
  return 1;
}

nodeL *searchingL (nodeListL list, int seaKey) {
  nodeL *tmp=list.root;
  while (tmp != NULL) {
    if (tmp->element.key == seaKey) 
      break;
    tmp=tmp->next;
  }
  return tmp;
}
/*
main() {
  nodeListL list;
  initializeL(&list);
  insertListL(&list,readDataL());
  insertListL(&list,readDataL());
  insertListL(&list,readDataL());
  insertListL(&list,readDataL());
  travellingL(list);

  int delKey;
  printf("nhap phan tu muon xoa: "); scanf("%d",&delKey);
  int kt=deleteNodeL(&list,delKey);
  if (kt == 1) {
    printf("===> xoa thanh cong!\n");
    travellingL(list);
  }
  else {
   printf("===> khong co phan tu can xoa.\n");
   travellingL(list); 
  }

  printf("chen vao dau: \n");
  insertFirstL(&list,readDataL());
  travellingL(list);

  int seaKey;
  printf("nhap phan tu muon tim: "); scanf("%d",&seaKey);
  printf("chen vao giua: \n");
  insertMidL(&list,readDataL(),searchingL(list,seaKey));
  travellingL(list);

  deleteL(&list);
}
*/
