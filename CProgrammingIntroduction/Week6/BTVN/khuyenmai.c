#include<stdio.h>
main()
{
 int n1,n2,g1,g2,total,km;
printf("Sieu thi topcare sieu khuyen mai cho khach hang mua cac mat hang cua apple\n");
printf("Nhap so ipod muon mua :");scanf("%d",&n1);
printf("Nhap so ipad muon mua :");scanf("%d",&n2);
g1 = 148*n1;
g2 = 288*n2;
total = g1 + g2;
 if (((n1>3) && (n2>=2))||(total>1020)) (km=total*10/100);else (km=0);
printf(" _______________________\n");
printf("|\t  Bill\t\t|\n");
printf("|_______________________|\n");
printf("|Type \t Qty \t Price \t|\n");
printf("|Ipod \t %d \t %d \t|\n",n1,g1);
printf("|Ipad \t %d \t %d \t|\n",n2,g2);
printf("|Total \t\t %d\t|\n",total);
printf("|Discount  \t  %d\t|\n",km);
printf("|Pay \t\t %d\t|\n",total-km);
printf("|_______________________|\n");
}
