#include<stdio.h>
typedef char eltype;
#include"stack1.h"
typedef eltype stacktype[MAX];

#include<string.h>
main()
{
  char a[MAX];
  stacktype x;
  Initialize(x);
  printf("Nhap chuoi : ");
  gets(a);
  int n=strlen(a);
  int i;
  for(i=0;i<n;i++)
    push(a[i],x);
  while(top!=0)
    printf("%c",pop(x));
  printf("\n");
}