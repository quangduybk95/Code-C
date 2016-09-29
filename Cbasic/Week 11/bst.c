#include<stdio.h>
#include<stdlib.h>
typedef struct
{
  int a;
}keytype;
typedef struct node node;
typedef struct node
{
  keytype key;
  node *left;
  node *right;
}node;
typedef struct
{
  node *root;
}keytype;
treetype r=NULL;
void insertnode(keytype x,keytype b)
{
  if(b==NULL)
    {
      b=(node*)malloc(sizeof(node));
      b.root->key=x;
      b.root->left=NULL;
      b.root->right=NULL;
    }
  else if(x.a<b.root->key.a) insertnode(x,b.root->left);
  else if(x.a>b.root->key.a) insertnode(x,b.root->right);
}
void duyet(treetype tree)
{
  if(tree!=NULL)
    {
      duyet(tree->left);
      printf("%-3d\n",tree->key.a);
      duyet(tree->right);
    }
}
main()
{
  int i,a[10];
  srand(time(NULL));
  for(i=0;i<10;i++)
    {
      a[i]=rand()%100;
      insertnode(a[i],root);
    }
  duyet(root);
}
