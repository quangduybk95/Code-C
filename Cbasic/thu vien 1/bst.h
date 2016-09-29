#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct t_node t_node;
typedef struct t_node
{
  t_elementtype element;
  t_node *left,*right;
}t_node;
typedef struct t_node *treetype;
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

t_node *create_t_node(t_elementtype e)
{
  t_node *new;
  new=(t_node*)malloc(sizeof(t_node));
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

treetype add_t_node(treetype *tree,t_elementtype res)
{
  t_node *new=create_t_node(res);
  if(new==NULL) return (new);
  *tree=new;
}
//Nhap cay.
void insert(treetype *tree,t_elementtype res)
{
  if(*tree==NULL)
    add_t_node(tree,res);
}

//Dem so t_node
int nb_t_node(treetype tree)
{
  if(empty_tree(tree)) return 0;
  else return 1+nb_t_node(left_child(tree))+ nb_t_node(right_child(tree));
}

//Tao 1 cay tu 2 cay con.
treetype create_from_2(t_elementtype e, treetype l,treetype r)
{
  treetype N;
  N=(t_node*)malloc(sizeof(t_node));
  N->element=e;
  N->left=l;
  N->right=r;
  return N;
}
/*int compare(t_elementtype a,t_elementtype b){
  if(strcmp(a.eng,b.eng)<0) return -1;
  else if(strcmp(a.eng,b.eng)==0) return 0;
  else return 1;
  }*/
//Bsearch:
treetype b_search(t_elementtype e,treetype tree){
  if(tree==NULL) return NULL;
  else if(strcmp(tree->element.eng,e.eng)==0) {
    printf("Nghia tieng Viet la: %20s\n",tree->element.vie);
    return tree;
  }
  else if(strcmp(tree->element.eng,e.eng)<0) return b_search(e,tree->right);
  else if(strcmp(tree->element.eng,e.eng)>0) return b_search(e,tree->left);
  else {
    printf("Khong co tu ban tim\n");
    return NULL;
  }
}
void b_insert(t_elementtype e,treetype *tree){
  if((*tree)==NULL){
    *tree=(t_node*)malloc(sizeof(t_node));
    strcpy((*tree)->element.eng,e.eng);
    strcpy((*tree)->element.vie,e.vie);
    (*tree)->left=NULL;
    (*tree)->right=NULL;
  }
  else if(strcmp(e.eng,(*tree)->element.eng)<0) b_insert(e,&(*tree)->left);
  else if(strcmp(e.eng,(*tree)->element.eng)>0) b_insert(e,&(*tree)->right);
}
void inorderprint(treetype tree){
  if(tree!=NULL){
    inorderprint(tree->left);
    printf("%15s: %15s\n",tree->element.eng,tree->element.vie);
    inorderprint(tree->right);
}
}
void inorderprint_file(treetype tree,FILE *f){
    if(tree!=NULL){
    inorderprint_file(tree->left,f);
    fprintf(f,"%-15s:-%15s\n",tree->element.eng,tree->element.vie);
    inorderprint_file(tree->right,f);
}
}
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

//Dem so t_node trong.
int interal_t_node(treetype tree)
{
  if(tree==NULL) return 0;
  else return nb_t_node(tree)-return_leaf(tree)-1;
}

//Dem so t_node con phai
int return_right_t_node(treetype tree)
{
  if(tree==NULL) return 0;
  if(tree->right==NULL) return 0;
  else return 1+return_right_t_node(right_child(tree));
}
t_elementtype  deletemin(treetype *tree){
  t_elementtype e;
  if((*tree)->left==NULL){
    strcmp(e.eng,(*tree)->element.eng);
    (*tree)=(*tree)->right;
    return e;
  }
  else return deletemin(&(*tree)->left);
}
void delete_t_node(t_elementtype e, treetype *tree){
  if(*tree!=NULL)
    if(strcmp(e.eng,(*tree)->element.eng)<0) delete_t_node(e,&(*tree)->left);
    else if(strcmp(e.eng,(*tree)->element.eng)>0)  delete_t_node(e,&(*tree)->right);
    else if(((*tree)->left==NULL) && ((*tree)->right==NULL)) *tree=NULL;
    else if((*tree)->left==NULL) *tree=(*tree)->right;
    else if((*tree)->right==NULL) *tree=(*tree)->left;
    else (*tree)->element=deletemin(tree);
}
void delete_all(treetype *tree){
  while (*tree!=NULL) deletemin(tree);
}
