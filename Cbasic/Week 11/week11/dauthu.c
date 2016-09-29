#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define IN "usopen.txt"
#define OUT "treegame.txt"
typedef struct {
	char name[100];
} elementtype;

#include "tree.h"
// insert
void  insertNode(tree *t, elementtype x)
{
	if (*t == NULL){
		*t=(node*)malloc(sizeof(node));
		(*t)->element = x;
		(*t)->left = NULL;
		(*t)->right = NULL;
	}
}
void padding ( char ch, int n )
{
	int i;
	for ( i = 0; i < n; i++ )
		putchar ( ch );
}
void structure ( tree t, int level )
{
	int i;
	if ( t == NULL ) {
		padding ( '\t', level );
		puts ( "NULL" );
	}
	else {
		structure ( t->right, level + 1 );
		padding ( '\t', level );
		printf ( "%s\n", t->element.name );
		structure ( t->left, level + 1 );
	}
}
int s_random()
{
  int r;

  r=rand()%10+1;
  return r%2;
}
main()
{
	srand(time(NULL));
	tree t[17],t1[9],t2[5],t3[3],t4;
	int i=0,j=0;
	for(i=1;i<=16;i++) makeNullTree(&t[i]);
	FILE *f;
	f=fopen(IN ,"r+");
	elementtype e;
	// 1/16
	i=0;
	while(fgets(e.name,80,f)!=NULL)
	{
		i++;
		insertNode(&t[i],e);
	}
	//1/8
	for(i=1 ;i<=15 ;i=i+2 )
	{
		j++;
		elementtype win;
		if(s_random())
			win=t[i]->element;
		else win=t[i+1]->element;
		t1[j]=makeNewTreeFromTowTrees(win,t[i],t[i+1]);
	}
	//1/4
	j=0;
	for(i=1 ;i<=7 ;i=i+2 )
	{
		j++;
		elementtype win;
		if(s_random())
			win=t1[i]->element;
		else win=t1[i+1]->element;
		t2[j]=makeNewTreeFromTowTrees(win,t1[i],t1[i+1]);
	}
	// 1/2
	j=0;
	for(i=1 ;i<=3 ;i=i+2 )
	{
		j++;
		elementtype win;
		if(s_random())
			win=t2[i]->element;
		else win=t2[i+1]->element;
		t3[j]=makeNewTreeFromTowTrees(win,t2[i],t2[i+1]);
	}
	// 1

	i=1;
	elementtype win;
	if(s_random())
		win=t3[i]->element;
	else win=t3[i+1]->element;
	t4=makeNewTreeFromTowTrees(win,t3[i],t3[i+1]);
	structure(t4,0);
	FILE * f1;
	f1=fopen(OUT ,"w+" );
	fprintf(f1,"%s",t4->element.name);
	printf("\nChuc mung quan quan: %s\n",t4->element.name);
	fclose(f);
	fclose(f1);
}
