#include<stdio.h>
#include<stdlib.h>
#define MAX 81
#define LINE 100
typedef struct xx
{ char STT[10];
  char MSSV[10];
  char hoten[30];
  char sdt[15];
  int diem;
} sv;
main(int argc,char *argv[])
{
  FILE *f1,*f2;

  char a[MAX][LINE];
  int i=0,n=0;
  f1=fopen(argv[1],"r");
  f2=fopen(argv[2],"w+b");
  while((fgets(a[i],MAX,f1))!=NULL)
  {
    i++;
    n++;
  }
  sv *ss;
  ss=(sv*)malloc(n*sizeof(sv));
fseek(f1,0,SEEK_SET);
for(i=0;i<n;i++)
  {
    fscanf(f1,"%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]",ss[i].STT,ss[i].MSSV,ss[i].hoten,ss[i].sdt);
    fgetc(f1);
  }
 fwrite(ss,sizeof(sv),n,f2);
  for(i=0;i<n;i++)
     printf("%-10s%-10s%-30s%-15s\n",ss[i].STT,ss[i].MSSV,ss[i].hoten,ss[i].sdt);
fclose(f1);
 fclose(f2);
    }
