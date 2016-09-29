//////////////////////////////////////////
typedef struct node{
  elementtype element;
  struct node *right,*left;
} node;

typedef struct node *tree;
///////////////////////////////////////////
tree * makeNullTree(tree *t);
int isEmpty(tree t);
tree childLeft(tree n);
tree childdRight(tree n);
node * makeNewNode(elementtype e);
int isLeaf(tree n);
tree makeNewTreeFromTowTrees(elementtype e,tree left,tree right);
int totalNode(tree t);
int totalLeaf(tree t);
int heighTree(tree t);
tree addRight(tree *t,elementtype e);
tree addLeft(tree *t,elementtype e);
///////////////////////////////////////////
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
  n=(node*)malloc(sizeof(node));
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

int heighTree(tree t)
{
  if(!t) return 0;
  int a=heighTree(t->left);
  int b=heighTree(t->right);
  if(a>b) return a+1;
  else return b+1;
}
/*
elementtype deleteMin(tree *t)
{
  elementtype e;
  if((*t)->left==NULL)
    {
      e.num=(*t)->element.num;
      (*t)=(*t)->right;
      return e;
    }
  else return deleteMin(&(*t)->left);
}

void deleteNode(tree *t,elementtype e)
{
  if((*t)!=NULL) {
    if(e.num<(*t)->element.num) deleteNode(&(*t)->left,e);
    else if(e.num>(*t)->element.num) deleteNode(&(*t)->right,e);
    else if((*t)->left==NULL&&(*t)->right==NULL) (*t)=NULL;
    else if((*t)->left==NULL) (*t)=(*t)->right;
    else if((*t)->right==NULL) (*t)=(*t)->left;
    else (*t)->element=deleteMin(&(*t)->right);
  }
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
void inorderPrint(tree t)
{
  if(t!=NULL)
    {
      inorderPrint(t->left);
      printf("%d ",t->element.num);
      inorderPrint(t->right);
    }
}

void  insertNode(tree *t, elementtype x)
{
  if (*t == NULL){
        *t=(tree)malloc(sizeof(tree));
        (*t)->element.num = x.num;
        (*t)->left = NULL;
        (*t)->right = NULL;
    }
  else if (x.num < (*t)->element.num) insertNode(&(*t)->left,x);
  else if (x.num> (*t)->element.num) insertNode(&(*t)->right,x);
}

tree searchBinary(tree t,elementtype e)
{
  if(t==NULL) return NULL;
  else    if(t->element.num==e.num) return t;
  else  if(t->element.num<e.num)  return searchBinary(t->right,e);
  else  return searchBinary(t->left,e);
}


void padding ( char ch, int n )
{
  int i;
  for ( i = 0; i < n; i++ )
    putchar ( ch );
}
void structure ( tree t, int level )
{
  int i;
  if ( t == NULL ) {
    padding ( '\t', level );
    puts ( "NULL" );
  }
  else {
    structure ( t->right, level + 1 );
padding ( '\t', level );
printf ( "%d\n", t->element.num );
structure ( t->left, level + 1 );
  }
}
////////
/*
///////////////////////////////////////////////////////
main()
{
    tree t;
    int i;
    makeNullTree(&t);
    for(i=1;i<=7;i++) insertNode(&t,getData());
    printf("=>node: %d | leaf: %d | height: %d| Node In: %d\n",totalNode(t),totalLeaf(t),heighTree(t),totalNode(t)-totalLeaf(t));
    inorderPrint(t);
    printf("\n");
    tree x;
    elementtype e;
    e.num=5;
    x=searchBinary(t,e);
    if(x!=NULL) printf("%d\n",x->element.num);
    else printf("Deo tim thay\n");
    e.num=9;
    deleteNode(&t,e);
    inorderPrint(t);
    printf("\n");
    structure ( t, 0 );
    printf("-----\n");
}*/
