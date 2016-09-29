#include<stdio.h>
#include<stdlib.h>
typedef struct
{
  char mskh[20];
  char name[30];
  int tongtien;
  int demtp;
  int demdt;
  int demmm;
}elementtype;
#include"tree.h"
void insertNode(tree *t, elementtype x)
{
  if (*t == NULL){
        *t=(node*)malloc(sizeof(node));
        (*t)->element = x;
        (*t)->left = NULL;
        (*t)->right = NULL;
    }
  else if (strcmp(x.name,(*t)->element.name)<0) insertNode(&(*t)->left,x);
  else if (strcmp(x.name,(*t)->element.name)>0) insertNode(&(*t)->right,x);
  else {
    printf("Da co \n");
    return;
  }
}
void duyet(tree t)
{
  if(t!=NULL)
    {
      duyet(t->left);
      printf("%-20s%-20s%-10d%-10d%-10d%-10d\n",t->element.mskh,t->element.name,t->element.tongtien,t->element.demtp,t->element.demdt,t->element.demmm);
      duyet(t->right);
    }
}
main()
{
  FILE *f;
  f=fopen("topcare.dat","rb");
  elementtype *a;
  tree t;
    makeNullTree(&t);
  a=(elementtype*)malloc(10*sizeof(elementtype));
  int i;
  fread(a,sizeof(elementtype),10,f);
  for(i=0;i<10;i++)
    {
      insertNode(&t,a[i]);
    }
  fclose(f);
  duyet(t);
}