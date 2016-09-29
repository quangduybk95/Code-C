#include<stdio.h>
#include<stdlib.h>
typedef  int keytype;
typedef struct node nodetype;
typedef struct node
{
  keytype key;
  nodetype *left;
  nodetype *right;
}nodetype;
typedef nodetype* treetype;
void insertnode(keytype x,treetype *root)
{
  if(*root==NULL)
    {
      *root=(nodetype*)malloc(sizeof(nodetype));
      (*root)->key=x;
      (*root)->left=NULL;
      (*root)->right=NULL;
    }
  else if(x<(*root)->key) insertnode(x,&(*root)->left);
  else if(x>=(*root)->key) insertnode(x,&(*root)->right);
}
void duyet(treetype tree)
{
  if(tree!=NULL)
    {
      duyet(tree->left);
      printf("%-3d\n",tree->key);
      duyet(tree->right);
    }
}
keytype deletemin(treetype *root)
{
  keytype k;
  if((*root)->left==NULL)
    { k=(*root)->key;
  (*root)=(*root)->right;
  return k;
    }
  else return deletemin(&(*root)->left);
}
void deletenode(keytype x,treetype *root)
{
  if(*root!=NULL)
    if(x<(*root)->key) deletenode(x,&(*root)->left);
    else if(x>(*root)->key) deletenode(x,&(*root)->right);
    else if
      ((*root)->left==NULL&&(*root)->right==NULL)
      *root=NULL;
    else if((*root)->left==NULL)
      *root=(*root)->right;
   else if((*root)->right==NULL)
      *root=(*root)->left;
   else (*root)->key=deletemin(&(*root)->right);
}
void freetree(treetype tree)
{
  if(tree!=NULL)
    {
      freetree(tree->left);
      freetree(tree->right);
      free((void*)tree);
    }
}
treetype search(keytype x,treetype root)
{
  if(root==NULL) return NULL;
  else if(root->key==x)
    return root;
  else if(root->key>x)
    return search(x,root->right);
  else if(root->key<x)
    return search(x,root->left);
}
main()
{
  int i;keytype a[10];
  treetype root;
  srand(time(NULL));
  for(i=0;i<5;i++)
    {
      a[i]=rand()%100;
      // printf("Nhap ptu thu %d : ",i+1);
      // scanf("%d%*c",&a[i]);
      insertnode(a[i],&root);
    }
  duyet(root);
  printf("Nhap so can xoa : ");
  scanf("%d%*c",&i);
  deletenode(i,&root);
   duyet(root);
   freetree(root);
}
