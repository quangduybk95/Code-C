/* HEDSPI NICHIBU - HUST */
// Date Create:
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
	char name[25];
	char tel[11];
	char email[20];
}elementtype;
typedef struct node node;
typedef struct node{
	elementtype element;
	node *next;
}node;
node *root;
node *cur;
node *root2;
node *root3;
node *prev=NULL;

node *makenewnode(elementtype adr)
{
	node *new;
	new=(node *)malloc(sizeof(node));
	new->element=adr;
	new->next=NULL;
	return new;
}
elementtype read(){
	elementtype ele;
	printf("moi nhap ten\n");
	gets(ele.name);
	printf("moi nhap so dien thoai\n");
	gets(ele.tel);
	printf("moi nhap email\n");
	gets(ele.email);
	return ele;
}
void dis(node *new)
{
	printf("NAME:%s\n",new->element.name  );
	printf("TEL:%s\n",new->element.tel  );
	printf("EMAIL:%s\n",new->element.email  );
	printf("\n\n");
}

void insertafter(elementtype adr)
{
	node *new;

	new=(node*)malloc(sizeof(node));
	new=makenewnode(adr);
	if(root==NULL)
	{
		root=new;
		cur=root;
	}
	else{

		new->next=cur->next;
		cur->next=new;
		prev=cur;
		cur=cur->next;
		prev->next=cur;
	}


}
void insertbefore(elementtype adr)
{
	node *new;
	new=(node*)malloc(sizeof(node));
	new=makenewnode(adr);
	if(root==NULL)
	{
		root=new;
		cur=root;
		prev->next=cur;
	}
	else{
		prev->next=new;
		new->next=cur;
		//neu chi co 1 con cho
		if(cur==root){
			root=new;
		}
		cur=new;
	}
}
void traversing()
{
	for(cur=root;cur!=NULL;cur=cur->next)
	{
		dis(cur);
	}
}
void deletebegin()
{
	node *new;
	new=(node*)malloc(sizeof(node));
	if(root==NULL)
	{
		printf(" danh sach rong ko xoa duoc\n");
	}
	else{
		new=root->next;
		root=new;

	}
}
void insertbegin(elementtype adr){
	node *new;
	new=(node*)malloc(sizeof(node));
	new=makenewnode(adr);
	if(root==NULL)
	{
		root=new;
		cur=root;
	}
	else{
		new->next=root;
		root=new;

	}
}
void deletecur()
{

	node *new;
	new=(node*)malloc(sizeof(node));
	new=cur;
	prev->next->next=cur->next;
	cur=cur->next;
	free(new);
}
void freecur()
{
  for(cur=root;cur!=NULL;cur=cur->next)
    {
      deletebegin();
    }
}
int search(elementtype adr)
{
  for(cur=root;cur!=NULL;cur=cur->next)
    {
      if(strcmp(adr.tel,cur->element.tel)==0)return 1;
    }
  return 0;
}
void contact(FILE *in)
{
  int i=0,j;
  elementtype *adr;
  adr=(elementtype*)malloc(100*sizeof(elementtype));
  if(adr==NULL)
    {
      printf("loi ko cap phat duoc bo nho\n");
    }

  for(cur=root;cur!=NULL;cur=cur->next)
    {
      strcpy(adr[i].name,cur->element.name);
      strcpy(adr[i].tel,cur->element.tel);
      strcpy(adr[i].email,cur->element.email);
      i++;
    }
  fwrite(adr,sizeof(elementtype),i,in);
  free(adr);
  fclose(in);
}
void contact2(FILE *in)
{
  int i=0,j;
  for(cur=root;cur!=NULL;cur=cur->next)
    {
      fprintf(in,"NAME: %s",cur->element.name);
      fprintf(in,"TEL:  %s",cur->element.tel);
      fprintf(in,"EMAIL:  %s",cur->element.email);
      fprintf(in,"\n\n");
      i++;
    }
  fclose(in);
}
node *insertatp(node *root,elementtype adr,int n)
{
  int i;
  cur=root;
  node *new;
  new=(node*)malloc(sizeof(node));
  new=makenewnode(adr);
  if(n<=1)
    {
      insertbegin(adr);
      return new;
    }
  for(i=0;i<n-1;i++)
    {
      prev=cur;
      cur=cur->next;
      if(cur==NULL){
        printf("ko co vi tri nhu ban yeu cau\n");
        break;
      }
    }
  if(cur==NULL)
    {
      insertbegin(adr);
    }
  if(cur!=NULL){
    prev->next=new;
    new->next=cur;
    cur=new;
  }

  return new;
}
node *deleteatp(node *root,int n)
{
  int i;
  cur=root;

  for(i=0;i<n-1;i++)
    {
      prev=cur;
      cur=cur->next;
      if(cur==NULL){
        printf("ko co vi tri nhu ban yeu cau\n");
        break;
      }
    }
  if(cur!=NULL)
    { deletecur();}
  return root;

}
void split(int n){
  int i,j;
  cur=root;

  for(i=0;i<n;i++){
    prev=cur;
    cur=cur->next;

  }
  root2=cur->next;
  root2->next=cur->next->next;
  cur->next=NULL;
}
int divide(int offside,int plus)
{
  int i,j;
  node *ck;
  cur=root;
  for(i=0;i<offside;i++)
    {
      if(cur==NULL){printf("ko ton tai vi tri trong danh sach\n");return 1;}
      prev=cur;
      cur=cur->next;
    }
  root3=cur;
  ck=prev;

  for(i=0;i<plus-1;i++)
    {
      if(cur==NULL){printf("phan tu + them vuot ra khoi danh sach\n ");return 1;}
      cur=cur->next;
    }
   ck->next=cur->next;
  cur->next=NULL;
  return 1;
}
void readdat(FILE *in)
{
  int num;
  elementtype dt;
  while(num=fread(&dt,sizeof(elementtype),1,in)!=0)

    {
      insertafter(dt);

  }
}
main(){
	elementtype adr;
	int i;
	node *new;
    FILE *in1;
    FILE *in;
    in1= fopen("contact2.txt","w");
    in=fopen("contact.dat","wb");
    if(in==NULL||in1==NULL)
      {
        printf("loi ko mo duoc FILE\n");
        return 0;
    }
    for(i=1;i<=3;i++)
      {
        adr=read();
        insertafter(adr);

      }
    adr=read();
    insertatp(root,adr,1);
    traversing();
}
