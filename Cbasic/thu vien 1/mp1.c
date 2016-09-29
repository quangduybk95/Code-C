#include<stdio.h>
#include<stdlib.h>
typedef struct
{
  char biethieu[30];
  int mau;
  int tancong;
  int phongthu;
  int nhanhnhen;
}s_elementtype;
#include"stack.h"
stack  monphai1,monphai2;
void docfile()
{
  make_new_stack(&monphai1);
  make_new_stack(&monphai2);
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
       s_elementtype tmp;
fscanf(f1,"%s\t%d\t%d\t%d\t%d\t",tmp.biethieu,&tmp.mau,&tmp.tancong,&tmp.nhanhnhen,&tmp.phongthu);// nhap du lieu tu file
if(tmp.mau<0||tmp.tancong<0||tmp.nhanhnhen<0||tmp.phongthu<0) {
printf("thong tin vo si %s sai\n",tmp.biethieu);}
push(&monphai1,tmp);//dua vao hang doi
     }
   for(i=0;i<n2;i++)
     {
       s_elementtype tmp;
       fscanf(f2,"%s\t%d\t%d\t%d\t%d\t",tmp.biethieu,&tmp.mau,&tmp.tancong,&tmp.nhanhnhen,&tmp.phongthu);
if(tmp.mau<0 || tmp.tancong<0||tmp.nhanhnhen<0||tmp.phongthu<0) {
printf("thong tin vo si %s sai\n",tmp.biethieu);}
push(&monphai2,tmp);
            }
   fclose(f1);
   fclose(f2);
}
/*void displayAllList(q_nodelist list)
{
  if (list.root==NULL) return;
  list.cur=list.root;
	while(list.cur!=NULL)
	{
printf("%-15s%-6d%-6d%-6d%-6d\n",list.cur->element.biethieu,list.cur->element.mau,list.cur->element.tancong,list.cur->element.nhanhnhen,list.cur->element.phongthu);
		list.cur=list.cur->next;
	}
    printf("-----------------\n");
}*/
main()
{
int a;
do{
printf("\n\t********menu********\n");
      printf("1. doc du lieu.\n");
      printf("2. tien hanh thi dau.\n");
      printf("3. xep hang vo si.\n");
      printf("4. Thoat.\n");
      printf("\tChon: "); scanf("%d",&a); while(getchar()!='\n');
      switch(a)
        {
        case 1:
          docfile();
          read_data_all(&monphai1);
          read_data_all(&monphai2);
          break;
        case 2:
          break;
        case 3:
          break;
        case 4:
         break;
               }
if(a<1 || a>4) printf("->>>moi ban chon 1 so tu 1 den 4:");
}while((a!=4));
}
