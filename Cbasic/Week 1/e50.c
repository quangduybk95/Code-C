#include<stdio.h>
#include<stdlib.h>
#define lim 0.001
float gt(int i){
  int j;
  float s=1;
  if (i==0) return s;
  for(j=1 ;j<=i ;j++ )
    s=s*j;
  return s;
}
float e(){
  float E=1;
  int i=1;
  while(1.0/i>lim){
    E=E+1.0/gt(i);
    i++;
  }
  return E;
}
float mu(float a, int x)
{
  int i;
  float s=1;
  for(i=1;i<=x;i++)
    s=s*a;
  return s;
}
main(int argc, char* argv[])
{
  int x=atof(argv[1]);
  printf("e^%d= %f\n",x,mu(e(),x));
}
