#include<stdio.h>
#include<math.h>
int nguyento(int a){int i;
  for (i=1;i<=(sqrt(a));i++)
    { if (a%i==0) {return 0;} } return 1;
}
int main(void)
{ int n=0,i=0;printf("Nhap a : ");scanf("%d",&n);
  for (i=2;i<=n;i++) {if (nguyento(i)) printf("%d",i);}
  return 0;
}
