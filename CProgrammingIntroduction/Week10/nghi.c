#include<stdio.h>
main()
{
  int x,y,z,a,b;
  for (x=1;x<5;x++)
    for (y=0;y<=9;y++)
      for (z=0;z<=9;z++)
        {
          a=x*100+y*10+z;
          b=x*x*x+y*y*y+z*z*z;
          if ((a==b)&&(a>=150)&&(a<=410)) printf("%d%d%d\n",x,y,z);
        }
}
