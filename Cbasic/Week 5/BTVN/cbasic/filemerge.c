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

int main(int argc, char* argv[]){

  if (argc!=4)
    {
      printf("Doi so co dang: $./fm file1 file2 filedich\n");
      return 1;
    }

  FILE *f,*f1,*f2;
  list *sv;
  sv=(list *)malloc(1*sizeof(list));

  if((f=fopen(argv[3],"w"))==NULL)
    {
      printf("Cannnot open file : %s\n",argv[3]);
      return 1;
    }
   if((f1=fopen(argv[1],"r"))==NULL)
    {
      printf("Cannnot open file : %s\n",argv[1]);
      return 1;
    }
   if((f2=fopen(argv[2],"r"))==NULL)
    {
      printf("Cannnot open file : %s\n",argv[2]);
      return 1;
    }

  while((fread(sv,sizeof(list),1,f1))!=0)
    fwrite(sv,sizeof(list),1,f);
  while((fread(sv,sizeof(list),1,f2))!=0)
    fwrite(sv,sizeof(list),1,f);

  printf("=>SUCCESS\n");
  free(sv);
  fclose(f1);
  fclose(f2);
  fclose(f);
}
