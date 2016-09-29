#include<stdio.h>
void docfile()
{
   creat(&monphai1);
   creat(&monphai2);
  FILE *f1,*f2;
  char buff[81];
  if((f1=fopen("Monphai1.txt","r"))==NULL)
    printf("Khong tim dc file\n");
  if((f2=fopen("Monphai2.txt","r"))==NULL)
    printf("khong tim thaY file");
   int n1=0,n2=0;
   while(fgets(buff,81,f1)!=NULL)
     n1++;// dem so dong
   while(fgets(buff,81,f2)!=NULL)
     n2++;
rewind(f1);//dua con tro ve dau file
   rewind(f2);
   int i;
   for(i=0;i<n1;i++)
     {
       q_elementtype tmp;
fscanf(f1,"%s\t%d\t%d\t%d\t%d\t",tmp.biethieu,&tmp.mau,&tmp.tancong,&tmp.nhanhnhen,&tmp.phongthu);// nhap du lieu tu file
if(tmp.mau<0||tmp.tancong<0||tmp.nhanhnhen<0||tmp.phongthu<0) {
printf("thong tin vo si %s sai\n",tmp.biethieu);}
enQueue(&monphai1,tmp);//dua vao hang doi
     }
   for(i=0;i<n2;i++)
     {
       q_elementtype tmp;
       fscanf(f2,"%s\t%d\t%d\t%d\t%d\t",tmp.biethieu,&tmp.mau,&tmp.tancong,&tmp.nhanhnhen,&tmp.phongthu);
if(tmp.mau<0 || tmp.tancong<0||tmp.nhanhnhen<0||tmp.phongthu<0) {
printf("thong tin vo si %s sai\n",tmp.biethieu);}
enQueue(&monphai2,tmp);
            }
   fclose(f1);
   fclose(f2);
}

main()
{
  int lc;
  do
    {
      printf("###################\n");
      printf("MENU\n");
      printf("1.\n");
      printf("2.\n");
      printf("3.\n");
      printf("4.\n");
      printf("\n");
      printf("Moi ban nhap lua chon : ");
      scanf("%d%*c",&lc);
      switch(lc)
        {
        case 1 :

        }

    }
  while(lc!=);
}
