
// 1 node gom truong du lieu va trg next de xd node tiep theo
typedef struct node node;
typedef struct node {
	elementtype element;
	node *next;
}node;
// mot ds node gom co root,tail,cur
typedef struct {
	node *root;
	node *cur;
	node *prev;
} nodelist;
//////////////////////////////////////////////////
// khoi tao mot danh sach moi
void creat(nodelist *list)
{
	(*list).root=(*list).cur=(*list).prev=NULL;
}
// tao mot nut moi voi gia tri =e
node *makeNewNode(elementtype e){
	node *new=(node *)malloc(sizeof(node));
	new->element=e;
	new->next=NULL;
	return new;
}
// insert after 1 node vao danh sach list voi gia tri e
//insert begin
node *enQueue(nodelist *list,elementtype e)
{
	node *new=makeNewNode(e);
	if((*list).root==NULL)
	{
      (*list).root=(*list).cur=new;
	}
	else{
      new->next=(*list).root;
      (*list).root=(*list).cur=new;
	}
    return (*list).root;
}
// tong so trg trong list
int total(nodelist list)
{
  int i=0;
  list.cur=list.root;
  while(list.cur!=NULL)
    {
      i++;
      list.cur=list.cur->next;
    }
  return i;
}
/////////////////////DELETE
// delete last
elementtype  deQueue(nodelist *list)
{

   elementtype e;
   (*list).prev = (*list).cur = (*list).root;
	if( (*list).root!=NULL)
	{
		while( (*list).cur->next!=NULL)
		{;
			 (*list).prev= (*list).cur;
			 (*list).cur= (*list).cur->next;
		}
		node *new;

		new= (*list).cur;
        e=new->element;
		 (*list).cur= (*list).prev;
		 (*list).cur->next=NULL;
		free(new);
        return e;
	}
}
int isEmpty(nodelist list)
{
  if (list.root==NULL) return 0;
  return 1;
}
//////////////////////////////////////////////////
//// cac ham tien ich co the thay doi
// hien thi tat ca noi dung cua list


