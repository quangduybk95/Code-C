#include<stdio.h>
#include<string.h>
typedef struct{
  char string[100];
} list;
list ds[10000000];

void insertionsort(list a[],int n)
{
	int i, j;
	list next;
	for (i=0; i<n; i++) {
		next= a[i];
		for (j=i-1;j>=0 && strcmp(next.string, a[j].string) < 0;j--)
			a[j+1] = a[j];
		a[j+1] = next;
	}
}

main()
{
  int n,i;
  printf("Nhap n: ");scanf("%d%*c",&n);
  for(i = 0 ;i < n ;i++ )
    {
      printf("Chuoi %d: ",i+1);
      gets(ds[i].string);
    }
  insertionsort(ds,n);
  printf("Sau khi sap xep: \n");
  for(i = 0 ;i < n ;i++ )
    {
      printf("\t%s\n",ds[i].string);
    }

}
