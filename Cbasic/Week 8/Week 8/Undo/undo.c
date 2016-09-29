#include<stdio.h>
#include<stdlib.h>
#include"stack2.h"
main()
{ char lc;eltype x,m,p;int i;
  stacktype a[2];
  initialize(&a[0]);
  initialize(&a[1]);
  do
    {
      printf("\nMEUNU\n");
      printf("1.Them 1 so nguyen vao ngan xep\n");
      printf("2.Xem dinh\n");
      printf("3.Lay ra 1 so nguyen tu ngan xep\n");
      printf("4.Undo\n");
      printf("5.In toan bo day\n");
      printf("6.Exit\n\n");
      printf("Moi ban nhap lua chon : ");
      lc=getchar();
      while(getchar()!='\n');
      switch(lc)
        {
        case '1' : printf("Nhap so muon them : ");
          scanf("%d%*c",&x.gt);
          x.kt=1;
          push(x,&a[0]);
          push(x,&a[1]);
          printf("Thanh cong\n");
          break;
        case '2' : printf("Dinh : %d\n",a[0].storage[a[0].top-1].gt);break;
        case '3' : p=pop(&a[0]);
          x.gt=p.gt;
          x.kt=0;
          push(x,&a[1]);
          printf("Thanh cong\n");
          break;
        case '4' :
          if(a[1].storage[a[1].top-1].kt==1)
            {m=pop(&a[0]);
              m=pop(&a[1]);
            }
          if(a[1].storage[a[1].top-1].kt==0)
            {
              push(a[1].storage[a[1].top-1],&a[0]);
              m=pop(&a[1]);
            }
          printf("Thanh cong\n");
          break;
        case '5' : for(i=a[0].top-1;i>=0;i--)
            printf("%d ",a[0].storage[i].gt);
          printf("\n");break;
        case '6' : printf("EXIT\n");break;
        default : printf("Ban nhap sai, moi ban nhap lai \n");break;
        }
    }
  while(lc!='6');
}
