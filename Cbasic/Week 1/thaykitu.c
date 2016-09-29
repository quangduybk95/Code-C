#include<stdio.h>
#include<string.h>
void thaykitu(char *str,char c1,char c2)
{
  while(*str!='\0')
    {
      if(*str==c1) *str=c2;
      ++str;
    }
}
main()
{
  char a[100];
  gets(a);
  thaykitu(a,'m','p');
  printf("%s \n",a);
}
