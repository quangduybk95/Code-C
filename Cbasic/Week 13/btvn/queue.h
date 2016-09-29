//Doan Anh Tu
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct elementtype
{
  int key;
}elementtype;
typedef struct node node;
typedef struct node
{
  elementtype element;
  node *left,*right;
}node;
typedef struct node *treetype;

void make_null_tree(treetype *T)
{
  (*T)=NULL;
}

int empty_tree(treetype T)
{
  return T==NULL;
}

treetype left_child(treetype n)
{
  if(n!=NULL) return n->left;
  else return NULL;
}

treetype right_child(treetype n)
{
  if(n!=NULL) return n->right;
  else return NULL;
}

node *create_node(elementtype e)
{
  node *new;
  new=(node*)malloc(sizeof(node));
  if(new!=NULL)
    {
      new->left=NULL; new->right=NULL; new->element=e;
    }
  return new;
}

int is_leaf(treetype n)
{
  if(n!=NULL)
    return ((left_child(n)==NULL) && (right_child(n)==NULL));
  else return -1;
}

treetype add_left(treetype *tree, elementtype res) //them 1 node vao trai nhat
{
  node *new=create_node(res);
  if(new==NULL) return (new);
  if(*tree==NULL)
    *tree=new;
  else
    {
      node *Lnode=*tree;
      while(Lnode->left != NULL)
        Lnode=Lnode->left;
      Lnode->left=new;
    }
  return (new);
}

treetype add_right(treetype *tree, elementtype res) //them 1 node vao vi tri phai nhat.
{
  node *new=create_node(res);
  if(new==NULL) return (new);
  if(*tree==NULL)
    *tree=new;
  else
    {
      node *Rnode=*tree;
      while(Rnode->right != NULL)
        Rnode=Rnode->right;
      Rnode->right=new;
    }
  return (new);
}


//Nhap cay nhi phan.
treetype add_node(treetype *tree,elementtype res)
{
  node *new=create_node(res);
  if(new==NULL) return (new);
  *tree=new;
}
void insert(treetype *tree,elementtype res)
{
  int a;
  if(*tree==NULL)
    add_node(tree,res);
  else
    {
      node *tmp=*tree;
      a=tmp->element.key;
      if(res.key<a) insert(&tmp->left,res);
      if(res.key==a) insert(&tmp->right,res);
      if(res.key>a) insert(&tmp->right,res);
    }
}


//Dem so node
int nb_node(treetype tree)
{
  if(empty_tree(tree)) return 0;
  else return 1+nb_node(left_child(tree))+ nb_node(right_child(tree));
}

//Tao 1 cay tu 2 cay con.
/*treetype create_from_2(elementtype e, treetype l,treetype r)
{
  treetype N;
  N=(node*)malloc(sizeof(node));
  N->key=e;
  N->left=l;
  N->right=r;
  return N;
}
*/

// Return height
int return_height(treetype tree)
{
  if(tree==NULL) return 0;
  int lh=return_height(tree->left);
  int rh=return_height(tree->right);
  return 1+(lh>rh?lh:rh);
}


//DEM SO LA
int return_leaf(treetype tree)
{
  if(tree!=NULL)
    {
      int a=return_leaf(tree->left);
      int b=return_leaf(tree->right);
      if(tree->left==NULL && tree->right==NULL)
        return 1+a+b;
      return a+b;
    }
  return 0;
}


//Dem so node trong.
int interal_node(treetype tree)
{
  if(tree==NULL) return 0;
  else return nb_node(tree)-return_leaf(tree)-1;
}


//Dem so node con phai
int return_right_node(treetype tree)
{
  if(tree==NULL) return 0;
  if(tree->right==NULL) return 0;
  else return 1+return_right_node(right_child(tree));
}


//Tim kiem tren BST
treetype search(elementtype x,treetype tree)
{
  if(tree==NULL) return NULL;
  else if(tree->element.key==x.key)
    return tree;
  else if(tree->element.key<x.key)
    return search(x,tree->right);
  else
    {
      return search(x,tree->left);
    }
}


//DISPLAY
void print_NLR(treetype tree) //duyet theo thu tu truoc(NODE_LEFT_RIGHT)
{
  if(tree!=NULL)
    {
      printf("%d\n",tree->element.key);
      print_NLR(tree->left);
      print_NLR(tree->right);
    }
}
void print_LNR(treetype tree) //duyet theo thu tu giua.
{
  if(tree!=NULL)
    {
      print_LNR(tree->left);
      printf("%d\n",tree->element.key);
      print_LNR(tree->right);
    }
}
void print_LRN(treetype tree) //duyet theo thu tu sau.
{
  if(tree!=NULL)
    {
      print_LRN(tree->left);
      print_LRN(tree->right);
      printf("%d\n",tree->element.key);
    }
}


//DELETE
elementtype delete_min(treetype *tree)
{
  elementtype k;
  if((*tree)->left==NULL)
    {
      k=(*tree)->element;
      (*tree)=(*tree)->right;
      return k;
    }
  else return delete_min(&(*tree)->left);
}
void freetree(treetype tree)
{
  if (tree!=NULL)
    {
      freetree(tree->left);
      freetree(tree->right);
      free((void*) tree);
    }
}
/*void delete_node(elementtype x,treetype *tree)
{
  if(*tree!=NULL)
    if(strcmp(x.word,(*tree)->element.word)==-1)
      delete_node(x,&(*tree)->left);
    else if (strcmp(x.word,(*tree)->element.word)==1)
      delete_node(x,&(*tree)->right);
    else if(((*tree)->left==NULL)&&((*tree)->right==NULL))
      *tree=NULL;
    else if((*tree)->left==NULL)
      *tree=(*tree)->right;
    else if((*tree)->right==NULL)
      *tree=(*tree)->left;
    else(*tree)->element=delete_min(&(*tree)->right);
}
*/

//FIND-MAX_MIN
treetype find_max(treetype tree)
{
  treetype tmp;
  tmp=tree;
  if(tmp!=NULL)
    {
      while(tmp->right!=NULL)
        tmp=tmp->right;
    }
  return tmp;
}
treetype find_min(treetype tree)
{
  treetype tmp;
  tmp=tree;
  if(tmp!=NULL)
    {
      while(tmp->left!=NULL)
        tmp=tmp->left;
    }
  return tmp;
}

//////////////////////////////////////////////////////


typedef treetype q_elementtype;
typedef struct
{
  q_elementtype element[MAX];
  int front,rear;
}queue;

void MakeNull_queue(queue *q) //tao mot hang doi rong.
{
  q->front=-1;
  q->rear=-1;
}

int empty_queue(queue q) //Kiem tra hang doi co rong khong.
{
  return q.front==-1;
}

int full_queue(queue q) //Kiem tra queue co day khong.
{
  return (q.rear-q.front+1)==MAX;
}

void Enqueue(treetype e,queue *q)
{
  if(!full_queue(*q))
    {
      if(empty_queue(*q)) q->front=0;
      q->rear=q->rear+1;
      q->element[q->rear]=e;
    }
  else printf("Queue is full!\n");
}

treetype Dequeue(queue *q)
{
  treetype tmp;
  if(!empty_queue(*q))
    {
      tmp=q->element[q->front];
      q->front=q->front+1;
      if(q->front > q->rear)
        MakeNull_queue(q);
    }
  else printf("Queue rong!\n");
  return tmp;
}

void breadth_first(treetype tree)
{
  queue q[1];
  treetype tmp;
  if(tree!=NULL)
    {
      Enqueue(tree,&q[0]);
      while(!empty_queue(q[0]))
        {
          tmp=Dequeue(&q[0]);
          printf("%d\n",tmp->element.key);
          if (tree->left!=NULL)
            Enqueue(tree->left,&q[0]);
          if (tree->right!=NULL)
            Enqueue(tree->right,&q[0]);
        }
    }
}
