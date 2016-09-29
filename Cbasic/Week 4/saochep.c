#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 81
void copykitu(FILE *in,FILE *out)
{
  char c;
  in =fopen("in.txt","r");
  out =fopen("out1.txt","w+");
  while((c=fgetc(in))!=EOF)
      fputc(c,out);
  fclose(in);
  fclose(out);
  printf("Hoan thanh\n");
}
void copydong(FILE *in,FILE *out)
{
  char buff[MAX];
   in =fopen("in.txt","r");
  out =fopen("out2.txt","w+");
  while((fgets(buff,MAX,in))!=NULL)
    fputs(buff,out);
  fclose(in);
  fclose(out);
  printf("Hoan thanh\n");
}
void copytuychon(FILE *in,FILE *out)
{ int n;
  printf("Nhap kich thuoc tuy chon(>0) : ");
  scanf("%d%*c",&n);
 char  buff[n];
   in =fopen("in.txt","r");
  out =fopen("out3.txt","w+");
  while((fgets(buff,MAX,in))!=NULL)
    fputs(buff,out);
   fclose(in);
  fclose(out);
  printf("Hoan thanh\n");

}
main(int argc,char *argv[])
{ int ch;FILE *in,*out;
   clock_t t1,t2;
   float tg;
   time_t tx,ty;
  do
    {
      printf("MENU\n");
      printf("1.Sao chep theo ki tu \n");
      printf("2.Sao chep theo dong\n");
      printf("3.Sao chep theo block-kich thuoc tuy chon\n");
      printf("4.Ket thuc\n");
      printf("\nMoi ban nhap tuy chon(1-4) : ");
      scanf("%d%*c",&ch);
      while(ch<1||ch>4)
        {
          printf("Ban nhap sai, nhap lai lua chon(1-4): ");
                scanf("%d%*c",&ch);
        }
      switch(ch)
        {
        case 1 : time(&tx);
          copykitu(in,out);
           time(&ty);
          tg = (float)(ty-tx);
           printf("Toc do : %6lf.5 s \n",tg);break;
        case 2 : time(&tx);
          copydong(in,out);
          time(&ty);
          tg = (float)(ty-tx);
           printf("Toc do : %6lf.5 s \n",tg);break;
        case 3 :  time(&tx);
          copytuychon(in,out);
          time(&ty);
          tg = (float)(ty-tx);
           printf("Toc do : %6lf.5 s \n",tg);break;
        case 4 : printf("Ket thuc\n");break;
        }
    }
  while(ch!=4);
}
