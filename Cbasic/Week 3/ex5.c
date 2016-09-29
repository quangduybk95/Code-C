#include<stdio.h>
#include<stdlib.h>
#define MAX 81
void Linereadwrite(FILE *f1)
{ int i=1;
char buff[MAX];
 fprintf(f1,"%d. ",i);i++;
  while((fgets(buff,MAX,f1))!=NULL)
    {  fseek(f1,-1,1);
      fputs(buff,f1);
      fprintf(f1,"%d. ",i);i++;
}
}
main(int argc,char *argv[])
{
  FILE *f1;
  f1=fopen(argv[1],"r+");
  Linereadwrite(f1);
  fclose(f1);
}
