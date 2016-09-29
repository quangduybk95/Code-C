#include<stdio.h>
int tonglapphuong(int n){
  int t=0,i;
  for (i=1;i<=n;i++) t=t+i*i*i;
  return t;
  }
void uoc(int n){
  int i;
  for (i=1;i<=n/2;i++)
    if (n%i==0) printf("%d ",i);
}
int binhphuong(int n){
  int i;
  for (i=1;i<=n;i++) printf("%d ",i*i);}
int main(void)
{
  int n,y,z;
  printf("Nhap n : ");scanf("%d",&n);
  printf("tong lap p : %d\n",tonglapphuong(n));
  printf("uoc : ");uoc(n);printf("\n");
  printf("binh phuong :");binhphuong(n);printf("\n");
  return 0;
}
