#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 2000000
void exch(int a[],int x,int y)
{
  int tmp=a[x];
  a[x]=a[y];
  a[y]=tmp;
}

void sort(int a[], int l, int r) {
  if (r <= l) return;
  int i = l-1, j = r;
  int p = l-1, q = r;
  while(1)
    {
      while (a[++i] < a[r]);
      while (a[r] < a[--j]) if (j == l) break;
      if (i >= j) break;
      exch(a, i, j);
      if (a[i]==a[r]) exch(a, ++p, i);
      if (a[j]==a[r]) exch(a, --q, j);
    }
  exch(a, i, r);
  j = i - 1;
  i = i + 1;
  int k;
  for (k = l ; k <= p; k++) exch(a, k, j--);
  for (k = r-1; k >= q; k--) exch(a, k, i++);
  sort(a, l, j);
  sort(a, i, r);
}
void main()
{
  int dem=0;
  srand(time(NULL));
  int a[MAX];
  int i,j;
  clock_t t1,t2;
  for(i=0;i<MAX;i++)
      a[i]=rand()%10000;
  t1=clock();
  sort(a,0,MAX-1);
  t2=clock();
  float t = (float)(t2-t1)/CLOCKS_PER_SEC;
  printf("%.5f \n",t);
}
