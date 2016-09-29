#include<stdio.h>
#include<string.h>
void upcase(char *s)
{
  int n = strlen(s),i;
  for(i=0 ;i<n ;i++ )
    if (s[i] >= 97 && s[i] <= 122) s[i] = s[i] - 32;
}

void lowercase(char *s)
{
  int n = strlen(s),i;
  for(i=0 ;i<n ;i++ )
    if (s[i] >= 65 && s[i] <= 90) s[i] = s[i] + 32;
}

main()
{
  char s[30];
  gets(s);
  upcase(s);
  printf("=>%s\n",s);
}

