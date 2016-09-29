#include<stdio.h>
#include<string.h>
int doi(char s1[],char s2[])
{
  int n=strlen(s1)-1;
  int i;
  for(i=0;i<=n/2;i++) if(s1[i]!=s2[n-i]) return 0;
  return 1;

}
int bang(char s1[],char s2[])
{
  int n=strlen(s1)-1;
  int i;
  for(i=0;i<=n;i++) if(s1[i]!=s2[i]) return 0;
  return 1;

}
int sosanh(char s1[],char s2[]){
  if (doi(s1,s2)==1) return -1;
   if (bang(s1,s2)==1) return 1;
   return 0;
}
main()
{
  char a1[100],a2[100];
  gets(a1);gets(a2);
  printf("\n%d\n",sosanh(a1,a2));
}
