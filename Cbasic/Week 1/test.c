#include<stdio.h>
#include<stdlib.h>
#define M 5
main()
{
	int r,i=0;
	char *s1[10]={"The","One","Some","Litter","A"};
	char *s2[10]={"boy","dog","girl","cat","pig"};
	char *s3[10]={"love","hate","like","jump","fly"};
	char *s4[10]={"at","on","up","down","outside"};
	srand(time(NULL));
	while(i<=9)
	{
		r=rand()%M;
		printf("%s ",s1[r]);
		r=rand()%M;
		printf("%s ",s2[r]);
		r=rand()%M;
		printf("%s ",s3[r]);
		r=rand()%M;
		printf("%s.\n",s4[r]);
		i++;
	}
}
