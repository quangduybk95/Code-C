#include<stdio.h>
#include<stdlib.h>
#define MAX 81
#define LINE 100
typedef struct xx
{ char STT[10];
  char MSSV[10];
  char hoten[30];
  char sdt[15];
} sv;
main(int argc,char *argv[])
{
  FILE *f1,*f2;
  sv ss[MAX];
  char a[MAX][LINE];
  int i=0,n=0,diem[MAX];
  f1=fopen(argv[1],"r");
   f2=fopen(argv[2],"w+");
  while((fgets(a[i],MAX,f1))!=NULL)
  {
    i++;
    n++;
  }
fseek(f1,0,SEEK_SET);
for(i=0;i<n;i++)
  {
    fscanf(f1,"%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]",ss[i].STT,ss[i].MSSV,ss[i].hoten,ss[i].sdt);
    fgetc(f1);
  }
 fprintf(f2,"%-10s%-10s%-30s%-15s%-10s\n","STT","MSSV","Ho ten","SDT","DIEM");
 for(i=0;i<n;i++)
   { printf("Nhap diem sv thu %d : ",i+1);scanf("%d%*c",&diem[i]);
fprintf(f2,"%-10s%-10s%-30s%-15s%-10d",ss[i].STT,ss[i].MSSV,ss[i].hoten,ss[i].sdt,diem[i]);
   }
 fprintf(f2,"\n");

 fclose(f1);
 fclose(f2);
    }
