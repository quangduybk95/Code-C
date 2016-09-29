#include<stdio.h>
FILE *fptr;
if((fptr=fopen("test.txt","r"))==NULL)
  {
    printf("can't \n");exit(1);
  }
