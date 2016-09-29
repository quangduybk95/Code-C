#include<stdio.h>
#include<string.h>
typedef struct x
{
  int x;
  char y[10];
} xx;
main()
{ int i,j;
  xx a[10][10];
  a[0][0].x=0;
  a[0][1].x=1;
  a[0][2].x=2;
  a[1][0].x=2;
  a[1][1].x=0;
  a[1][2].x=1;
  a[2][0].x=1;
  a[2][1].x=2;
  a[2][2].x=0;
  for(i=0;i<3;i++)
    for(j=0;j<3;j++)
      {
        if(a[i][j].x==0) strcpy(a[i][j].y,"Xanh");
        else if(a[i][j].x==1) strcpy(a[i][j].y,"Do");
        else if (a[i][j].x==2) strcpy(a[i][j].y,"Vang");
          }
   for(i=0;i<3;i++)
    for(j=0;j<3;j++)
      {
        printf("%-6s",a[i][j].y);
        if(j==2) printf("\n");
      }

}
