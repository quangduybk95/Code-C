// 1 node gom truong du lieu va trg next de xd node tiep theo
typedef struct node node;
typedef struct node {
	elementtype element;
	node *next;
}node;
// mot ds node gom co root,tail,cur
typedef struct {
	node *root;
	node *tail;
	node *cur;
	node *prev;
} nodelist;
//////////////////////////////////////////////////
// khoi tao mot danh sach moi
void creat(nodelist *list)
{
	(*list).root=(*list).tail=(*list).cur=(*list).prev=NULL;
}
// tao mot nut moi voi gia tri =e
node *makeNewNode(elementtype e){
	node *new=(node *)malloc(sizeof(node));
	new->element=e;
	new->next=NULL;
	return new;
}

//insert begin
node * push(nodelist *list,elementtype e)
{
	node *new=makeNewNode(e);
	if((*list).root==NULL)
	{
      (*list).root=(*list).tail=new;
	}
	else{
      new->next=(*list).root;
      (*list).root=new;
	}
    return (*list).root;
}
/////////////////////DELETE
//delete begin
elementtype  pop(nodelist *list)
{
  elementtype e;
  if((*list).root!=NULL)
	{
      node *new=(*list).root;
      e=new->element;
		(*list).root=(*list).root->next;
		free(new);
	}
  return e;
}
//////////////////////////////////////////////////
//// cac ham tien ich co the thay doi
// hien thi tat ca noi dung cua list
void displayAllList(nodelist list)
{
  if (list.root==NULL) return;
  list.cur=list.root;
	printf("ds------------------\n");
	while(list.cur!=NULL)
	{
      printf("%5d ",list.cur->element.num);
		list.cur=list.cur->next;
	}
    printf("\n");
}
void str(nodelist ds)
{
  ds.cur=ds.root;
  int s[300];
  int j,i=-1;
  while(ds.cur!=NULL)
    {
      i++;
      s[i]=ds.cur->element.num;
      ds.cur=ds.cur->next;
    }

  for(j=0 ;j<=i ;j++ ) printf("%d",s[j]);
  printf("\n");
}
