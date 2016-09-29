#include<stdio.h>
int sosanhmang(int a[],int b[],int n)
{
  int i,k=0,t=0;
  for(i=0;i<n;i++)
    {
      if(a[i]==b[i]) k=1;else {k=0;break;}
    }
  if(k==1) return 1;
  for(i=0;i<n;i++)
    {
      if(a[i]==b[n-1-i]) t=1;else {t=0;break;}
    }
  if(t==1) return -1;
  if((t!=1)&&(k!=1)) return 0;
}
main()
{
  int a[]={1,2,3,4,5};int b[]={1,2,3,4,5};
  int c[]={5,4,3,2,1};int d[]={1,3,4,5,6};
  printf("%d %d %d\n",sosanhmang(a,b,5),sosanhmang(a,c,5),sosanhmang(a,d,5));

}
