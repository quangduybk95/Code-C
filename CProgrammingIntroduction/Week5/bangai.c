#include<stdio.h>
main()
{
char s1[5],s2[5];
int t1,t2,c1,c2,pt1,pt2,pc1,pc2,p1,p2,c;
printf("Nhap vao ten co gai thu nhat(ten) :\t");gets(s1);
printf("Nhap vao ten co gai thu hai(ten) :\t");gets(s2);
printf("Nhap vao tuoi co gai thu nhat :\t");scanf("%d",&t1);
printf("Nhap vao chieu cao co gai thu nhat(cm) :\t");scanf("%d",&c1);
printf("Nhap vao tuoi co gai thu hai :\t");scanf("%d",&t2);
printf("Nhap vao chieu cao co gai thu hai(cm) :\t");scanf("%d",&c2);
printf("Nhap chieu cao cua ban (cm) :\t");scanf("%d",&c);
pt1 = t1<=16 ? 0 : (((16<t1) & (t1<21)) ? 5 : 2);
pt2 = t2<=16 ? 0 : (((16<t2) & (t2<21)) ? 5 : 2);
pc1 = c1>=c ? -1 : ((c-c1)>30 ? -2 : +3);
pc2 = c2>=c ? -1 : ((c-c2)>30 ? -2 : +3);
printf("Yahoo Chat log\t\n");
printf("Yahoo(1)\t\n");
printf("You\t: \tHi %-5s\t\n",s1);
printf("%-5s\t: \tHi\t\n",s1);
printf("You\t: \tHow old are you? \n");
printf("%-5s\t: \t%d years old\n",s1,t1);
printf("You\t: \tHow tall are you?\n");
printf("%-5s\t: \t%dcm\t\t\n",s1,c1);
printf("\n");
printf("Yahoo(2)\n");
printf("You\t: \tHi %-5s\n",s2);
printf("%-5s\t: \tHi\n",s2);
printf("You\t: \tHow old are you?\n");
printf("%-5s\t: \t%d years old\n",s2,t2);
printf("You\t: \tHow tall are you? \n");
printf("%-5s\t: \t%dcm\n",s2,c2);
printf("\n");
p1 = pt1 + pc1;
p2 = pt2 + pc2;
 printf("Diem cua %-5s la : %d\n",s1,p1);
  printf("Diem cua %-5s la : %d\n",s2,p2);

(p1>p2) ? printf("%5s la nguoi phu hop voi ban\n",s1) : (p1<p2 ? printf("%5s la nguoi phu hop voi ban\n",s2) : printf("Ban nen chon 1 nguoi thu 7 , 1 nguoi chu nhat\n"));
}

