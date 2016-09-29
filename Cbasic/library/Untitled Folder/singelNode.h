////////////////////////////////////
typedef struct node node;
// mot node gom
typedef struct node {
	elementtype element;
	node *next;
}node;
// mot ds node gom co root,prev,cur
typedef struct {
  node * root;
  node * cur;
  node * prev;
  node * tail;
} singleList;

////////////////////////////////////////////////// nguyen ham
// cac ham khoi tao
void   createSingleList(singleList * list);
node * makeNewNode(elementtype e);

// insert
node * insertAfter(singleList * list, elementtype e);
node * insertBegin(singleList * list, elementtype e);
node * insertEnd(singleList * list, elementtype e);
node * insertAtPosition(singleList * list, elementtype e, int n);

// delete
node * deleteBegin(singleList * list);
node * deleteEnd(singleList * list);
node * deleteAtPosition(singleList * list, int n);
node * deleteSingleList(singleList * list);

// print data
void   printSingleList(singleList  list);

// total node
int    totalSingleList(singleList list);

/////////////////////////////////////////////// cac ham
///////////////// cac ham khoi tao
// tao ds moi
void createSingleList(singleList * list)
{
  (*list).root = (*list).prev = (*list).cur = (*list).tail  = NULL;
}

// tao nut moi
node * makeNewNode(elementtype e)
{
  node * new = (node *)malloc(sizeof(node));
  new->element = e;
  new->next = NULL;
  return new;
}

/////////////// insert
node * insertEnd(singleList *list,elementtype e)
{
	node * new = makeNewNode(e);
	if((*list).root == NULL)
	{
      (*list).root = (*list).tail = new;
	}
	else
	{
		(*list).tail->next = new;
		(*list).tail = new;
	}
	return (*list).tail;
}

// inser begin
node * insertBegin(singleList * list, elementtype e)
{
  node * new = makeNewNode(e);
  if ((*list).root == NULL)
    {
      (*list).root = (*list).tail = new;
    }
  else
    {
      new->next=(*list).root;
      (*list).root = new;
    }
  return (*list).root;
}

// insert at  position
node * insertAtPosition(singleList * list,elementtype e,int n)
{
  node *new = makeNewNode(e);
  if((*list).root == NULL)
    {
      (*list).root = (*list).tail = (*list).cur = new;
	}
  else
    {
      if(n <= 1)
        {
          insertBegin(list,new->element);
          return (*list).cur;
        }
      if(n > totalSingleList(*list))
        {
          insertEnd(list,new->element);
          return (*list).cur;
        }
      else
        {
          (*list).cur = (*list).prev = (*list).root;
          int i = 1;
          while(((*list).cur->next != NULL)&&(i <= n-1))
            {
              i++;
              (*list).prev = (*list).cur;
              (*list).cur = (*list).cur->next;
            }
          new->next = (*list).cur;
          (*list).prev->next = (*list).cur = new;
        }
    }
  return (*list).cur;
}

//////////////////delete
//delete begin
node * deleteBegin(singleList * list)
{
  if((*list).root != NULL)
	{
      node * new = (*list).root;
		(*list).root = (*list).root->next;
		free(new);
	}
  return (*list).root;
}

// delete last
node * deleteEnd(singleList *list)
{
  if((*list).root != NULL)
    {
       (*list).cur = (*list).prev = (*list).root;
          while(((*list).cur->next != NULL))
            {
              (*list).prev =( *list).cur;
              (*list).cur = (*list).cur->next;
            }
        node *new = (*list).cur;
		(*list).cur = (*list).cur->next;
		free(new);
        (*list).tail = (*list).prev;
        (*list).tail->next = NULL;
        return (*list).tail;
    }
}

// delete all
node * deleteSingleList(singleList * list)
{
  while((*list).root != NULL) deleteBegin(list);
}

///////////////// total
int totalSingleList(singleList list)
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
