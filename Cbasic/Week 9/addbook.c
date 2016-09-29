#include<stdio.h>
#include<stdlib.h>
#include"queue.h"
main()
{
  queue s;
  makenull_queue(&s);
  int i;
  FILE *f;
  eltype *a,b;
  a=(eltype*)malloc(1*sizeof(eltype));
  f=fopen("addressbook.dat","rb");
  while(fread(a,sizeof(eltype),1,f)!=0)
    {
      enqueue(a[0],&s);
    }

  for(i=0;i<10;i++)
    {

      printf("-----------------\n");
      printf("Name : %s\n",s.element[s.front].name);
      printf("SDT : %s\n",s.element[s.front].sdt);
      printf("Mail : %s\n",s.element[s.front].mail);
      dequeue(&s);
    }
}
