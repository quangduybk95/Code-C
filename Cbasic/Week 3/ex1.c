#include<stdio.h>
#include<stdlib.h>
main(int argc,char *argv[])
{
 FILE *f1;
 char c;
 f1=fopen(argv[1],"r+");
 while((c=fgetc(f1))!=EOF)
   if (c=='\n') fputc('\n',f1); else continue;
 fclose(f1);
}
