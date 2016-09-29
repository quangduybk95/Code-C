#include<string.h>
#include<stdio.h>
#include<stdlib.h>
typedef struct
{
  int num;
} elementtype;
typedef struct node{
  elementtype element;
  struct node *right,*left;
} node;

typedef struct node *tree;
tree * makeNullTree(tree *t);
int isEmpty(tree t);
tree childLeft(tree n);
tree childdRight(tree n);
node * makeNewNode(elementtype e);
int isLeaf(tree n);
tree makeNewTreeFromTowTrees(elementtype e,tree left,tree right);
int totalNode(tree t);
int totalLeaf(tree t);
tree addRight(tree *t,elementtype e);
tree addLeft(tree *t,elementtype e);
// khoi tao cay rong
tree* makeNullTree(tree *t)
{
  (*t)=NULL;
  return t;
}
// rong?
int isEmpty(tree t)
{
  return t==NULL;
}
// truy cap trai phai
tree childLeft(tree n)
{
  if(n!=NULL) return n->left;
  else return NULL;
}

tree childdRight(tree n)
{
  if(n!=NULL) return n->right;
  else return NULL;
}
// co phai la?
int isLeaf(tree n)
{
  if(n!=NULL) return ((n->left)==NULL)&&((n->right)==NULL);
  else return -1;
}
// tao mot nut moi
tree makeNewNode(elementtype e)
{
  tree  new;
  new=(tree)malloc(sizeof(tree));
  new->left=NULL;
  new->right=NULL;
  new->element=e;
  return new;
}

// tao mot cay tu 2 cay con
tree makeNewTreeFromTowTrees(elementtype e,tree left,tree right)
{
  tree n;
  n=(tree)malloc(sizeof(tree));
  n->left=left;
  n->right=right;
  n->element=e;
  return n;
}

// them mot nut vao ben trai
tree addLeft(tree *t,elementtype e)
{
  tree new=makeNewNode(e);
  if(new==NULL) return new;
  if((*t)==NULL) (*t)=new;
  else
	{
      tree leftNode=(*t);
      while(leftNode->left!=NULL) leftNode=leftNode->left;
      leftNode->left=new;
	}
  return new;
}
// them mot nut vao ben phai
tree addRight(tree *t,elementtype e)
{
  tree new=makeNewNode(e);
  if(new==NULL) return new;
  if((*t)==NULL) (*t)=new;
  else
	{
      tree rightNode=(*t);
      while(rightNode->right!=NULL) rightNode=rightNode->right;
      rightNode->right=new;
	}
  return new;
}
// tong so nut
int totalNode(tree t)
{
	if(isEmpty(t)) return 0;
	else return 1+totalNode(t->left)+totalNode(t->right);
}
// tong so la
int totalLeaf(tree t)
{
	if(t==NULL) return 0;
	if(isLeaf(t)) return 1;
	else return totalLeaf(t->left)+totalLeaf(t->right);
}

///////////////////////////////////////////
elementtype getData()
{
	elementtype e;
	printf("Nhap so: ");scanf("%d",&e.num);
	return e;
}
void traversing(tree t)
{
  if(t!=NULL)
    {
      printf("%d ",t->element.num);
      traversing(t->left);
      traversing(t->right);
    }
  else  return;
}
main()
{
	tree t;
	makeNullTree(&t);
	addLeft(&t,getData());
	addLeft(&t,getData());
    addRight(&t,getData());
	addLeft(&t,getData());
	addLeft(&t,getData());
	addRight(&t,getData());
	addRight(&t,getData());
	printf("=>node: %d | leaf: %d\n",totalNode(t),totalLeaf(t));
    traversing(t);
    printf("\n");
}
