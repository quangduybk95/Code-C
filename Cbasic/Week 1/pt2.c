#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void pt2(float a,float b,float c)
{
  float delta;delta=b*b-4*a*c;
  if(delta<0) printf("pt vo nghiem\n");
    else if(delta==0) printf("Pt co nghiem kep x = %-5.2f\n",-b/2/a);
    else printf("pt co 2 nghiem : x1= %-5.2f ; x2= %-5.2f\n",((sqrt(delta)-b)/2/a),((-sqrt(delta)-b)/2/a));
}
main(int argc,char *argv[])
{ int a=atof(argv[1]);
  int b=atof(argv[2]);
  int c=atof(argv[3]);
  pt2(a,b,c);
  printf("\n");
}
