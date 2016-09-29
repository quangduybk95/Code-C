#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct listnode listnode;
typedef struct listnode{
  l_elementtype element;
  listnode *next;
}listnode;
typedef struct list{
  listnode *root;
  listnode *cur;
  listnode *prev;
}list;
//khai bao: list *l;l=make_new_list();
list *make_new_list(){
  list *l=(list*)malloc(sizeof(list));
  if(l==NULL){
    printf("Khong khoi tao duoc danh sach\n");
    return;
  }
  l->root==NULL;
  l->cur==NULL;
  return l;
}
listnode *make_new_listnode(l_elementtype e){
  listnode *new=(listnode*)malloc(sizeof(listnode));
  if(new==NULL){
    printf("Tao nut moi that bai\n");
    return;
  }
  else {
    new->element=e;
    new->next=NULL;
    return new;
  }
}
void insert_begin(list *l,l_elementtype a){
  listnode *new=make_new_listnode(a);
  if(l->root==NULL){
    l->root=new;
  }
  else{
    new->next=l->root;
    l->root=new;
  }
}
void insert_after(list *l,l_elementtype a)//chen sau
{
  listnode *new=make_new_listnode(a);
  if(l->root==NULL)
    {
      l->root=new;
      l->cur=new;
    }
  else
    {
      new->next=l->cur->next;
      l->cur->next=new;
      l->cur=l->cur->next;
    }
}

int removeAfter (list *l, listnode *q )
{
if (q !=NULL && q->next !=NULL)
{
listnode* p = q->next;
q->next = p->next;
//if (p->next=NULL) l.pTail = q;
 free(p);
return 1;
}
else return 0;
}

void delete_begin(list *l){
  listnode *a;
  l_elementtype e;
  if(l->root==NULL){
    printf("Danh sach rong\n");
    return;
  }
  else{
    a=l->root;
    e=a->element;
    l->root=a->next;
    free(a);
    return;
  }
}
listnode *insert_before(list *l,l_elementtype a)
{
  listnode *new;
  new = make_new_listnode(a);
  if (l->root == NULL)
    {
      l->root = new;
      l->cur = l->root;
      l->prev->next=l->cur;
    }
  else
    {
      l->prev->next=new;
      new->next = l->cur;
      if (l->prev != NULL) l->prev->next = new;
      if (l->cur == l->root) l->root = new;
        l->cur = new;
    }
  return l->cur;
    }
void insert_last(list* l,l_elementtype a)
{
  listnode *new=make_new_listnode(a);
  if(l->root==NULL)
    {
      l->root=new;
     l->cur=new;
    }
  else
    {
      l->cur=l->root;
  do
    {
      if(l->cur->next!=NULL)
        {
          l->prev=l->cur;
          l->cur=l->cur->next;
        }
    }while(l->cur->next!=NULL);
    }
  l->cur->next=new;
  l->cur=l->cur->next;
}
void insert_choose(list*l,l_elementtype a,int i)
//insert vao vi tri i tuy chon
{
  int j;
  j=0;
   listnode *new=make_new_listnode(a);
   if(i==1)
     insert_begin(l,a);
   else
     {
       l->cur=l->root;
       j++;
       while(j<i)
         {
           j++;
           if(l->cur->next!=NULL)
             {
               l->prev=l->cur;
             }
           l->cur=l->cur->next;
           if(l->cur==NULL) break;
         }
       if(l->cur==NULL) insert_last(l,a);
  else
    {
      new->next=l->cur;
      l->prev->next=new;
    }
    }
}
/*void insert_before(list *l,l_elementtype adr)
{
  //l->prev=NULL;
 	listnode *new=make_new_listnode(adr);;
    //	new=(listnode*)malloc(sizeof(listnode));
    // listnode *new;
	if(l->root==NULL)
	{
		l->root=new;
		l->cur=l->root;
		l->prev->next=l->cur;
	}
	else{
      l->prev->next=new;
      new->next=l->cur;
      if(l->cur==l->root){
        l->root=new;
      }
      l->cur=new;
	}
}
void deletecur(list *l)
{

	listnode *new;
    // new=make_new_listnode();
	new=l->cur;
	l->prev->next=l->cur->next;
	l->cur=l->cur->next;
	free(new);
    }*/
void delete_last(list *l)//xoa o vi tri cuoi
{
  listnode *a;
  if(l->root==NULL)
    {
      printf("danh sach khong co phan tu de xoa.\n");
    }
  else
    {
      l->cur=l->root;
  do
    {
          l->prev=l->cur;
          l->cur=l->cur->next;
    }while(l->cur->next!=NULL);
  a=l->cur;
  l->cur=l->prev;
  l->prev->next=NULL;
  free(a);
    }
}
void delete_choose(list *l,int i)
//Xoa phan tu o vi tri duoc chi dinh san.
{
 listnode *b,*a;
  int j;
  j=-1;
  if(l->root==NULL)
    {
      printf("Danh sach ko co phan tu de xoa .\n");
    }
  else
    {
      b=l->root;
      while(j<i-2)
        {
          j++;
          l->prev=b;
          b=b->next;
          if(b==NULL)
            break;
    }
  if(b!=NULL)
    {
      a=b;
      l->prev->next=b->next;
      b=b->next;
      free(a);
    }
  else
    {
      printf("Vi tri ban can xoa nam ngoai danh sach.\n");
    }
    }
}
list *sapxep(list *l){
  int i,j;
  double a,b;
  listnode *temp1=l->root,*temp2=l->root;
  listnode *noki=(listnode *)malloc(sizeof(listnode));
  while(temp1!=NULL){
    temp2=temp1->next;
    while(temp2!=NULL){
      a=temp1->element.diem;
      b=temp2->element.diem;
      if(a>b){
        noki->element=temp2->element;
        temp2->element=temp1->element;
        temp1->element=noki->element;
      }
      temp2=temp2->next;
    }
    temp1=temp1->next;
  }
  return l;
}
