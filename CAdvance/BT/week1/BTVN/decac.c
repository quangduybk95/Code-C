#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
typedef struct data
{
  int x;
  int y;
  int count;
}elementtype;

#include"sort.h"
void randomData(elementtype a[], int n)
{
  srand(time(NULL));
  int i;
  for(i=0;i<n;i++)
    {
      a[i].x=rand()%50;
      a[i].y=rand()%50;
    }
}

void writeData(FILE *f, elementtype a[], int n)
{
  int i;
  for(i=0;i<n;i++)
    fprintf(f,"(%d,%d)\n",a[i].x,a[i].y);
}

void menu()
{
  printf("*********MENU************\n");
  printf("1. Sinh du lieu thu nghiem.\n");
  printf("2. In tap cac diem dong tuyen tinh lon nhat.\n");
  printf("3. In tap cac diem trung nhau lon nhat.\n");
  printf("4. Load lai du lieu.\n");
  printf("0. Thoat.\n");
}

int compareY (elementtype e1, elementtype e2) {
  return (e1.y-e2.y);
}

void Y_three_way(elementtype a[], int l, int r) {
  if (r <= l) return;
  int i = l-1, j = r;
  int p = l-1, q = r;
  while(1)
    {
      while (compareY(a[++i],a[r])<0);
      while (compareY(a[r],a[--j])<0) if (j == l) break;
      if (i >= j) break;
      swap(&a[i],&a[j]);
      if (compareY(a[i],a[r])==0) swap(&a[++p],&a[i]);
      if (compareY(a[j],a[r])==0) swap(&a[--q],&a[j]);
    }
  swap(&a[i],&a[r]);
  j = i - 1;
  i = i + 1;
  int k;
  for (k = l ; k <= p; k++) swap(&a[k],&a[j--]);
  for (k = r-1; k >= q; k--) swap(&a[k],&a[i++]);
  Y_three_way(a, l, j);
  Y_three_way(a, i, r);
}

main()
{
  elementtype *a;
  int n,kt;
  printf("Nhap gioi han sinh du lieu : "); scanf("%d%*c",&n);
  a=(elementtype*)malloc(n*sizeof(elementtype));
  do
   {
     menu();
     printf("Nhap lua chon : ");
     do
       {
         scanf("%d%*c",&kt);
         if(kt<0||kt>4)
           printf("Moi chon lai chuc nang : ");
       }
     while(kt<0||kt>4);
     switch(kt)
       {
       case 0:
         {
           printf("===>KET THUC CHUONG TRINH\n");
           break;
         }
         //sinh du lieu
       case 1:
         {
           int i;
           FILE *f1=fopen("data.txt","w+");
            if(f1==NULL) return 0;
           printf("\nDang sinh du lieu....\n");
           randomData(a,n);
           //        for(i=0;i<n;i++)
           //  printf("(%d,%d)\n",a[i].x,a[i].y);
           printf("===>Sinh du lieu xong.\n");
           writeData(f1,a,n);
           printf("===>Da ghi du lieu.\n");
           fclose(f1);
           break;
         }
         //dong tuyen tinh
       case 2:
         {
           elementtype b[n],c[n];
           int i,j=0,k,max=0;
           three_way(a,0,n-1);
           //    for(i=0;i<n;i++)
           //  printf("(%d,%d)\n",a[i].x,a[i].y);
           b[0].count=0; b[0].x=a[0].x;
           for(i=0;i<n;i++)
             {
               (b[j].count)++;
               if(((b[j].x)!=(a[i].x))&&(i!=0))
                 {
                   if(b[j].count>max) max=b[j].count;
                   j++; b[j].count=0;
                 }
               b[j].x=a[i].x; b[j].y=a[i].y;
             }
           ///////////////////////
               Y_three_way(a,0,n-1);
           //      for(i=0;i<n;i++)
           //  printf("(%d,%d)\n",a[i].x,a[i].y);
           c[0].count=0; c[0].y=a[0].y; j=0;
           for(i=0;i<n;i++)
             {
               (c[j].count)++;
               if(((c[j].y)!=(a[i].y))&&(i!=0))
                 {
                   if(c[j].count>max) max=c[j].count;
                   j++; c[j].count=0;
                 }
               c[j].x=a[i].x; c[j].y=a[i].y;
             }
           ///////////////////////
           j=0;
           three_way(a,0,n-1);
           printf("Dong tuyen tinh lon nhat gom %d phan tu:\n",max);
           for(i=0;i<n;i++)
             {
               if(b[i].count==max)
                 {
                   j++;
                   printf("Day thu %d:\n",j);
                   for(k=0;k<n;k++)
                     if(a[k].x==b[i].x)
                       printf("(%d,%d)\n",a[k].x,a[k].y);
                 }
             }
           Y_three_way(a,0,n-1);
           for(i=0;i<n;i++)
             {
               if(c[i].count+1==max)
                 {
                   j++;
                   printf("Day thu %d:\n",j);
                   for(k=0;k<n;k++)
                     if(a[k].y==c[i].y)
                       printf("(%d,%d)\n",a[k].x,a[k].y);
                 }
             }
               break;
         }
         //cac diem trung nhau lon nhat
       case 3:
         {
           int i,j,k,count=1,m;
           int q1,p1,p2,q2;
           three_way(a,0,n-1);
           for(i=0;i<n;i++)
             {
               k=1;
               for(j=i+1;j<n;j++)
                 {
                   if(a[i].x==a[j].x&&a[i].y==a[j].y)
                     { k++; q1=a[i].y; p1=a[i].x;}
                 }
               if(k>count) { count=k; m=i;p2=p1;q2=q1;}
             }
           if(count==1) printf("Khong co cap diem nao trung toa do.\n");
           else
             {
               printf("Tap cac diem trung nhau lon nhat gom %d phan tu:\n",count);
               for(i=m;i<=n;i++)
                 if(a[i].y==q2&&a[i].x==p2)
                   printf("(%d,%d)\n",a[i].x,a[i].y);
             }
           break;
         }
         //load lai du lieu
       case 4:
         {
           randomData(a,n);
           printf("===>Load xong du lieu.\n");
           break;
         }
       default : printf("Ban nhap sai \n");break;
       }

   }while(kt!=0);
}
