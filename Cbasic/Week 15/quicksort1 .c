#include<stdio.h>
#include<stdlib.h>
typedef struct {
  int key;
  char hoten[30];
  char sdt[15];
  char mail[15];
}element;
void swap(element *a, element *b){
  element temp;
  temp=*a;
  *a=*b;
  *b=temp;
}

void quicksort(element a[],int left,int right)
{
  int pivot,i,j;
  if(left<right)
    {
      i=left;
      j=right+1;
      pivot=a[left].key;
      do{
      do i++ ; while (a[i].key<pivot);
      do j--; while(a[j].key>pivot);
      if(i<j) swap(&a[i],&a[j]);
    }
      while (i<j);
      swap(&a[left],&a[j]);
      quicksort(a,left,j-1);
      quicksort(a,j+1,right);
    }
}
main(){
      element a[10];
      int i;
      FILE *f;
      f=fopen("add.txt","r");
      for(i=0;i<5;i++)
        {
          // scanf("%d%*c",&a[i].key);
          fscanf(f,"%d%*c%[^\t]\t%[^\t]\t%[^\t]\t",&a[i].key,a[i].hoten,a[i].sdt,a[i].mail);
        }
      quicksort(a,0,5);
      for(i=0;i<5;i++)
        {
          printf("%d  %s  %s  %s\n",a[i].key,a[i].hoten,a[i].sdt,a[i].mail);
        }
}
