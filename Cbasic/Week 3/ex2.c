#include<stdio.h>
#include<stdlib.h>
#define MAX 81
void Linereadwrite(FILE *f1,FILE *f2)
{
char buff[MAX];
  while((fgets(buff,MAX,f1))!=NULL)
    {
      fputs(buff,f2);
      printf("%s",buff);
    }
}
main(int argc,char *argv[])
{
  FILE *f1,*f2;
  f1=fopen(argv[1],"r");
  f2=fopen(argv[2],"w");
  Linereadwrite(f1,f2);
  fclose(f1);
  fclose(f2);
}
