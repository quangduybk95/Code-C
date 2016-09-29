#include<stdio.h>
main()
{  int h;float t;
  char c;
  printf("Nhap loai xe muon gui(C,B or T) : ");scanf("%c",&c);
  printf("Nhap so gio gui : ");scanf("%d",&h);
  if (c=='C') { if (h<=2) t=0.7*h; else t=0.7*2+(h-2)*2.5/2.0;}
  else if (c=='B') { if (h<=2) t=1.5*h; else t=1.5*2+(h-2)*2.0/2;}
  else if (c=='T') { if (h<=2) t=2.5*h; else t=2.5*2+(h-2)*3.25;}
  printf("Tong so tien gui xe la : %.2f$\n",t);
}

