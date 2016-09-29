#include<stdio.h>
#include<math.h>
main()
{
  int a[20],i,n,min=0,sum=0,t;
  float x,b[20];
  printf("Nhap so phan tu : ");scanf("%d%*c",&n);
  for(i=0;i<=n-1;i++)
    {
      printf("Nhap phan tu thu %d : ",i+1);
      scanf("%d%*c",&a[i]);
    }
  for(i=0;i<=n-1;i++)
      sum+=a[i];
  x=sum/n;
 for(i=0;i<=n-1;i++)
      b[i]=abs(x-a[i]);
 t=b[0];
  for(i=0;i<n-1;i++)
    {
      if(b[i]<=t) {t=b[i];min=i-1;}
    }
  printf("%-5d %-5.2f %-5d\n",sum,x,a[min]);
}
