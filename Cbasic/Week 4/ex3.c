#include<stdio.h>
#include<math.h>
typedef struct point
{
  double x;
  double y;
} point_t;
typedef struct circle
{
  point_t center;
  double radius;
} circle_t;
  main()
  {
    point_t a;circle_t k;double m;
    printf("Nhap toa do diem : ");
    scanf("%d%*c%d%*c",&a.x,&a.y);
     printf("Nhap toa do tam : ");
    scanf("%d%*c%d%*c",&k.center.x,&k.center.y);
    printf("Nhap ban kinh : ");scanf("%d%*c",&k.radius);
    m=sqrt((a.x-k.center.x)*(a.x-k.center.x)+(a.y-k.center.y)*(a.y-k.center.y));
    if(m<=k.radius) printf("thuoc\n");
    else printf("k thuoc\n");
    printf("%f %f\n",m,k.radius);
  }
