#include<stdio.h>
main()
{
  int n1,n2,n3,t1,t2,t3,t,max1,max2,max3,max4;
  printf("Nhap so tu lanh ban ra : ");scanf("%d",&n1);
  printf("Nhap so tivi LCD Sony ban ra : ");scanf("%d",&n2);
  printf("Nhap so Laptop HP ban ra : ");scanf("%d",&n3);
  t1 = 8*n1;
  t2= 15*n2;
  t3= 12*n3; t = t1 + t2 + t3;
  printf("Doanh so tu lanh : \t\t%d trieu dong\n",t1);
  printf("Doanh so tivi LCD Sony : \t%d trieu dong\n",t2);
  printf("Doanh so Laptop HP : \t\t%d trieu dong\n",t3);
  printf("Tong doanh so : \t\t%d trieu dong \n",t);
  if (n1>n2) max1=n1;else  max1= n2;
   if (n3>max1) max2=n3;else  max2= max1;
  if (t1>t2) max3=n1;else  max3= n2;
   if (t3>max1) max4=n3;else  max4= max3;
   if (max2==n3) printf("Mat hang ban chay nhat la Laptop HP\n");else if (max2==n2)  printf("Mat hang ban chay nhat la tivi LCD Sony\n");else  printf("Mat hang ban chay nhat la tu lanh\n");
if (max4==t3) printf("Mat hang doanh thu lon nhat la Laptop HP\n");else if (max4==t2) printf("Mat hang doanh thu lon nhat la tivi LCD Sony\n");else  printf("Mat hang doanh thu lon nhat la tu lanh\n");
}
