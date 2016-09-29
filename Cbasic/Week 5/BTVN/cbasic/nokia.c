#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define IN "nokiadb.txt"
#define OUT "nokiadb.dat"
#define MAX 3
typedef struct{
  char model[15];
  char memory[10];
  char size[5];
  char price[15];
}list;

int size_file()
{
  FILE *f;
  int d=0;
  char s[100];
  if((f=fopen(IN,"r"))==NULL) return 0;

  while((fgets(s,81,f))!=NULL) d++;
  return d;
  fclose(f);
}
//////////////////////////////submenu 1
// tach thong tin

list get(char s[])
{
  list a;
  int n,i,k=0,m;
  // lay gia tien
  for(n=strlen(s)-2;n>=0;n--)
    if (s[n]==' ') break;
  for(i=n+1;i<=strlen(s)-2 ;i++)
    {
      a.price[k]=s[i];
      k++;
    }
  a.price[k]='\0';
  // lay kich thuoc man hinh
  k=0;n--;m=n;
  while(s[m]!=' ') m--;
  for(i=m+1;i<=n;i++ )
    {
      a.size[k]=s[i];
      k++;
    }
  a.size[k]='\0';
  //lay bo nho
    k=0;m--;n=m;
  while(s[m]!=' ') m--;
  for(i=m+1;i<=n;i++ )
    {
      a.memory[k]=s[i];
      k++;
    }
  a.memory[k]='\0';
  // lay model
  k=0;m--;
  for(i=0;i<=m;i++ )
    {
      a.model[k]=s[i];
      k++;
    }
  a.model[k]='\0';
  return a;
}
// lay thong tin ghi ra file .dat
int get_info(list *dt)
{
  char s[100];
  int i,n;
  FILE *f1,*f2;
  if((f1=fopen(IN,"r"))==NULL){
    printf("Cannot open file: %s\n",IN);
    return 1;
  }
  if((f2=fopen(OUT,"w"))==NULL){
    printf("Cannot open file: %s\n",OUT);
    return 1;
  }
  dt=(list *)malloc(1*sizeof(list));

  while((fgets(s,81,f1))!=NULL)
    {
      dt[0]=get(s);
      fwrite(dt,sizeof(list),1,f2);
    }
  fclose(f1);
  fclose(f2);
  printf("=>1. SUCCESS\n");
}
///////////////////////////////submenu 3
// xem het
int show_all()
{
  printf("THONG TIN DIEN THOAI\n----------------page max=%d-----------------------\n",MAX);
  FILE *f;
  if((f=fopen(OUT,"r"))==NULL)
    {
      printf("Cannot access file: %s\n",OUT);
      return 1;
    }
  list *dt;
  dt=(list *)malloc(MAX*sizeof(list));
  int num,i;
  char c;
  while((num=fread(dt,sizeof(list),MAX,f))!=0)
    {
      for(i=0;i<num;i++ )
        printf("%-15s%-8s%-10sin%-15s VND\n",dt[i].model,dt[i].memory,dt[i].size,dt[i].price);
      printf("----Press Any Key\n");
      scanf("%c",&c);
    }
  fclose(f);
  printf("=>3. SUCCESS\n");
}
///////////////////////////////////submenu 2
// doc toan phan
int show_all_2(int size)
{
  printf("THONG TIN DIEN THOAI\n----------------page max=%d-----------------------\n",MAX);
  FILE *f;
  if((f=fopen(OUT,"r"))==NULL)
    {
      printf("Cannot access file: %s\n",OUT);
      return 1;
    }
  list *dt;
  dt=(list *)malloc(size*sizeof(list));
  int num,i;
  char c;
  while((num=fread(dt,sizeof(list),size,f))!=0)
    {
      for(i=0;i<num;i++ )
        printf("%-15s|%-8s|%-10sin|%-15s VND\n",dt[i].model,dt[i].memory,dt[i].size,dt[i].price);
    }
  printf("Hien co : %d Model\n",size);
  fclose(f);
  printf("=>2. SUCCESS\n");
}// doc mot doan
int show_option(int size)
{
  FILE *f;
  int m,n,i;
  if((f=fopen(OUT,"r"))==NULL)
    {
      printf("Cannot access file: %s\n",OUT);
      return 1;
    }
  list *dt;

  printf("Vi tri bat dau? : ");scanf("%d",&m);
  printf("Vi tri ket thuc?: ");scanf("%d",&n);
  while( getchar() != '\n' );
  if (n>size) n=size;
  if(n<m) {
    printf("Loi xac dinh vi tri! \n");
    return 1;
  }
  dt=(list *)malloc((n-m+1)*sizeof(list));
  int num=fread(dt,sizeof(list),n-m+1,f);
  for(i=0;i<num;i++)
     printf("%-15s|%-8s|%-10sin|%-15s VND\n",dt[i].model,dt[i].memory,dt[i].size,dt[i].price);
  printf("Co %d sp\n",num);
  printf("=>2. SUCCESS\n");
}
//////////////////////////////submenu 4
// tim theo model
int find_model()
{
  char s[100];
  printf("Nhap model ban muon tim: ");
  gets(s);
  clock_t t1,t2;
  t1=clock();
  //tim
  FILE *f;
  if((f=fopen(OUT,"r"))==NULL)
    {
      printf("Cannot access file: %s\n",OUT);
      return 1;
    }
  list *dt;

  int kt=0,d=0;
  dt=(list *)malloc(1*sizeof(list));
  printf("Ket qua tim kiem: \n");
  while(fread(dt,sizeof(list),1,f)!=0)
    {
      if (strcmp(dt[0].model,s)==0)
        {
         printf("%-15s|%-8s|%-10sin|%-15s VND\n",dt[0].model,dt[0].memory,dt[0].size,dt[0].price);
         kt=1;
        }
      d++;
    }
  if (kt==0) printf("Khong tim thay model nao\n");
  t2=clock();
  printf("=> 4. SUCCESS: Find in %d times : %0.0f ms\n",d,(double)(t2-t1));
}
main()
{
  list *dt;
  char c,k;

  do
    {
      printf("QUAN LY THONG TIN DIEN THOAI\n----------------------------------------\n");
      printf("1. Import DB from text\n");
      printf("2. Import from DB\n");
      printf("3. Print all Nokia DB\n");
      printf("4. Find model mobile\n");
      printf("5. Exit\n");
      printf("=>Ban chon?: ");scanf("%c%*c",&c);
      int size=size_file();
      switch(c){
      case '1': get_info(dt);break;
      case '2':  {
        printf("CHON KIEU XEM\n");
        printf("1. Show all\n");
        printf("2. Show option\n");
        printf("Ban chon?: ");scanf("%c%*c",&k);
        switch(k){
        case '1': show_all_2(size);break;
        case '2': show_option(size);break;
        }
      };break;

      case '3':show_all() ;break;
      case '4': find_model();break;
      }

    }
  while(c!='5');
  printf("GOODBYE!\n");
}
