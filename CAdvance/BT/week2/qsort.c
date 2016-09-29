#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
  char xau[20];
}sao;
int int_compare(void const *x,void const *y)
{
  int m,n;
  m=*((int*)x);
  n=*((int*)y);
  if(m==n) return 0;
  return m>n?1:-1;
}
/*int char_compare(void const *x,void const *y)
{
  char m,n;
  m=*((char*)x);
  n=*((char*)y);
  if(m==n) return 0;
  return m>n?1:-1;
  }*/
int char_compare(void const *x,void const *y)
{
  sao m,n;
  m=*((sao*)x);
  n=*((sao*)y);
  if(strcmp(m.xau,n.xau)==0) return 0;
  else if(strcmp(m.xau,n.xau)>0) return 1;
  else return -1;
  }
void qsort(void *buf,
           size_t num,
           size_t size,
           int (*compare)(void const *,void const *)
   );
/*void main()
{
 int i;
 char a[]="aafhicbfbngfnftwfwegg";
 qsort(a,strlen(a),sizeof(char),char_compare);
 for(i=0;i<strlen(a);i++)
    printf("%c\n",a[i]);
    }*/
void main()
{
 int i;
 sao a[10];
 strcpy(a[0].xau,"chao");
 strcpy(a[1].xau,"nam");
 strcpy(a[2].xau,"moi");
 strcpy(a[3].xau,"2014");

 qsort(a,4,sizeof(sao),char_compare);
 for(i=0;i<4;i++)
    printf("%s\n",a[i].xau);
    }
