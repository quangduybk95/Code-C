#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 100
char *x(char a[],char b[])
{
  int i=0,j;
  char *kqua;
  kqua=(char *)malloc((strlen(a)+strlen(b)+1)*sizeof(char));
  for(j=0;j<strlen(a);j++)
    {
      *(kqua+i)=a[j];
      i++;
    }
  for(j=0;j<strlen(b);j++)
    {
      *(kqua+i)=b[i];
      i++;
    }
  printf("%s \n",*kqua);
  return kqua;
}
main()
{
  char str1[max],str2[max];
  char *kqua;
  printf("Nhap chuoi : \n");
  gets(str1);
  gets(str2);
  kqua=x(str1,str2);
  if(kqua==NULL)
    {
      printf("\n Loi\n");
      return 1;
    }
  printf("kqua : %s %s %s",str1,str2,kqua);
  free(kqua);
  return 0;
}
