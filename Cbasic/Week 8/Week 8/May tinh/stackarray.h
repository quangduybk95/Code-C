#include<stdio.h> 
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define MAX 50
typedef int elementtype;
typedef struct StackRec{
  int top;
  elementtype data[MAX];        //mang luu tru phan tu
}StackRec;
typedef struct StackRec stacktype;

void initialize(stacktype *s);
int empty(stacktype *s);
int full(stacktype *s);
void push(elementtype e, stacktype *s);
elementtype pop(stacktype *s);

void initialize(stacktype *s){
  (*s).top=0;
}

int empty(stacktype *s){
  return (*s).top==0;
}

int full(stacktype *s){
  return (*s).top==MAX;
}
void push(elementtype e,stacktype *s){
  if(full(s))
    printf("stack over\n");
  else {
    (*s).top=(*s).top+1;
    (*s).data[(*s).top]=e;
  }
}

elementtype pop(stacktype *s){
  if(empty(s))
    printf("stack ko con de lay ra\n");
  else {
    int x;
    x=(*s).data[(*s).top];
    (*s).top=(*s).top-1;
    return x;
  }
}  

void output(stacktype s){
  int i;
  for(i=s.top-1;i>0;i--)
    printf("%d",s.data[i]);
  printf("\n");
}
elementtype top(stacktype *s){
  return (*s).data[(*s).top];
}

