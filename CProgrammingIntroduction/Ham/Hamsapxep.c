void sapxep(int a[],int n)
{int i,j,tg;
for(i=0;i<=n-1;i++)
    for(j=i+1;j<=n-1;j++)
      if (a[i].grade<=a[j].grade)
        {
          g=a[i];
          a[i]=a[j];
          a[j]=g;
        }
