#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
  if(argc!=3)
    {
      printf("Loi cu phap!\n");
      return 0;
    }
  FILE *fin;
  char c;
  int n,k;
  fin=fopen(argv[1],"r+");
  n=atof(argv[2]);
  while((c=fgetc(fin))!=EOF)
    {
      if(c>='A' && c<='Z')
        {
          k=c+n%26;
          if(k<=90)
            {
              c=k;
              fseek(fin,-1,SEEK_CUR);
              fputc(c,fin); putchar(c);
            }
          if(k>90)
            {
              c=64+k-90;
              fseek(fin,-1,SEEK_CUR);
              fputc(c,fin); putchar(c);
            }
        }
      else
      if(c>='a' && c<='z')
        {
          k=c+n%26;
          if(k<=122)
            {
              c=k;
              fseek(fin,-1,SEEK_CUR);
              fputc(c,fin); putchar(c);
            }
          if(k>122)
            {
              c=96+k-122;
              fseek(fin,-1,SEEK_CUR);
              fputc(c,fin); putchar(c);
            }
        }
      else putchar(c);
    }
  printf("\nCompleted!\n");
  fclose(fin);
}
