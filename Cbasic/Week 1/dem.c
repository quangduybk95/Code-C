#include <stdio.h>
#include<string.h>
char s[255];
int a[1000];
void nhap()
{
	printf("Nhap xau: ");gets(s);
}
void xuli(){
	int i;
    char j;
	for (i=0;i<=strlen(s)-1;i++)
	{
		a[s[i]]=0;
	}
	for (i=0;i<=strlen(s)-1;i++)
	{
		a[s[i]]++;
	}
	for (j='a';j<='z';j++)
	{
		if(a[j]>0) printf("%c    %d\n",j,a[j]);
	}
}
main()
{
	nhap();
	xuli();
}
