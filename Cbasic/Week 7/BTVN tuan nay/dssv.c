#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct{
	int stt;
	int mssv;
	char name[20];
	int sdt;
	int diem;
}elementtype;
typedef struct node node;
typedef struct node{
	elementtype element;
	node *next;
}node;
node *root=NULL;
node *cur;
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
    printf("Moi nhap stt : \n");
    scanf("%d%*c",&ele.stt);
    printf("Moi nhap mssv : \n");
    scanf("%d%*c",&ele.mssv);
	printf("Moi nhap ten :\n");
	gets(ele.name);
	printf("Moi nhap so dien thoai :\n");
    scanf("%d%*c",&ele.sdt);
	printf("Moi nhap diem :\n");
    scanf("%d%*c",&ele.diem);
	return ele;
}

void dis(node *new)
{ printf("\n---------------------------\n");
  printf("STT :%d\n",new->element.stt);
  printf("Tem :%s\n",new->element.name  );
  printf("Sdt :%d\n",new->element.sdt  );
  printf("Diem :%d\n",new->element.diem  );
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
void traversing()
{
	for(cur=root;cur!=NULL;cur=cur->next)
	{
		dis(cur);
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

node *add_student(node *root,node *to_add)
{
  node *curr_std=NULL,*prev_std=NULL;
  if(root==NULL)
    {
      return to_add;
    }
  if(to_add->element.diem>root->element.diem)
    {
      to_add->next=root;
      return to_add;
    }
  curr_std=root;
  while(curr_std!=NULL && to_add->element.diem<curr_std->element.diem)
    {
      prev_std=curr_std;
      curr_std=curr_std->next;
    }
  prev_std->next=to_add;
  to_add->next=curr_std;
  cur=curr_std;
  return root;
}
void readdat(FILE *in)
{
  int num=0;
  elementtype dt;
  node *adr;
  while(num=fread(&dt,sizeof(elementtype),1,in)!=0)

    {
      num++;
      adr=makenewnode(dt);
      root=add_student(root,adr);
  }
  printf("%d",num);
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
main(){
	char c,ch;
    int i;
    elementtype ad;
    FILE *in;
    in=fopen("grade.dat","rb");
	do{
		printf("\nChuong trinh danh sach sinh vien\n");
		printf("1.Lap danh sach\n2.Bo sung 1 sinh vien\n3.Xoa 1 sinh vien\n4.In danh sach\n5.Quit\n");
        printf("Nhap lua chon : ");
        c=getchar();
        while(getchar()!='\n');
		switch(c){
		case'1':
          readdat(in);
          break;
		case'2':

          ad=  read();
          cur=makenewnode(ad);
          root=add_student(root,cur);
          break;
        case'3':
          deletebegin();
        case'4':traversing();
          break;
		case'5':break;
        default : printf("\nEXIT \n");break;
		}

	}while(c!='5');

}
