#include<stdio.h>
#include<time.h>
#include<string.h>
#define SIZE 10000
#define MAX 10000
typedef struct {
  int key;
  int content[50000];
} bigObj;
int sosanh(bigObj a, bigObj b){
  if (a.key<b.key) return -1;
  if (a.key>b.key) return 1;
  return 0;
}
void swap(bigObj *a,bigObj *b)
{
  bigObj tmp=*a;
  *a=*b;
  *b=tmp;
}
void quicksort(bigObj a[], int left, int right)
{

  int i,j;
  bigObj key;
  if(left<right)
    {
      key=a[(left+right)/2];
      i=left-1;j=right+1;
      do
        {
          do i++; while(sosanh(a[i],key)==-1);
          do j--; while (sosanh(a[j],key)==1);
          if (i<j) swap(&a[i],&a[j]);
        }
      while(i<j);
      swap(&a[left],&a[j]);
      quicksort(a,left,j);
      quicksort(a,j+1,right);
    }
 }
void selectionsort(bigObj a[],int m)
{
  int i, j, min;
  bigObj tmp;
  for (i = 0; i < m-1; i++)
	{
      min = i;
      for (j = i+1; j <=m-1 ; j++)
        if ( a[j].key < a[min].key)
          min = j;
      tmp= a[i];
      a[i]= a[min];
      a[min] = tmp;
	}
}
main()
{
  srand(time(NULL));
  int i,j;
  bigObj *a,*b;
  a=(bigObj*)malloc(MAX*sizeof(bigObj));
   b=(bigObj*)malloc(MAX*sizeof(bigObj));
  for(i=0;i<MAX;i++)
    {
      a[i].key=rand()%5000;
      for(j=0;j<SIZE;j++)
           {
             a[i].content[j]=rand()%5000;
          }
        b[i]=a[i];
        if(i<100) printf("%d\n",a[i].key);
    }
   time_t t1,t2;
         time(&t1);
        quicksort(a,0,MAX-1);
        time(&t2);
        int qstime = (int)(t2-t1);
        time(&t1);
        selectionsort(b,MAX-1);
        time(&t2);
        int seletime = (int)(t2-t1);
        free(a);
        free(b);
        printf("=>Quicksort: %d s \n Selectionsort: %d s\n",qstime,seletime);
}
