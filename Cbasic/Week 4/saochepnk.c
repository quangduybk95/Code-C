#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 50
char* substr(char *s,int k,int n)
{ int j=0;
  s=(char *)malloc(MAX*sizeof(char));
  char *x;
  x=(char *)malloc(n*sizeof(char));
  printf("Nhap xau : ");gets(s);

  int m=strlen(s);
  int i;
  if((k+n)<=m)
    for(i=k;i<(k+n);i++)
        { x[j]=s[i];
          j++;}
  else
    for(i=k;i<m;i++)
       { x[j]=s[i];
          j++;}
  return x;
  free(x);
  free(s);
}
main()
{ char *s,*x;int n,k;
  printf("Nhap k(>=0) : ");scanf("%d%*c",&k);
    printf("Nhap n : ");scanf("%d%*c",&n);
    x= substr(s,k,n);
  printf("ket qua : %s\n",x);
}
