#include<stdio.h>
main()
{
  int i;
  for (i=1;i<=256;i++) 
    {
      printf("%c ",i);    
      if (i%16==0) printf("\n");


    }
}
