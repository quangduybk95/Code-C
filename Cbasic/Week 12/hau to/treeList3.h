#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct one_nodeT {
  elementtype element;
  struct one_nodeT *left;
  struct one_nodeT *right;
} nodeT;
typedef nodeT *nodeTreeT;

nodeTreeT *initializeT (nodeTreeT *root) {
  (*root)=NULL;
  return (root);
}

nodeTreeT makeNodeT (elementtype e) {
  nodeTreeT tmp;
  tmp=(nodeTreeT)malloc(sizeof(nodeTreeT));
  if (tmp != NULL) {
    tmp->element=e;
    tmp->left=NULL;
    tmp->right=NULL;
  }
  return tmp;
}

nodeTreeT leftChildT (nodeTreeT root) {
  if (root != NULL) return root->left;
  else return NULL;
}

nodeTreeT rightChildT (nodeTreeT root) {
  if (root != NULL) return root->right;
  else return NULL;
}

int isLeafT (nodeTreeT root) {
  if (root != NULL) return (leftChildT(root) == NULL && rightChildT(root) == NULL);
  else return -1;
}

nodeTreeT insertLeftT (nodeTreeT *root, elementtype e) {
  nodeTreeT tmp=makeNodeT(e);
  if (tmp == NULL) return NULL;
  if ((*root) == NULL) (*root)=tmp;
  else {
    nodeTreeT cur=(*root);
    while (cur->left != NULL)
      cur=cur->left;
    cur->left=tmp;
  }
  return tmp;
}

nodeTreeT insertRightT (nodeTreeT *root, elementtype e) {
  nodeTreeT tmp=makeNodeT(e);
  if (tmp == NULL) return NULL;
  if ((*root) == NULL) (*root)=tmp;
  else {
    nodeTreeT cur=(*root);
    while (cur->right != NULL)
      cur=cur->right;
    cur->right=tmp;
  }
  return tmp;
}

nodeTreeT insertT (nodeTreeT *root, elementtype e) {
  nodeTreeT tmp=makeNodeT(e);
  if (tmp == NULL) return NULL;
  if ((*root) == NULL) (*root)=tmp;
  else {
    if (tmp->element.key < (*root)->element.key) {
      if ((*root)->left) 
	insertT(&(*root)->left,e);
      else
	(*root)->left=tmp; 
    }
    else if (tmp->element.key > (*root)->element.key) {
      if ((*root)->right)
	insertT(&(*root)->right,e);
      else 
	(*root)->right=tmp;
    }
  }
  return tmp;
}

nodeTreeT insert_nonT (nodeTreeT *root, elementtype e) {
  nodeTreeT tmp=makeNodeT(e);
  if (tmp == NULL) return NULL;
  if ((*root) == NULL) (*root)=tmp;
  else {
    nodeTreeT cur=(*root);
    int addleft=1;
    while (cur->element.key != e.key) {
      if (cur->element.key > e.key) {
	addleft=1;
	if (cur->left != NULL) cur=cur->left;
	else break;
      }
      else {
	addleft=0;
	if (cur->right != NULL) cur=cur->right;
	else break;
      }
    }
    if (addleft == 1) cur->left=tmp;
    else cur->right=tmp;
  }
  return tmp;
}

void outputDataT (elementtype e) {
  printf("%c",e.key);
}

void RootLR_TravellingT (nodeTreeT root) {
  if (root == NULL) return ;
  outputDataT(root->element);
  RootLR_TravellingT(leftChildT(root));
  RootLR_TravellingT(rightChildT(root));
}

void LRootR_TravellingT (nodeTreeT root) {
  if (root == NULL) return ;
  LRootR_TravellingT(leftChildT(root));
  outputDataT(root->element);
  LRootR_TravellingT(rightChildT(root));
}

void LRRoot_TravellingT (nodeTreeT root) {
  if (root != NULL) {
    LRRoot_TravellingT(leftChildT(root));
    LRRoot_TravellingT(rightChildT(root));
    outputDataT(root->element);
  }
}

int heightT (nodeTreeT root) {
  if (root == NULL) return 0;
  int HL=heightT(leftChildT(root));
  int HR=heightT(rightChildT(root));
  if (HL > HR) return HL+1;
  else return HR+1;
}

int countNodeT (nodeTreeT root) {
  if (root == NULL) return 0;
  else return 1+countNodeT(leftChildT(root))+countNodeT(rightChildT(root));
}

int countLeafT (nodeTreeT root) {
  if (root == NULL) return 0;
  if (isLeafT(root)) return 1;
  else return countLeafT(leftChildT(root))+countLeafT(rightChildT(root));
}

int countLeftChidT (nodeTreeT root) {
  if (root == NULL) return 0;
  if (leftChildT(root))
    return 1+countLeftChidT(leftChildT(root))+countLeftChidT(rightChildT(root));
  else 
    countLeftChidT(leftChildT(root));
}

int countRightChidT (nodeTreeT root) {
  if (root == NULL) return 0;
  if (rightChildT(root)) 
    return 1+countRightChidT(rightChildT(root))+countRightChidT(leftChildT(root));
  else
    countRightChidT(leftChildT(root));
}

nodeTreeT searchingT (nodeTreeT root, int seakey) {
  if (root == NULL) return NULL;
  if (root->element.key == seakey) return root;
  if (root->element.key < seakey) return searchingT(rightChildT(root),seakey);
  else return searchingT(leftChildT(root),seakey);
}

nodeTreeT searching_nonT (nodeTreeT root, int seakey) {
  nodeTreeT tmp=root;
  while (tmp != NULL && tmp->element.key != seakey) {
    if (tmp->element.key > seakey) tmp=tmp->left;
    else tmp=tmp->right;
  }
  return tmp;
}

void deleteT (nodeTreeT *root) {
  if (*root == NULL) return;
  deleteT(&(*root)->left);
  deleteT(&(*root)->right);
  free(*root);  
}

void createT (nodeTreeT *root) {
  int x; elementtype e;
  do {
    printf("nhap (-1 de ket thuc): "); scanf("%d",&x);
    if(x != -1) {
      e.key=x;
      insertT(root,e);
    }
  } while (x != -1);
}

// xoa node la node la
elementtype deleteNodeLeafT (nodeTreeT *root) {
  elementtype e;
  if ((*root)->left == NULL) {
    e=(*root)->element;
    (*root)=(*root)->right;
    return e;
  }
  else return deleteNodeLeafT(&(*root)->left);
}

nodeTreeT createfrom2 (elementtype e, nodeTreeT e1, nodeTreeT e2) {
  nodeTreeT tmp=makeNodeT(e);
  tmp->left=e1;
  tmp->right=e2;
  return tmp;
}


/*
main() {
  nodeTreeT root;
  initializeT(&root);
  createT(&root);
  printf("\nDuyet giua: \n"); LRootR_TravellingT(root);
  printf("\n\nchieu cao cay    : %d\n",heightT(root));
  printf("\nso nut cua cay   : %d\n",countNodeT(root));
  printf("\nso la            : %d\n",countLeafT(root));
  printf("\nso con trai      : %d\n",countLeftChidT(root));
  printf("\nso con phai      : %d\n",countRightChidT(root));
  int seakey;
  printf("\nnhap phan tu can tim: "); scanf("%d",&seakey);
  if (searchingT(root,seakey) != NULL) printf("===>tim thanh cong\n");
  else printf("===>khong co phan tu can tim\n");

  printf("\n");
  deleteT(&root);
}
*/
