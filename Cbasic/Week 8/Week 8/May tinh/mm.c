#include<stdio.h>
#include<stdlib.h>
#include"nodestack.h"
#include<string.h>
node *top==NULL;
void tach(char s[],char k[][])
{ char b[50][20];
  int i=0,j=-1,t=-1;n=strlen(s);
  while(i<n)
    {t++;
      while(a[i]!=' ')
        {
          j++;b[j][t]=a[i];i++;
        }
      strcpy(k[t],b[t]);
    }
}
int main()
{
  int lc;char s[100],s1[100];char k[50][20];
  do
    {
      printf("\nMENU\n");
      printf("1.Nhap bieu thuc \n");
      printf("2.Chuyen sang hau to\n");
      printf("3.Tinh gia tri\n");
      printf("4.Thoat\n\n");
      printf("Nhap lua chon(1-4) : ");
      scanf("%d%*c",&lc);
      switch(lc)
        {
        case 1 :
          printf("Moi ban nhap bieu thuc : ");
          scanf("%[^\n]s",s);
          //  gets(s);
          break;
        case 2 :

        case 4 : printf("\nEXIT\n");
        default : printf("ban nhap sai\n");break;
        }
    }
  while(lc!=4);
  return 0;
}
