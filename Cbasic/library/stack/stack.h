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
} stack;

////////////////////////////////////////////////// nguyen ham
// cac ham khoi tao
void   createStack(stack * list);
node * makeNewNode(elementtype e);

// insert
node * push(stack * list, elementtype e);

// delete
elementtype pop(stack * list);

// print data
void printStack(stack  list);

// total node
int totalStack(stack list);

// is empty

int isEmpty(stack list);
/////////////////////////////////////////////// cac ham
///////////////// cac ham khoi tao
// tao ds moi
void createStack(stack * list)
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
node * push(stack * list, elementtype e)
{
  node * new = makeNewNode(e);
  if ((*list).root == NULL)
    {
      (*list).root = (*list).tail = new;
    }
  else
    {
      new->next = (*list).root;
      new->prev = (*list).root;
      (*list).root = new;
    }
  return (*list).root;
}

//////////////////delete
//delete begin
elementtype pop(stack * list)
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
node * deleteStack(stack * list)
{
  while((*list).root != NULL) pop(list);
}

///////////////// total
int totalStack(stack list)
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

// is empty
int isEmpty(stack list)
{
  if (list.root == NULL) return 1;
  return 0;
}
