#include<stdio.h>
#include<stdlib.h>
typedef struct
{
  char biethieu[20];
  int mau;
  int tancong;
  int nhanhnhen;
  int phongthu;
  int STT;
} q_elementtype;
#include"queuelist.h"
    q_nodelist phai1;
    q_nodelist phai2;

void docfile()
{
  FILE *f1,*f2;
  int n1=0,n2=0,i;
      creat(&phai1);
      creat(&phai2);
  f1=fopen("monphai1.txt","r");
  f2=fopen("monphai2.txt","r");
  char buff[81];
  while(fgets(buff,81,f1)!=NULL)
    {
      n1++;
    }
   while(fgets(buff,81,f2)!=NULL)
    {
      n2++;
    }
   rewind(f1);
   rewind(f2);
   for(i=0;i<n1;i++)
     {
       q_elementtype tmp;
       fscanf(f1,"%[^\t]\t%d\t%d\t%d\t%d\t",tmp.biethieu,&tmp.mau,&tmp.tancong,&tmp.nhanhnhen,&tmp.phongthu);
       tmp.STT=(i+1);
       enQueue(&phai1,tmp);
     }
    for(i=0;i<n1;i++)
     {
       q_elementtype tmp;
       fscanf(f2,"%[^\t]\t%d\t%d\t%d\t%d\t",tmp.biethieu,&tmp.mau,&tmp.tancong,&tmp.nhanhnhen,&tmp.phongthu);
       tmp.STT=(i+1);
       enQueue(&phai2,tmp);
     }
    printf("Mon phai 1------------------\n");
    displayAllList(phai1);
    printf("Mon phai 2------------------\n");
    displayAllList(phai2);
}
void thidau()
{ int i;
  for(i=0;i<5;i++)
    { q_elementtype tmp1,tmp2;
      tmp1 = phai1.tail->element;
      tmp2 = phai2.tail->element;
      //    tmp1=deQueue(&phai1);
      //   tmp2=deQueue(&phai2);
      printf("Tran %d ---------------------: \n\n",i+1);
      printf("MP1 - %s (%d %d %d %d)\n \tVS \nMP2 - %s (%d %d %d %d) \n",tmp1.biethieu,tmp1.mau,tmp1.tancong,tmp1.nhanhnhen,tmp1.phongthu,tmp2.biethieu,tmp2.mau,tmp2.tancong,tmp2.nhanhnhen,tmp2.phongthu);
      while(tmp1.mau>0&&tmp2.mau>0)
        {
          if(tmp1.nhanhnhen>tmp2.nhanhnhen)
            {    while(tmp1.mau>0&&tmp2.mau>0)
            {
              if(tmp1.mau>0)
                { printf("%s(%d) tan cong %s(%d) mat %d mau \n",tmp1.biethieu,tmp1.mau,tmp2.biethieu,tmp2.mau,(tmp1.tancong-tmp2.phongthu));
                  tmp2.mau = tmp2.mau - (tmp1.tancong-tmp2.phongthu);}
              if(tmp2.mau>0)
                {  printf("%s(%d) tan cong %s(%d) mat %d mau\n",tmp2.biethieu,tmp2.mau,tmp1.biethieu,tmp1.mau,(tmp2.tancong-tmp1.phongthu));
              tmp1.mau = tmp1.mau - (tmp2.tancong-tmp1.phongthu);
                }  }


            }
          else   {    while(tmp1.mau>0&&tmp2.mau>0)
              {if(tmp2.mau>0)
                  {  printf("%s(%d) tan cong %s(%d) mat %d mau \n",tmp2.biethieu,tmp2.mau,tmp1.biethieu,tmp1.mau,(tmp2.tancong-tmp1.phongthu));
              tmp1.mau = tmp1.mau - (tmp2.tancong-tmp1.phongthu);
                  }
                if(tmp1.mau>0)
                  {printf("%s(%d) tan cong %s(%d) mat %d mau\n",tmp1.biethieu,tmp1.mau,tmp2.biethieu,tmp2.mau,(tmp1.tancong-tmp2.phongthu));
              tmp2.mau = tmp2.mau - (tmp1.tancong-tmp2.phongthu);
                  }}

            }
        }
                if(tmp1.mau<=0) {printf("MP2 - %s thang\n",tmp2.biethieu);
            deQueue(&phai1);
            phai2.tail->element=tmp2;
          }
          else
            { printf("MP1 - %s thang \n",tmp1.biethieu);
              deQueue(&phai2);
              phai1.tail->element=tmp1;
            }

}
}

main()
  {
    int lc;
    do
      {
        printf("MENU\n");
        printf("1. Load du lieu\n");
        printf("2. Loi dai thi dau\n");
        printf("3. Xep hang vo sy\n");
        printf("4. Thoat chuong trinh\n\n");
        printf("Nhap lua chon cua ban : ");
        scanf("%d%*c",&lc);
        switch(lc)
          {
          case 1 : docfile();break;
          case 2 : thidau();break;
          case 4 : printf("Thoat\n");break;
          default: printf("Ban da nhap sai yeu cau \n");
          }
      }
        while(lc!=4);

  }
