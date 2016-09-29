#include<stdio.h>
#include<stdlib.h>
#define MAX 81
#define LINE 100
main(int argc,char *argv[])
{
  FILE *f1;
  int i=0,n=0;
  f1=fopen(argv[1],"r+");
    char b[LINE][MAX];
  while(fgets(b[i],MAX,f1)!=NULL)
    {
      i++;
      n++;
    }
  fseek(f1,0L,SEEK_SET);
  for(i=0;i<n;i++)
    {
      fprintf(f1,"%d. %s",i+1,b[i]);
      fprintf(f1,"\n");
    }
}
