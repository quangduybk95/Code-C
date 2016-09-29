#include<stdio.h>
main()
{
  int to1,to2,to3,to,d=0;
	printf("Nhap to ve so 1: ");scanf("%d",&to1);
	printf("Nhap to ve so 2: ");scanf("%d",&to2);
	printf("Nhap to ve so 3: ");scanf("%d",&to2);
	srand ( time ( NULL ));
	to = 1 + rand () % 10000000;
	printf("Giai dac biet  : %d\n",to);
	if ((to==to1)||(to==to2)||(to==to3)) printf("Ban da trung giai dac biet 1 ty USD\n"); else d++;
	if ((to%1000000==to1%1000000)||(to%1000000==to2%1000000)||(to%1000000==to3%1000000)) printf("Ban da trung giai Nhat vs bo so: %d 100 trieu USD\nx",to%1000000); else d++;
	if ((to%100000==to1%100000)||(to%100000==to2%100000)||(to%100000==to3%100000)) printf("Ban da trung giai Nhi vs bo so: %d 50 trieu USD\n",to%100000); else d++;
																				     if ((to%10000==to1%10000)||(to%10000==to2%10000)||(to%10000==to3%10000)) printf("Ban da trung giai Ba vs bo so: %d\n",to%10000); else d++;
	if ((to%1000==to1%1000)||(to%1000==to2%1000)||(to%1000==to3%1000)) printf("Ban da trung giai Tu vs bo so: %d\n",to%1000);else d++;
	if ((to%100==to1%100)||(to%100==to2%100)||(to%100==to3%100)) printf("Ban da trung giai Nam vs bo so: %d\n",to%100);else d++;
	if (d==6) printf("Chuc ban may man lan sau\n");
}
