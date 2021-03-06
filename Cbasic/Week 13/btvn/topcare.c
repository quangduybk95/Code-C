#include "BST_Topcare.h"

treetype tree;
void in(treetype tr);
void find(treetype tr);
int main()
{
  elementtype tmp; treetype k;
  int n=0,i,a,kt=1;
  double tp,dt,mm;
  char s[81];
  FILE *fin;
  fin=fopen("inf_khach.txt","r");
  if(fin==NULL)
    {
      printf("Loi mo tep.\n"); return 0;
    }
  while(fgets(s,100,fin)!=NULL)
    {
      n++;
    }
  rewind(fin);
  for(i=0;i<n;i++)
    {
      fscanf(fin,"%s %[^-]-",tmp.mskh,tmp.name);
      fscanf(fin,"%lf%lf%lf",&tp,&dt,&mm);
      k=search(tmp,tree);
      if(k!=NULL)
        {
          k->element.price=k->element.price+tp+dt+mm;
          if(tp!=0) k->element.tp++;
          if(dt!=0) k->element.dt++;
          if(mm!=0) k->element.mm++;
        }
      else
        {
          tmp.price=tp+dt+mm;
          if(tp!=0) tmp.tp=1;
          if(dt!=0) tmp.dt=1;
          if(mm!=0) tmp.mm=1;
          if(tp==0) tmp.tp=0;
          if(dt==0) tmp.dt=0;
          if(mm==0) tmp.mm=0;
          insert(&tree,tmp);
        }
    }
  //
  do
    {
      printf("\n\tMENU\n");
      printf("1. Display\n");
      printf("2. Find\n");
      printf("3. ADD\n");
      printf("4. Quit\n");
      printf("\tChon: "); scanf("%d",&a); while(getchar()!='\n');
      switch(a)
        {
        case 1:
          in(tree);
          break;
        case 2:
          find(tree);
          break;
        case 3:
          printf("Nhap ten khach hang : ");
          gets(tmp.name);
          printf("Nhap mskh : ");
          gets(tmp.mskh);
          printf("Nhap TP : ");
          scanf("%f%*c",&tp);
           printf("Nhap DT : ");
          scanf("%f%*c",&dt);
           printf("Nhap MM : ");
          scanf("%f%*c",&mm);
          insert(&tree,tmp);
          printf("Success\n");
          break;
        case 4:
          kt=0; break;
        default:
          kt=0; break;
        }
    }while(kt);
}
void in(treetype tr)
{
  if(tr!=NULL)
    {
      in(tr->left);
      printf("MSKH: %s\t\tTen: %s\n",tr->element.mskh,tr->element.name);
      printf("Tien:%.0lf\t\tTP=%d\tDT=%d\tMM=%d\n",tr->element.price,tr->element.tp,tr->element.dt,tr->element.mm);
      printf("--------------------------\n");
      in(tr->right);
    }
}
void find(treetype tr)
{
  elementtype tmp;
  treetype k;
  printf("Nhap ten can tim kiem: ");
  scanf("%[^\n]%*c",tmp.name);
  k=search_2(tmp,tree);
  if(k!=NULL)
    {
      printf("Khach hang: %s - %s\n",k->element.mskh,k->element.name);
      printf("Tien:%.0lf\t\tTP=%d\tDT=%d\tMM=%d\n",k->element.price,k->element.tp,k->element.dt,k->element.mm);
      printf("--------------------------\n");
    }
  else
    {
      printf("Khong co khach hang nay!\n");
    }
}
