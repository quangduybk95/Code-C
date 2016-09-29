#include<stdio.h>
#include<stdlib.h>
#include"stack2.h"
main()
{ int i=0;
  stacktype *a;
  a=(stacktype*)malloc(2*sizeof(stacktype));
  eltype k;
  a[0].top=0;
  a[1].top=0;
  for(i=0;i<2;i++)
    {
      push(nhapdulieu(),&a[0]);
    }
   for(i=0;i<1;i++)
    {

      push(nhapdulieu(),&a[1]);
    }
   printf("%d %d \n",a[0].top,a[1].top);
   while(a[0].top!=0)
     {
       indulieu(pop(&a[0]));
     }
   printf("\n\n\n");
    while(a[1].top!=0)
     {
       indulieu(pop(&a[1]));
     }
}
