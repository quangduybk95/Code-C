#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
  char product[30];
  int price;
}elementtype;
int struct_cmp_byproduct(const void *a,const void *b)
{
  const elementtype *ia = (const elementtype*)a;
  const elementtype *ib = (const elementtype*)b;
  return (int)strcmp(ia->product,ib->product);
}
int struct_cmp_byprice(const void *a,const void *b)
{
  const elementtype *ia = (const elementtype*)a;
  const elementtype *ib = (const elementtype*)b;

}

void print_struct_array(elementtype *array,size_t len)
{
  size_t i;
  for(i=0;i<len;i++)
    printf("%-10s - %-10d|",array[i].product,array[i].price);
  printf("\n");
}
int main()
{
  elementtype a[10];
  strcpy(a[0].product,"Computer");
  a[0].price=1000000;
  strcpy(a[1].product,"Caculator");
  a[1].price=2000000;
  strcpy(a[2].product,"Laptop");
  a[2].price=4000000;
  strcpy(a[3].product,"Mouse");
  a[3].price=3000000;
  strcpy(a[4].product,"Keyboard");
  a[4].price=6000000;
  print_struct_array(a,10);
  qsort(a,10,sizeof(elementtype *),struct_cmp_byproduct);
  print_struct_array(a,10);
}
