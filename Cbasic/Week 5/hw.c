#include<stdio.h>
#include<stdlib.h>
#define MAX 10
main(int argc,char *argv[])
{ int i=1,sum=0,x;
  FILE *f1;
  int *p;
    p=(int*)malloc(MAX*sizeof(int));
    printf("\nNhap : \n");
    scanf("%d%*c",&p[0]);
    while(i<=p[0])
    {
      scanf("%d%*c",&x);
      p[i]=x;i++;
      sum=sum+x;
    }
    if((f1=fopen(argv[1],"w+"))==NULL)
      printf("\nKhong the mo file \n");
  for(i=p[0];i>=1;i--)
    fprintf(f1,"%d ",p[i]);
  fprintf(f1,"%d\n",sum);
  fclose(f1);
}
