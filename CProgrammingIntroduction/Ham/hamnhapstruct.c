#incldue<stdio.h>
#define total 6;
typedef struct x
{
  char name[25];
  int old;
  float suggest[6];
} result;
result person[total];
void nhap(result a[]){
  int n,i;
  printf("Nhap so nguoi choi : ");scanf("%d%*c",&n);
  while ((n<=0)&&(n>6)) {printf("Ban nhap sai moi ban nhap lai n>0 : ");scanf("%d%*c",&n);}
  for(i=0;i<=n-1;i++)
    { printf("Nhap thong tin nguoi choi thu %d : \n",i+1);
      printf("Nhap ten nguoi choi : ");scanf("%[^\n]*c",&a[i].name);
      printf("Nhap tuoi nguoi choi : ");scanf("%d%*c",&a[i].old);
}
  printf("Danh sach nguoi choi : \n");
  printf("| STT |      Ten      |\n");
    for(i=0;i<=n-1;i++)
      printf("|%5d|%15s|",i+1,a[i].name);
}
  main()
  { result a[7];
      nhap(a);
    }
