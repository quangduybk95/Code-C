void tanggiam(int a[],int n)
{
  int i,j,tg;
  for(i=0;i<=n-1;i++)
    for(j=1;j<i;j++)
      {
        tg=a[i];
        a[i]=a[j];
        a[j]=tg;
      }
}
