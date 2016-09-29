#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cstring_cmp(const void *a,const void *b)
{
  const char **ia = (const char**)a;
  const char **ib = (const char**)b;
  return strcmp(*ia,*ib);
}
void print_cstring_array(char **array,size_t len)
{
  size_t i;
  for(i=0;i<len;i++)
    printf("%-10s |",array[i]);
  printf("\n");
}
int main()
{
  char *strings[]={"aad","sfasg","vdv","awefwef","werwer"};
  size_t strings_len = sizeof(strings)/sizeof(char*);
  print_cstring_array(strings,strings_len);
  qsort(strings,strings_len,sizeof(char *),cstring_cmp);
  print_cstring_array(strings,strings_len);
}
