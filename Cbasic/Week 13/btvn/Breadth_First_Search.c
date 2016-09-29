// Doan Anh Tu
#include "queue.h"
#include <time.h>
int main()
{
  treetype tree;
  elementtype tmp;
  int i,r;
  make_null_tree(&tree);
  srand(time(NULL));
  for(i=0;i<10;i++)
    {
      tmp.key=rand()%20;
      insert(&tree,tmp);
    }
  printf("-----------------\n");
  print_LNR(tree);
  printf("-----------------\n");
  breadth_first(tree);
}
