#include <stdio.h>
#include <stdlib.h>

struct node
{
  char so;
  struct node *lk;
};

struct node *push(struct node *p,char value)
{
  struct node *tmp;
  tmp=(struct node*)malloc(sizeof(struct node));
  if(tmp==NULL)
    {
      printf("Loi cap phat bo nho!\n"); exit(0);
    }
  tmp->so=value;
  tmp->lk=p;
  p=tmp;
  return(p);
}

struct node *pop(struct node *p,char *value)
{
  struct node *tmp;
  *value=p->so;
  tmp=p;
  p=p->lk;
  free(tmp);
  return(p);
}
struct node *sh1,*sh2,*kq;
int data=0; // kiem tra co ton tai du lieu trong ngan xep.
int dem1,dem2; //so sanh do dai 2 so lon.\n
int dau1,dau2; //kiem tra dau.
int kt_change; //kiem tra viec hoan doi vi tri.
int tong(char d);
int hieu(char d);
int nhap();

int main()
{
  int kt=1,a;
  char c;
  sh1=NULL; sh2=NULL; kq=NULL;
  do
    {
      printf("\n\t~Tinh toan so vo cung lon~\n");
      printf("1. Nhap 2 so lon.\n");
      printf("2. Tinh tong.\n");
      printf("3. Tinh hieu.\n");
      printf("4. Thoat.\n");
      printf("\tChon: "); scanf("%d",&a); while(getchar()!='\n');
      switch(a)
        {
        case 1:
          nhap();
          break;
        case 2:
          tong('+');
          break;
        case 3:
          hieu('+');
          break;
        case 4:
          kt=0; break;
        default:
          kt=0; break;
        }
    }while(kt);
}
int nhap()
{
  char c;
  struct node *tmp;
  dem1=0;dem2=0;
  dau1=0;dau2=0;
  kt_change=0;
  printf("Nhap so thu nhat: ");
  while(c=getchar())
    {
      if(c=='-') {dau1=-1; continue;}
      if(c!='\n') sh1=push(sh1,c);
      if(c=='\n') break; dem1++;
    }

  printf("Nhap so thu hai: ");
  while(c=getchar())
    {
      if(c=='-') {dau2=-1; continue;}
      if(c!='\n') sh2=push(sh2,c);
      if(c=='\n') break; dem2++;
    }
  if(dem2>dem1)
    {
      tmp=sh1; sh1=sh2; sh2=tmp; kt_change=1;
    }
  data=1;
}

int tong(char d)
{
  char c1,c2,c;
  int kt;
  if(data==1)
    {
      if(dau1==0 && dau2==0)
        {
      while(sh1!=NULL || sh2!=NULL)
        {
          if(sh1!=NULL)
            sh1=pop(sh1,&c1);
          else c1=48;
          if(sh2!=NULL)
            sh2=pop(sh2,&c2);
          else c2=48;
          c=c1+c2;
          if(kt==1){c=c+1; kt=0;}
          if(c>=106)
            {
              kt=1; c=(c-57)-1;
            }
          else
            {
              c=c-48;
            }
          kq=push(kq,c);
          if(sh1==NULL && sh2==NULL && kt==1)
            {
              kq=push(kq,'1');
            }
        }
      printf("_Ket qua can tim la: %c",d);
      while(kq!=NULL)
        {
          kq=pop(kq,&c);
          printf("%c",c);
        }
      printf("\n");
        }
      else if(dau1==-1 && dau2==0 && kt_change==0) {dau1=0;hieu('-');}
      else if(dau1==-1 && dau2==0 && kt_change==1) {dau1=0;hieu('+');}
      else if(dau1==0 && dau2==-1 && kt_change==0) {dau2=0; hieu('+');}
      else if(dau1==0 && dau2==-1 && kt_change==1) {dau2=0; hieu('-');}
    }
  else printf("_Chon 1 de nhap lai du lieu!\n");
  data=0;
}
int hieu(char d)
{
  char c1,c2,c;
  int kt;
  if(data==1)
    {
      if(dau1==0 && dau2==0 && kt_change==1) {kt_change=0;hieu('-'); return 1;}
      if(dau1==-1 && dau2==0) {dau1=0; tong('-');}
      else if(dau1==0 && dau2==-1) {dau2=0; tong('+');}
      else if(dau1==0 && dau2==0 && kt_change==1) {hieu('-');}
      else
        {
      while(sh1!=NULL || sh2!=NULL)
        {
          c=0;
          if(sh1!=NULL)
            sh1=pop(sh1,&c1);
          else c1=48;
          if(sh2!=NULL)
            sh2=pop(sh2,&c2);
          else c2=48;
          if(kt==-1) {c=c-1; kt=0;}
          if(c1==c2) {c=c+c1-c2+48;}
          if(c1>c2) c=c+c1-c2+48;
          if(c1<c2) {c=c+c1+10-c2+48; kt=-1;}
          if(c==47 && sh1==NULL) {c=48; d='-';}
          else if(c==47) {c=57; kt=-1;}
          kq=push(kq,c);
        }
      printf("_Ket qua can tim la: %c",d);
      while(kq!=NULL)
        {
          kq=pop(kq,&c);
          printf("%c",c);
        }
      printf("\n");}
    }
  else printf("_Chon 1 de nhap lai du lieu!\n");
  data=0;
}
