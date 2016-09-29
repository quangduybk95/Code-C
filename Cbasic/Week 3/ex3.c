#include<stdio.h>
#include<stdlib.h>
#define MAX 81
main(int argc,char *argv[])
{
  FILE *f1,*f2;
  int a[100],i=0;
  f1=fopen(argv[1],"r");
  f2=fopen(argv[2],"w");
  char c;
  while((c=fgetc(f1))!=EOF)
      if(c!='\n') a[i]++;else{break;i++;}

}

