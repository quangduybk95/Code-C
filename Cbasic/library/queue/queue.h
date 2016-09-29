/*Thu vien cho QUEUE*/
////////////////////////////////////
typedef struct node node;
// mot node gom
typedef struct node {
  elementtype element;
  node * next;
  node * prev;
}node;
// mot ds node gom co root,cur
typedef struct {
  node * root;
  node * cur;
  node * tail;
} queue;

////////////////////////////////////////////////// nguyen ham
// cac ham khoi tao
void   createQueue(queue * list);
node * makeNewNode(elementtype e);

// insert
node * enQueue(queue * list, elementtype e);

// delete
elementtype deQueue(queue * list);

// print data
void printQueue(queue  list);

// total node
int totalQueue(queue list);

//isEmpty
int isEmpty(queue list);
/////////////////////////////////////////////// cac ham
///////////////// cac ham khoi tao
// tao ds moi
void createQueue(queue * list)
{
  (*list).root  = (*list).cur = (*list).tail  = NULL;
}

// tao nut moi
node * makeNewNode(elementtype e)
{
  node * new = (node *)malloc(sizeof(node));
  new->element = e;
  new->next = NULL;
  new->prev = NULL;
  return new;
}

/////////////// insert
// inser begin
node * enQueue(queue * list, elementtype e)
{
  	node * new = makeNewNode(e);
	if((*list).root == NULL)
	{
      (*list).root = (*list).tail = new;
	}
	else
	{
		(*list).tail->next = new;
		new->prev = (*list).tail;
        (*list).tail = new;
	}
	return (*list).tail;
    /* node * new = makeNewNode(e);
       if ((*list).root == NULL)
       {
       (*list).root = (*list).tail = new;
       }
       else
       {
       new->next = (*list).root;
       (*list).root->prev = new;
       (*list).root = new;
       }
       return (*list).root;*/
}

//////////////////delete
// delete last
elementtype deQueue(queue *list)
{
  elementtype e;
  if((*list).root != NULL)
	{
     		 node * new = (*list).root;
		(*list).root = (*list).root->next;
		if ((*list).root != NULL) (*list).root->prev = NULL;
		e = new->element;
		free(new);
		return e;
	}
}

// delete all
node * deleteQueue(queue * list)
{
  while((*list).root != NULL) deQueue(list);
}
///////////////// total
int totalQueue(queue list)
{
  int i=0;
  list.cur = list.root;
	while(list.cur != NULL)
      {
        i++;
        list.cur = list.cur->next;
      }
    return i;
}
//isEmpty
int isEmpty(queue list)
{
  if (list.root != NULL ) return 0;
  return 1;
}
