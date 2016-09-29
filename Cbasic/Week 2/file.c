#include<stdio.h>
#include<stdlib.h>
main(int argc,char *argv[])
{
  FILE *f1,*f2;
  f1=fopen(argv[1],"r");
  char c,a[100];int i=0,j=0;
  while((c=fgetc(f1))!=EOF)
    {
      if((c>='a')&&(c<='z')) c=c-'a'+'A';
      else if ((c>='A')&&(c<='Z')) c=c+'a'-'A';
      a[i]=c;
       putchar(a[i]);
      i++;
}
  fclose(f1);
    f2=fopen(argv[2],"w");
  for(j=0;j<i;j++)
    fputc(a[j],f2);
  fclose(f2);
}
