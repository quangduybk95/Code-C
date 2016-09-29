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
  if (argc!=2)
    {
      printf("Doi so co dang: $./fr file\n");
      return 1;
    }
  FILE *f;
  list *sv;
  sv=(list *)malloc(1*sizeof(list));
  if((f=fopen(argv[1],"r"))==NULL)
    {
      printf("Cannnot open file : %s\n",argv[1]);
      return 1;
    }
  while((fread(sv,sizeof(list),1,f))!=0)
    printf("%-5s%-9s%-30s%-12s%-4s\n",sv[0].stt,sv[0].mssv,sv[0].ten,sv[0].sdt,sv[0].diem);
  printf("=>SUCCESS\n");
  free(sv);
  fclose(f);

}
