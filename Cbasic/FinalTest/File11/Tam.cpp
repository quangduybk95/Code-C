#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;
int n,a[100][100],x[100],dinhdau;
void nhap()
{   int i,j;
   fstream f("De_11.txt",ios::in);
   f>>n;
   for(i=1;i<=n;i++)
   for(j=1;j<=n;j++)
   f>>a[i][j];
}
void dfs(int i)
{  x[i]=1;
  for(int j=1;j<=n;j++)
  if(x[j]==0&&a[i][j]==1)
  dfs(j);
}
int lienthong()
{  int i;
  for(i=1;i<=n;i++) x[i]=0;
  dfs(1);
  for(i=1;i<=n;i++)
  if(x[i]==0)  return 0;
  return 1;
}
int kt()
{  int i,j,dem1=0,dem2=0,deg1,deg2;
   for(i=1;i<=n;i++)
   {  deg1=0;  deg2=0;
   for(j=1;j<=n;j++)
   {  deg1+=a[i][j];  deg2+=a[j][i];  }
   if((deg1-deg2)==1) { dinhdau=i; dem1++;  }
 else  if((deg1-deg2)==-1)  dem2++;
   else if((deg1-deg2)!=0)   return 0;
   }
 if(dem1==1&&dem2==1)  return 1;
}
void euler(int ce[])
{   int st[100],t=1,i,j,k,h;
    st[t]=dinhdau;  k=0;
    while(t>0)
    {   h=st[t];  j=0;
    for(i=1;i<=n;i++)
    if(a[h][i]==1)
    {  t++;
    st[t]=i;
    j=i;
    a[h][i]=0;  a[i][h]=0;
    break;
    }
    if(j==0)
    {  k++;
    ce[k]=h;
    t--;
    }
  }
  for(i=k;i>1;i--)
  cout<<ce[i]<<"  ";
  cout<<ce[1];
}
main()
{  int ce[100];
   nhap();
   if(lienthong()==1&&kt()==1)   euler(ce);
   else cout<<"khong co duong di euler";
   getch();
}
