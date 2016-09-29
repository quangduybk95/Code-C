#include<stdio.h>
#include<stdlib.h>
#include"list.h"
main()
{
  FILE *f;int i;
  f=fopen("addressbook.dat","rb");
  eltype *a;
  queue s;
  a=(eltype*)malloc(sizeof(eltype));
  while(fread(a,sizeof(eltype),1,f)!=0)
     enqueue(a[0],&s);
  for(i=0;i<10;i++)
    {
      printf("-----------------\n");
      printf("Name : %s\n",s.head->element.name);
      printf("SDT : %s\n",s.head->element.sdt);
      printf("Mail : %s\n",s.head->element.mail);
      dequeue(&s);
    }
}
