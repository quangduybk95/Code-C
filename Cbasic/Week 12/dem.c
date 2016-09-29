#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
  char c[10];
  int num;
}elementtype;
#include"tree.h"
void  insertNode(tree *t, elementtype x)
{
  if (*t == NULL){
        *t=(tree)malloc(sizeof(tree));
        (*t)->element= x;
        (*t)->element.num=1;
        (*t)->left = NULL;
        (*t)->right = NULL;
    }
  else if (x.num < (*t)->element.num) insertNode(&(*t)->left,x);
  else if (x.num> (*t)->element.num) insertNode(&(*t)->right,x);
  else
    {
      printf("da co\n");
              (*t)->element.num++;
  }
}
void inorderPrint(tree t)
{
  if(t!=NULL)
    {
      inorderPrint(t->left);
      printf("%s : %d\n",t->element.c,t->element.num);
      inorderPrint(t->right);
    }
}
main()
{
  FILE *f;
  f=fopen("word.txt","r");
  tree t;
  elementtype x;
  makeNullTree(&t);
  while(!foef(f))
    { strcpy(x.c,"");
      fscanf(f,"%s%*c",x.c);
      insertNode(&t,x);
    }
  inorderPrint(&t);
}
