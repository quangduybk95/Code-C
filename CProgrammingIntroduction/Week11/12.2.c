#include<stdio.h>
main()
{
  int a[7]={13,-355,235,47,67,943,1222},*x,i;
  x=a;
  for (i=0;i<=4;i++)
    {

      printf("%p \n",x);
      x=x+1;
    }
}
