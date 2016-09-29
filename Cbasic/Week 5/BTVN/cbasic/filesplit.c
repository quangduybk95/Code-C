/*Le Vinh Thien 8C*/
#include<stdio.h>
#include<stdlib.h>

typedef struct {
	char stt[5];
	char mssv[9];
	char ten[35];
	char sdt[12];
	char diem[3];
} list;

// cho line dong vao file out1
int out1(char s1[],char s2[],int line,list *sv){
  FILE *f1,*f2;
  int i;
  if((f1=fopen(s1,"r"))==NULL)
    {
      printf("Cannot access file : %s\n",s1);
      return 1;
    }
   if((f2=fopen(s2,"w"))==NULL)
    {
      printf("Cannot access file : %s\n",s2);
      return 1;
    }

   sv=(list *)malloc(line*sizeof(list));
   int irc=fread(sv,sizeof(list),line,f1);

   irc=fwrite(sv,sizeof(list),line,f2);
   /*printf("FILE 1:\n");
   for(i=0;i<line;i++)
   printf("%-30s \%-5s\n",sv[i].ten,sv[i].diem);*/
   free(sv);
   fclose(f1);
   fclose(f2);
   return 0;
}


int out2(char s1[],char s2[],int line, list *sv)
{
  FILE *f1,*f2;
    if((f1=fopen(s1,"r"))==NULL)
    {
      printf("Cannot access file : %s\n",s1);
      return 1;
    }
   if((f2=fopen(s2,"w"))==NULL)
    {
      printf("Cannot access file : %s\n",s2);
      return 1;
    }
   sv=(list *)malloc(1*sizeof(list));
   fseek(f1,line*(sizeof(list)),SEEK_SET);
   // printf("FILE 2:\n");
   while(fread(sv,sizeof(list),1,f1)!=0)
     {
       fwrite(sv,sizeof(list),1,f2);
       //printf("%-30s%-5s\n",sv[0].ten,sv[0].diem);
       }
   free(sv);
   fclose(f1);
   fclose(f2);
   return 0;
}
int main(int argc, char* argv[]){
  if(argc!=5){
    printf("Doi so co dang: $./filesplit input line out1 out2\n");
    return 1;
  }
  list *sv;
  int line=atoi(argv[2]);
  int kq= out1(argv[1],argv[3],line,sv);
  kq=out2(argv[1],argv[4],line,sv);
  printf("=>SUCCESS\n");

}
