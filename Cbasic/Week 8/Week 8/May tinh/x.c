#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct x
{
  char x[20];
}xx;
void tach(char s[],xx k[],int t)
{ xx b[50];
  int i=0,j=-1,n=strlen(s);
  while(i<n)
    {
      while(s[i]!=' ')
        {
          j++;b[t].x[j]=s[i];i++;
        }
      if(s[i]==' ') {strcpy(k[t].x,b[t].x);t++;i++;}
    }
}
main()
{
  char s[100];xx k[50];int t=0;
  printf("Nhap s : ");
  scanf("%[^\n]s",s);
  tach(s,k,t);
  int i;
  for(i=0;i<t-1;i++)
    {
      printf("%s\n ",k[i].x);
    }

}
