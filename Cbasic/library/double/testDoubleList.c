#include<stdio.h>
#include<stdlib.h>

typedef struct
{
  int num;
} elementtype;

#include "doubleList.h"
///////////////////// cac ham tuy chinh
void displayDoubleList(doubleList list);
elementtype getData();
void bubbleSortDoubleList(doubleList * list);
//////////////////////////////////////
// getdata
elementtype getData()
{
  elementtype e;
  printf("Nhap so: ");scanf("%d%*c",&e.num);
  return e;
}
// sap xep
void bubbleSortDoubleList(doubleList * list)
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
//
void displayDoubleList(doubleList list)
{
  if (list.root != NULL)
    {
      list.cur = list.root;
      while(list.cur != NULL)
        {
          printf("%d\n",list.cur->element.num);
          list.cur = list.cur->next;
        }
    }
}
void displayDoubleList2(doubleList list)
{
  if (list.tail != NULL)
    {
      list.cur = list.tail;
      while(list.cur != NULL)
        {
          printf("%d\n",list.cur->element.num);
          list.cur = list.cur->prev;
        }
    }
}
main()
{
  doubleList list;
  char kt;
  createDoubleList(&list);
  do
    {
      printf("DoubleList test\nMENU:\n");
      printf("0. EXIT\n");
      printf("1. insert begin\n");
      printf("2. insert end\n");
      printf("3. insert position\n");
      printf("4. delete begin\n");
      printf("5. delete end\n");
      printf("6. delete ALl\n");
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
        case '6':
          {
            deleteDoubleList(&list);

          }break;
        case '7': bubbleSortDoubleList(&list);break;
        case '9': displayDoubleList(list);break;
        }
    }
  while(kt != '0');
  //  deleteDoubleList(&list);
}
