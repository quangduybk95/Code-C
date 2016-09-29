// 1 q_node gom truong du lieu va trg next de xd q_node tiep theo
typedef struct q_node q_node;
typedef struct q_node {
	q_elementtype element;
	q_node *next;
}q_node;
// mot ds q_node gom co root,tail,cur
typedef struct {
	q_node *root;
	q_node *tail;
	q_node *cur;
	q_node *prev;
} q_nodelist;
//////////////////////////////////////////////////
// khoi tao mot danh sach moi
void creat(q_nodelist *list)
{
	(*list).root=(*list).tail=(*list).cur=(*list).prev=NULL;
}
// tao mot nut moi voi gia tri =e
q_node *makeNewq_node(q_elementtype e){
	q_node *new=(q_node *)malloc(sizeof(q_node));
	new->element=e;
	new->next=NULL;
	return new;
}

//insert begin
q_node * enQueue(q_nodelist *list,q_elementtype e)
{
	q_node *new=makeNewq_node(e);
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
q_elementtype  deQueue(q_nodelist *list)
{
  q_elementtype e;
  if((*list).root!=NULL)
    {
      (*list).cur=(*list).prev=(*list).root;
      while(((*list).cur->next!=NULL))
        {
          (*list).prev=(*list).cur;
          (*list).cur=(*list).cur->next;
        }
      q_node *new=(*list).cur;
      e=new->element;
      (*list).cur=(*list).cur->next;
      free(new);
      (*list).tail=(*list).prev;
      (*list).tail->next=NULL;
      return e;
    }
}
  //////////////////////////////////////////////////
//// cac ham tien ich co the thay doi
// hien thi tat ca noi dung cua list
void displayAllList(q_nodelist list)
{
  if (list.root==NULL) return;
  list.cur=list.root;
	while(list.cur!=NULL)
	{
      printf("%-5d%-20s%-10d%-10d%-10d%-10d\n",list.cur->element.STT,list.cur->element.biethieu,list.cur->element.mau,list.cur->element.tancong,list.cur->element.nhanhnhen,list.cur->element.phongthu);
		list.cur=list.cur->next;
	}
    printf("\n");
    }
