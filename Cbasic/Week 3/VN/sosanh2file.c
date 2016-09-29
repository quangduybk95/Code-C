#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int main(int argc,char *argv[])
{
  if(argc!=3)
    {
      printf("Loi cu phap!");
      return 0;
    }
  FILE *file1,*file2;
  char s1[100],s2[100];
  int a[100],dem=0,i=0,j;
  file1=fopen(argv[1],"r");
  file2=fopen(argv[2],"r");
  while(fgets(s1,MAX,file1)!=NULL && fgets(s2,MAX,file2)!=NULL)
    {
      dem++;
      if(strcmp(s1,s2)!=0) {a[i]=dem; i++;}
    }
  if(s1!=NULL)
    {
      while(fgets(s1,MAX,file1)!=NULL)
        {
          dem++; a[i]=dem; i++;
        }
    }
  if(s2!=NULL)
    {
      while(fgets(s2,MAX,file2)!=NULL)
        {
          dem++; a[i]=dem; i++;
        }
    }
  printf("\nDong dau tien ma 2 tep van ban khac nhau la dong so: %d\n",a[0]);
  printf("Cac dong khac nhau o 2 tep van ban: ");
  for(j=0;j<=i-1;j++)
    {
      printf("%d ",a[j]);
    }
  printf("\n\n");
  fclose(file1);
  fclose(file2);
}
