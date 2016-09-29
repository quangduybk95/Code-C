#include<stdio.h>
#include<stdlib.h>
#include<string.h>
///////////////// hangso
#define IN "data.txt"
////////////////
typedef struct
{
  int num;
} elementtype;

#include " "
////////////////////////// cac ham them




//////////////////////// chuong trinh chinh
FILE *fr,*fw;
main()
{
  char kt;
  // khai bao ds
  queue list;
  // tao ds NULL
  createQueue(&list);
  do
    {
      printf("test\nMENU:\n");
      printf("0. EXIT\n");
      printf("1. INPUT\n");
      printf("2. deQueue\n");
      printf("3. DISPLAY\n");
      printf("4. DELETE\n");
      printf("Ban chon?: ");
      scanf("%c%*c",&kt);
      switch(kt )
        {
        case '1':
          {
            fr = fopen(IN,"r");
            elementtype e;

            while(!feof(fr))
              {
                int d = fscanf("%s\t%s\t%*c",e.num,e.char);
                if (d == )
                  {
                    // cho vao trong list
                  }
              }
            fclose(fr);
          }
          break;
        case '2':{

        } break;
        case '3':{

        }break;
        case '4':
          {
            fr = fopen(OUT,"w");
            elementtype e;
            // duyet ds va in
            fclose(fr);
          }break;
        }
    }
  while(kt != '0');
  // xoa list
}
