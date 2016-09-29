#include<stdio.h>
main()
{
  float g;
  printf("Nhap goc cua la ban(0-360) : ");scanf(".2f",&g);
  if (g==360.0) printf("East\n"); else if (g>270.0) printf("South east\n");
  else if (g==270.0) printf("South\n");else if (g>180.0) printf("South west\n");
  else if (g==180.0) printf("West\n");else if (g>90.0) printf("North West\n");
  else if (g==90.0)  printf("North\n");else if (g>0.0) printf("North East\n");
  else if (g==0.0)   printf("East\n");
}
