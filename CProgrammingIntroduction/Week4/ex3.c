#include <stdio.h>
main()
{
#define PI 3.14
  float r,c,s,v;
  printf("nhap ban kinh :\n"); scanf("%f", &r);
  c=2*PI*r;
  s=2*PI*r*r;
  v=4.0*PI*r*r*r/3.0;
  printf("chu vi : %f \n",c);
  printf("dien tich: %f \n",s);
  printf("the tich: %f \n",v);
}
