#include<stdio.h>
#include<stdlib.h>

typedef struct
{
  int num;
} elementtype;

#include "singleList.h"

///////////////////// cac ham tuy chinh
void displaySingleList(singleList list);
elementtype getData();
int totalSingleList(singleList list);
void bubbleSortSingleList(singleList * list);
//////////////////////////////////////
void displaySingleList(singleList list)
{
  if (list.root == NULL) return;
  printf("----------------DS--------------\n");
  list.cur = list.root;
  while(list.cur != NULL)
    {
      printf("%d\n",list.cur->element.num);
      list.cur = list.cur->next;
    }
}
// getdata
elementtype getData()
{
  elementtype e;
  printf("Nhap so: ");scanf("%d%*c",&e.num);
  return e;
}
// sap xep
void bubbleSortSingleList(singleList * list)
{
  node * tmpI, *tmpJ;
  elementtype tmp;
  for(tmpI = (*list).root ; tmpI != NULL ; tmpI = tmpI->next )
     for(tmpJ = (*list).root ; tmpJ != NULL ; tmpJ = tmpJ->next )
       if (tmpI->element.num > tmpJ->element.num)
         {
           tmp = tmpI->element;
           tmpI->element = tmpJ->element;
           tmpJ->element = tmp;
         }
}


main()
{
  singleList list;
  char kt;
  createSingleList(&list);
  do
    {
      printf("SingleList test\nMENU:\n");
      printf("0. EXIT\n");
      printf("1. insert begin\n");
      printf("2. insert end\n");
      printf("3. insert position\n");
      printf("4. delete begin\n");
      printf("5. delete end\n");
      printf("6. delete All\n");
      printf("7. Sort\n");
      printf("9. display\n");
      printf("Ban chon?: ");
      scanf("%c%*c",&kt);
      switch(kt )
        {
        case '1':
          {
            insertBegin(&list,getData());
          }
          break;
        case '2':{
          insertEnd(&list,getData());
        } break;
        case '3':{
          int i;
          printf("Vi tri chen: ");scanf("%d%*c",&i);
          insertAtPosition(&list,getData(),i);
        }break;
        case '4':deleteBegin(&list) ;break;
        case '5': deleteEnd(&list);break;
        case '6': deleteSingleList(&list);break;
        case '7': bubbleSortSingleList(&list);break;
        case '9': displaySingleList(list);break;
        }
    }
  while(kt != '0');
  deleteSingleList(&list);
}
