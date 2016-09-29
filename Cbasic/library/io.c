#include<stdio.h>
#include<string.h>
#define IN "data.txt"
typedef struct{
  char ten[30];
  int tuoi;
  char sdt[15];
  char email[30];
  int diem;
} thongtin;
thongtin ds[10];
int input()
{
  int i;
  FILE *f = fopen(IN,"r");
  int i=0;
  while(!feof(f))
    {
      char ten[30],email[30],sdt[15];
      int tuoi,diem;
      int kt = fscanf(f,"%[^\t]%d\t%s\t%s\t%d",ten,&tuoi,sdt,email,&diem);

      if(kt == 5)
        {
          i++;
          strcat(ds[i].ten,ten);
          ds[i].tuoi,tuoi = tuoi;
          strcat(ds[i].sdt,sdt);
          strcat(ds[i].email,email);
          ds[i].diem = diem;
        }
    }
  fclose(f);
  return i;
}
main()
{
  int i, n = input();
  for(i=1 ;i<=n ;i++ )
    {
      printf("%-30s%-5d%-15s%-30s%-5d\n",ds[i].ten,ds[i].email,ds[i].sdt,ds[i].email,ds[i].diem);
    }
}
