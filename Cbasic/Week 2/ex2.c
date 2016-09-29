#include <stdio.h>
#define X 26
#include <string.h>
main(int argc,char *argv[])
{ char c;
  int i = 0;
   int count[X] = {0};
  FILE *fptr,*fptw;
    fptr=fopen(argv[1], "r");
    fptw=fopen(argv[2], "w");
	while ((c=fgetc(fptr)) != EOF)
      {
        if (c <= 'z'  &&  c >= 'a')
          c=c-('a'-'A');
     else	if (c <= 'Z'  &&  c >= 'A')
      c=c+'a'-'A';
        fputc(c,fptw);
        putchar(c);
      }
    fclose(fptr);
    fclose(fptw);
}
