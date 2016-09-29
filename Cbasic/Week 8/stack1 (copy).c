#include<stdio.h>
#include"stack1.h"
main()
{
  int i=0;
  stacktype stack;
  Initialize(stack);
  int n;
  printf("Nhap so n : ");scanf("%d%*c",&n);
  while(n!=0)
    {
      i=n%2;
      push(i,stack);
      n=n/2;
    }
  while(top!=0)
    {
      printf("%d ",pop(stack));
    }
  printf("\n");
}
