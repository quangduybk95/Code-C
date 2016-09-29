#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define MAX 1000000
typedef struct {
  char string[100];
} elementtype;
elementtype ds[MAX];
#define IN "words.txt"
#include "tree.h"

int input(tree *t)
{
  printf("Dang cho vao cay nhi phan....\n");
  int i = 0;
  FILE *f = fopen(IN,"r");
  elementtype e;
  while(fgets(e.string,80,f)!=NULL)
    {
      i++;
      insertNode(&(*t),e);
    }
  fclose(f);
  printf("=> Hoan tat!\n");
  return i;
}
FILE *fw;
void inorderWrite(tree t)
{

  if(t!=NULL)
    {
      inorderWrite(t->left);
      fprintf(fw,"%s",t->element.string);
      inorderWrite(t->right);
    }
}
void insertionsort(elementtype a[],int n)
{
	int i, j;
	elementtype next;
	for (i=0; i<n; i++) {
		next= a[i];
		for (j=i-1;j>=0 && strcmp(next.string, a[j].string) < 0;j--)
			a[j+1] = a[j];
		a[j+1] = next;
	}
}
main()
{
  time_t t1, t2;
  tree t;
  createTree(&t);
  char kt;
  do{
    printf("Test string sort!\n");
    printf("1. tree\n");
    printf("2. array\n");
    printf("3. EXIT\n");
    printf("Ban chon?: ");scanf("%c%*c",&kt);
    switch(kt){
    case '1':
      {
        time(&t1);
        int n = input(&t);
        printf("=> %d words\n",n);
        printf("Dang them tu moi....\n");
        FILE *f = fopen("new.txt","r");
        elementtype e;
        int d = 0;
        while(fgets(e.string,80,f)!=NULL)
          {
            d++;
            insertNode(&t,e);
          }
        fclose(f);
        printf("Bo sung them : %d tu\n",d);
        fw = fopen(IN,"w+");
        inorderWrite(t);
        fclose(f);
        printf("=> ok!");
        time(&t2);
        printf("==> tree time: %d s\n", (int)(t2-t1));
        printf("------------------------------------------\n");
      } break;
    case '2':{
      time(&t1);
      FILE *f = fopen(IN,"r");
       elementtype e;
        int d = 0;
        printf("Dang cho vao array....\n");
        while(fgets(e.string,80,f)!=NULL)
          {
            d++;
            strcpy(ds[d].string,e.string);
          }
        fclose(f);
        printf("=> %d words\n",d+1);
         printf("Dang them tu moi....\n");
        f = fopen("new.txt","r");
        int k = d;
        while(fgets(e.string,80,f)!=NULL)
          {
            d++;
            strcpy(ds[d].string,e.string);
          }
        fclose(f);
        printf("OK! Bo sung them : %d tu\n",d-k);
        printf("Dang sap xep...\n");
        insertionsort(ds,d);
        fw = fopen(IN,"w+");
        int i;
        for(i = 0 ; i<=d ;i++ )
          fprintf(fw,"%s",ds[i].string);
          fclose(fw);
          time(&t2);
          printf("=>ok\n");
           printf("==> array time: %d s\n", (int)(t2-t1));
          printf("------------------------------------------\n");
    }break;
    }
  } while(kt != '3');
}
