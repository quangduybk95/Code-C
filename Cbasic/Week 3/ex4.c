#include<stdio.h>
#include<stdlib.h>
#define MAX 80
void merge(FILE *f1,FILE *f2,FILE *f3)
{
  char buff1[MAX],buff2[MAX];
  while(((fgets(buff1,MAX,f1))!=NULL)&&((fgets(buff2,MAX,f2))!=NULL))
    { printf("%s",buff1);
      printf("%s",buff2);
      fputs(buff1,f3);
      fputs(buff2,f3);
    }
   while((fgets(buff1,MAX,f1))!=NULL)
    {
      fputs(buff1,f3);
      printf("%s",buff1);
    }
    while((fgets(buff2,MAX,f2))!=NULL)
    {
      fputs(buff2,f3);
      printf("%s",buff2);
    }


}
main(int argc,char *argv[])
{
  FILE *f1,*f2,*f3;
  f1=fopen(argv[1],"r");
  f2=fopen(argv[2],"r");
  f3=fopen(argv[3],"w");
  merge(f1,f2,f3);
  fclose(f1);
  fclose(f2);
  fclose(f3);
}
