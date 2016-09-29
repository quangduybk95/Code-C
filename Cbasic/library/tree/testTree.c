#include<stdio.h>
#include<stdlib.h>
#define IN "data.txt"
#define OUT "out.txt"
//////////////////////////////////////
typedef struct
{
  char ten[30];
  int tuoi;
  char sdt[15];
  char email[30];
  int num;
} elementtype;

#include "tree.h"
// lay du lieu
elementtype getData()
{
    elementtype e;
    printf("Nhap so: ");scanf("%d%*c",&e.num);
    return e;
}
FILE * fw;
void inorderWrite(tree t)
{
  if(t!=NULL)
    {
      inorderWrite(t->left);
      fprintf(fw,"%s\n",t->element.ten);
      inorderWrite(t->right);
    }
}
int input(tree *t)
{
  FILE *f = fopen(IN,"r");
  elementtype e;
  while(!feof(f))
    {
      int kt = fscanf(f,"%s%d\t%s\t%s\t%d",e.ten,&e.tuoi,e.sdt,e.email,&e.num);

      if(kt == 5)
        {
          insertNode(&(*t),e);
        }
    }
  fclose(f);
  }
main()
{
  char kt;
  tree t;
  createTree(&t);
  do
    {
      printf("Tree test\nMENU:\n");
      printf("=> hien co : %d\n",totalNode(t));
      printf("0. EXIT\n");
      printf("1. en Tree\n");
      printf("2. DISPLAY\n");
      printf("3. DELETE\n");
      printf("4. xem cay\n");
      printf("5. Search\n");
      printf("6. delete All\n");
      printf("7. input from file\n");
      if (isEmpty(t)) printf(" NULL\n");
      else printf("Not NULL\n");
      printf("Ban chon?: ");
      scanf("%c%*c",&kt);
      switch(kt )
        {
        case '1':
          {
            insertNode(&t,getData());
          } break;
        case '2':
          {
            inorderPrint(t);
          } break;
        case '3':
          {
            deleteTreeNode(&t,getData());
          } break;
        case '4':structure(t,0);break;
        case '5':
          {
            elementtype new = searchBinary(t,getData());
            printf("=>%d\n",new.num);
            if(new.num >0 ) printf("Found\n");
            else printf("Not Found\n");
          }
          break;
        case '6': deleteTree(&t);break;
              case '7':
            {
              /* FILE *f = fopen(IN,"r");
              elementtype e;
              while(!feof(f))
                {
                  int kt = fscanf(f,"%s%d\t%s\t%s\t%d",e.ten,&e.tuoi,e.sdt,e.email,&e.num);
                  printf("%s\n",e.ten);
                  if(kt == 5)
                    {
                      insertNode(&t,e);
                    }
                }
              fclose(f);*/
              input(&t);
              }break;
        }
    } while(kt != '0');
  fw = fopen(OUT,"w");
  inorderWrite(t);
  fclose(fw);
}
