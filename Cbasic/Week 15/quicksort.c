#include<stdio.h>
#include<stdlib.h>
typedef struct {
  int key;
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
      for(i=0;i<5;i++)
        {
          printf("Nhap key thu %d : ",i+1);
          scanf("%d%*c",&a[i].key);
        }
        for(i=0;i<5;i++)
        printf("%d ",a[i].key);
      printf("\n");
      quicksort(a,0,5);
      for(i=0;i<5;i++)
        printf("%.9d ",a[i].key);
      printf("\n");
}
