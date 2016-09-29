#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct danhba
{
  char name[20];
  char phone[15];
} elementtype;

typedef struct node node;
typedef struct node
{
  elementtype element;
  node *next;
} node;

node *root=NULL, *cur=NULL;
node *prev=NULL;

node *makeNode (elementtype element)
{
  node *tmp;
  tmp=(node*)malloc(sizeof(node));
  tmp->element=element;
  tmp->next=NULL;
  return tmp;
}

void insert (node *new)
{
  if (root == NULL)
    {
      root=new;
      cur=new;
    }
  else
    { new->next=cur->next;
      cur->next=new;
      cur=cur->next;
    }
}

void printDaTa (elementtype element)
{
  printf("%-20s %-15s\n",element.name,element.phone);
}
void display ()
{
  node *tmp=root;
  while (tmp != NULL)
    {
      printDaTa(tmp->element);
      tmp=tmp->next;
    }
}
void insertbefore(node *new)
{
  if(root=NULL)
    {
      root=new;
      cur=new;
    }
  else
    {
      prev->next=new;
      new->next=cur;
      if(cur==root)
        root=new;
      cur=new;
    }
    }
elementtype read_data()
{
	elementtype tt;
	printf("Nhap name: ");gets(tt.name);
	printf("Nhap Tel : ");gets(tt.phone);
	return tt;
}
void delete(node *del)
{
  if(del==root)
    {
      root=del->next;
      free(del);
    }
  else
  {
    prev->next=cur->next;
    free(cur);
    cur=prev->next;
  }
}
void tofree()
{
  node *tofree;
  tofree=root;
  while(free!=NULL)
    {
      root=root->next;
      free(tofree);
      tofree=root;
    }
}
main()
{
  int n,i;
  printf("Nhap so nguoi muon them: "); scanf("%d%*c",&n);

  elementtype element[n],x;
  node *tmp,*del;
  for(i=0;i<n;i++)
    {   element[i]= read_data();
      tmp=makeNode(element[i]);
      insert(tmp);
    }

  cur=root;
  /* x=read_data();
    del=makeNode(x);
    insertbefore(del);
  /* for(cur=root;cur!=NULL;cur=cur->next)
   */
  /*  for(i=0;i<2;i++)
      cur=cur->next;*/
    del=cur;
  delete(del);
  display();
  free(tmp);
}
