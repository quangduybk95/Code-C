#include<stdio.h>
#include<string.h>
void input(char s[]);
void delete(char s[], int a);
void trimRight(char s[]);
void trimLeft(char s[]);
void trimMid(char s[]);
void input(char s[])
{
printf("Nhap xau: \n");
scanf("%[^\n]%*c",s);
}
void delete(char s[],int a)
{
int i;
for(i=a ;i<=strlen(s)-1 ;i++ )
s[i]=s[i+1];
}
void trimRight(char s[])
{
while(s[strlen(s)-1]==' ') s[strlen(s)-1]='\0';
}
void trimLeft(char s[])
{
while(s[0]==' ') delete(s,0);
}
void trimMid(char s[])
{
int i;
for(i=1 ;i<strlen(s) ;i++ )
if ((s[i]==' ')&&(s[i+1]==' '))
{
delete(s,i);
i--;
}
}
main()
{
char s[100];
input(s);
trimMid(s);
trimRight(s);
trimLeft(s);
printf("%s\n",s);
}
