#define MAX 50
typedef struct int eltype;
typedef struct stackrec
{
  eltype storage[MAX];
  int top;
};
typedef struct stackrec stacktype;
void initialize(stacktype stack)
{
  stack.top=0;
}
int empty(stacktype stack)
{
  return stack.top==1;
}
int full(stacktype stack)
{
  return stack.top==MAX;
}
void push(eltype el,stacktype stack)
{
  if(full(stack))
    printf("stack tran\n");
  else stack.storage[stack.top++]=el;
}
eltype pop(stacktype stack)
{
  if(empty(stack)) printf("stack k con de lay ra \n");
  else return stack.storage[--stack.top];
}
