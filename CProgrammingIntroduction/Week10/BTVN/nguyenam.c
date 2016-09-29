#include<stdio.h>
#include<string.h>
int dem(char s[]);
int dem(char s[])
{
char nguyenam[6]="aieou";
int dem[7],i,j,n;
for(j=0 ;j<=5 ;j++ ) dem[j]=0;
n=strlen(s);
for(i=0 ; i<=n-1 ;i++ )
{
for(j=0 ;j<=4 ;j++ )
if (s[i]==nguyenam[j])
{
dem[j]++;
s[i]=s[i]-'a'+'A';
}
}
printf("\n");
for(j=0 ;j<=4 ;j++ ) printf("%c:%d\n",nguyenam[j],dem[j]);
printf("Xau da xu li: %s\n",s);
}
main()
{
char s[1000];
printf("Nhap xau :");
scanf("%[^\n]*c",s);
dem(s);
}

