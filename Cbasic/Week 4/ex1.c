#include<stdio.h>
#include<stdlib.h>
main()
{
  int i,n,*p;
  printf("nhap n : ");scanf("%d%*c",&n);
  p=(int*)malloc(n*sizeof(int));
  if(p==NULL)
    {
      printf("loi\n");return 1;
    }
      printf("Please enter the numbers : \n");
      for(i=0;i<n;i++)
        scanf("%d%*c",&p[i]);
      printf("the numbers : \n");
      for(i=n-1;i>=0;i--)
        printf("%d ",p[i]);
      printf("\n");
      printf("%p \n",p);
      free(p);
      return 0;

}
