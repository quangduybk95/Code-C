#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define OUT "words.txt"
//////////////////////////////////////////
typedef struct
{
  char en[100];
  char vi[100];
} elementtype;
#include "tree.h"
FILE *f,*f1;
////////////////////////////////////////////////
void duyet(tree t)
{
  if(t!=NULL)
    {
      duyet(t->left);
      printf("%-10s : %-10s\n",t->element.en,t->element.vi);
      duyet(t->right);
    }
}
void  insertNode(tree *t, elementtype x)
{
  if (*t == NULL){
        *t=(node*)malloc(sizeof(node));
        (*t)->element = x;
        (*t)->left = NULL;
        (*t)->right = NULL;
    }
  else if (strcmp(x.en,(*t)->element.en)<0) insertNode(&(*t)->left,x);
  else if (strcmp(x.en, (*t)->element.en)>0) insertNode(&(*t)->right,x);
  else {
    printf("Da co trong tu dien!\n");
    return;
  }
}
// tim kiem
elementtype searchByWord(tree t,elementtype e)
{
  elementtype null;
  strcpy(null.en,"");
  strcpy(null.vi,"");
  if(t==NULL) return null;
  else    if(strcmp(t->element.en,e.en)==0) return t->element;
  else  if(strcmp(t->element.en,e.en)<0)  return searchByWord(t->right,e);
  else  return searchByWord(t->left,e);
}
// xoa
elementtype deleteMin(tree *t)
{
  elementtype e;
  if((*t)->left==NULL)
    {
      e=(*t)->element;
      (*t)=(*t)->right;
      return e;
    }
  else return deleteMin(&(*t)->left);
}
void deleteNode(tree *t,elementtype e)
{
  if((*t)!=NULL) {
    if(strcmp(e.en,(*t)->element.en)<0) deleteNode(&(*t)->left,e);
    else if(strcmp(e.en,(*t)->element.en)>0) deleteNode(&(*t)->right,e);
    else if((*t)->left==NULL&&(*t)->right==NULL) (*t)=NULL;
    else if((*t)->left==NULL) (*t)=(*t)->right;
    else if((*t)->right==NULL) (*t)=(*t)->left;
    else (*t)->element=deleteMin(&(*t)->right);
  }
}
// duyet
void inorderPrint(tree t)
{
  if(t!=NULL)
    {
      inorderPrint(t->left);
      fprintf(f,"%s|%s\n",t->element.en,t->element.vi);
      inorderPrint(t->right);
    }
}
//
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
printf ( "%s\n", t->element.en );
structure ( t->left, level + 1 );
  }
}
////////////////////////////////////////////////
main()
{
  f1=fopen(OUT,"r");
  tree t;
  makeNullTree(&t);
  char kt;
  // getdata
  elementtype x;
  char s[100];
  int i;
  while(fgets(s,80,f1)!=NULL)
      {
        int k=0;
        x.vi[0]=x.en[0]='\0';

        for(i=0 ;s[i]!='|' ;i++)
          {

            x.en[k]=s[i];
            k++;
          }
        x.en[k]='\0';
        k=0;
        for(i=i+1 ;i<strlen(s) ;i++ )
          {
            x.vi[k]=s[i];
            k++;
          }
        x.vi[k]='\0';
          insertNode(&t,x);
      }
  fclose(f1);
   f=fopen(OUT,"w+");
  do
    {
      printf("English-Vietnamese dictionary ver 1.0.0\n--------------------------------------------------\n");
      printf("MENU:\n");
      printf("1. Search\n");
      printf("2. Add new word\n");
      printf("3. Delete old word\n");
      printf("4. Print data\n");
      printf("5. Print on file\n");
      printf("0. Exit\n");
      printf("->Ban chon?: ");scanf("%c%*c",&kt);
      switch(kt )
        {
        case '1':{
          elementtype e,s;
          printf("//Search by tree binary\n");
          printf("-English: ");gets(e.en);
          s=searchByWord(t,e);
          if(strcmp(s.en,"")==0) printf("Khong co trong tu dien!\n hay them tu nay de lam phong phu tu dien!!\n");
          else printf("=>KQ:  %s : %s\n",s.en,s.vi);
        }break;
        case '2': {
          elementtype e;
          printf("//Add new word in data:\n");
          printf("-English   : ");gets(e.en);
          printf("-Vietnamese:");gets(e.vi);
          insertNode(&t,e);
          printf("=>Success\n--------------------------------------------------\n");
        } break;
        case '3': {
          elementtype e;
          printf("Nhap tu muon xoa: ");gets(e.en);
          deleteNode(&t,e);
          printf("=>Xoa thanh cong\n");
        }break;
        case '4': {
          duyet(t);
        }break;
        case '5': {
          f=fopen(OUT,"w+" );
          inorderPrint(t);
          fclose(f);
        }
        }
    }
  while(kt!='0');
}
