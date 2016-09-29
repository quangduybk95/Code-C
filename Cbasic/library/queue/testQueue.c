#include<stdio.h>
#include<stdlib.h>
///////////////////////////////////////
typedef struct{
  int num;
} elementtype;
#include "queue.h"

void printQueue(queue list)
{
  list.cur = list.root;
  while(list.cur != NULL)
    {
      printf("%d\n",list.cur->element.num);
      list.cur = list.cur->next;
    }
}

elementtype getData()
{
  elementtype e;
  printf("So: ");
  scanf("%d%*c",&e.num);
  return e;
}
main()
{
  char kt;
  queue list;
  createQueue(&list);
  do
    {
      printf("queue test\nMENU:\n");
      printf("=> hien co : %d\n",totalQueue(list));
      printf("0. EXIT\n");
      printf("1. enQueue\n");
      printf("2. deQueue\n");
      printf("3. DISPLAY\n");
      printf("4. DELETE\n");
      printf("Ban chon?: ");
      scanf("%c%*c",&kt);
      switch(kt )
        {
        case '1':
          {
            enQueue(&list,getData());
          }
          break;
        case '2':{
          elementtype e = deQueue(&list);
          printf("POP: %d\n",e.num);
        } break;
        case '3':{
          printQueue(list);
        }break;
        case '4':deleteQueue(&list);break;
        }
    }
  while(kt != '0');
  deleteQueue(&list);
}
