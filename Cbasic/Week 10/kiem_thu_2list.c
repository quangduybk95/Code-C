#include <stdio.h>
#include <stdlib.h>
#define MAX 100;
typedef struct elementtype
{
  int key;
  char name[30];
}elementtype;
elementtype list1[100],list2[100];
int N,M;
int read_data()
{
  char s[100]; int dem1,dem2,i;
  FILE *fin1,*fin2;
  fin1=fopen("list1.txt","r");
  fin2=fopen("list2.txt","r");
  if(fin1==NULL || fin2==NULL)
    {printf("Loi mo tep.\n"); return 1;}
  while(fgets(s,100,fin1)!=NULL)
    {dem1++;}
  rewind(fin1);
  while(fgets(s,100,fin2)!=NULL)
    {dem1++;}
  rewind(fin2);
  for(i=0;i<dem1;i++)
    {
      fscanf(fin1,"%d\t%[^\n]",&list1[i].key,list1[i].name);
      fgetc(fin1);
    }
  for(i=0;i<12;i++)
    {
      fscanf(fin2,"%d\t%[^\n]",&list2[i].key,list2[i].name);
      fgetc(fin2);
    }
  N=dem1; M=12;

}
void verify(elementtype l1[], elementtype l2[],int n,int m)
{
  int i,j,k;
  i=0; j=0;
  do
    {
      if(i>=n&&j>=m) break;
      if(i>=n)
        {
          printf("Phan tu %d chi co trong list 2.\n",list2[j].key);
          j++;
        }
      if(j>=m)
        {printf("Phan tu %d chi co trong list 1.\n",list1[i].key); i++;}
      if(list1[i].key>list2[j].key)
        {
          printf("Phan tu %d chi co trong list 2.\n",list2[j].key);
          j++;
        }
      if(list1[i].key<list2[j].key)
        {
          printf("Phan tu %d chi co trong list 1.\n",list1[i].key);
          i++;continue;
        }
      if(list1[i].key==list2[j].key)
        {
          printf("Phan tu %d co trong ca 2 list.\n",list1[i].key);
          k=list1[i].key;
          while(list1[i].key==k) i++;
          while(list2[j].key==k) j++;
        }
    }while(1);
}

int main()
{
  read_data();
  verify(list1,list2,N,M);
}
