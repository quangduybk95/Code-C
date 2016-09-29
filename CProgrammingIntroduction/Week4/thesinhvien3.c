/* Nguyen Duc Linh - 8C */
#include <stdio.h>
#include<string.h>
main()
{
  char  t[20], a[10], b[8], c[12], d[5], f[30], g[5], h[12] ,k[12];
puts("Nhap ma so sinh vien:");fgets(a,10,stdin) !=NULL;
  a[strlen(a)-1]='\0';
puts("Nhap vao ten lop:");fgets(b,8,stdin) !=NULL;
  b[strlen(b)-1]='\0';
puts("Nhap vao ho va ten:");fgets(t,20,stdin) !=NULL;
  t[strlen(t)-1]='\0';
puts("Nhap ngay sinh theo mau: dd/mm/yyyy");
  fgets(c,12,stdin) !=NULL;
  c[strlen(c)-1]='\0';
puts("Gioi tinh:"); fgets(d,5,stdin) !=NULL;
  d[strlen(d)-1]='\0';
puts("Nhap vao ho khau:");fgets(f,30,stdin) !=NULL;
  f[strlen(f)-1]='\0';
puts("Khoa hoc:"); fgets(g,5,stdin) !=NULL;
  g[strlen(g)-1]='\0';
puts("Thoi han su dung den ngay: dd/mm/yyyy");
  fgets(h,12,stdin) !=NULL;
  h[strlen(h)-1]='\0';
puts("Nhap ngay phat hanh theo mau: dd/mm/yyyy.");
  fgets(k,12,stdin) !=NULL;
  k[strlen(k)-1]='\0';

	printf(" ___________________________________________________________\n");
	printf("| _____                                                     |\n");
	printf("||*|DH |           DAI HOC BACH KHOA HA NOI                 |\n");
	printf("||*|BK |                                                    |\n");
	printf("||_|HN_|                THE SINH VIEN                       |\n");
	printf("||_____|                                                    |\n");
	printf("| _________                                                 |\n");
	printf("||  _^^^_  | MSSV:%-8s                Lop:%-5s        |\n",a,b);
	printf("|| | /// | | Ho ten: %-20s                   |\n",t);
	printf("|| |^ _ ^| | Ngay sinh: %-10s        %-3s               |\n",c,d);
	printf("||  +___+  | Ho khau: %-30s        |\n",f);
	printf("||   | |   | Nhom nganh: Dien, DTVT, CNTT, Toan Tin UD      |\n");
	printf("||__^___^__| Khoa hoc: %-3s      Co gia tri den: %-10s  |\n",g,h);
	printf("|                   ||||||||| ||||||||||| || | |||| ||      |\n");
	printf("|NPH:%-10s     ||||||||| ||||||||||| || | |||| ||      |\n",k);
	printf("|___________________________________________________________|\n");
}
