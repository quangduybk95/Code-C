/* Vu Quang Minh - 8C */
// Date Create:
//menu chuong trinh
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<math.h>
typedef struct{
  char name[30];
}pl;
//tim ten
void tim(pl a[],char name[],int n)
{
  int i;
  char *c;
  for(i=0;i<n;i++)
    {
      c=strstr(timten(a[i].name),name);
      if(c!=NULL)printf(" ");

    }
}
//loc ra phan ten
char *timten(char hoten[])

{
  int i;
  i=strlen(hoten)-1;
  while(i>=0&&hoten[i]!=' ')i--;
  return hoten+i+1;
}//loc ra ho
void ho(char str[],char c[])
{
	int i=0,n,j,a=0;
	n=strlen(str);
	while(i<n&&str[i]!=' ')i++;
	for(j=0;j<=i;j++)
	{
		c[j]=str[j];
	}
	c[i]='\0';
	printf("%s",c);
}
//in xau hoa
char *xauhoa(char *c)
{
  int i,j;
  j=strlen(c)-1;
  for(i=0;i<=j;i++)
    {
      if(c[i]!=' '&&c[i]<='z'&&c[i]>='a'){
        c[i]='A'+(c[i]-'a');
      }
    }
  return c;
}
//in hoa
char *cap(char *str)
{
		int i;
  for(i=0;i<strlen(str);i++)
    if((str[i]>='a'&&str[i]<='z')&&(i==0||str[i-1]==' '))
      str[i]='A'+(str[i]-'a');
  return str;
}
//xoa dau cach trang
void trimmiddle(char a[])
{
  int i;
  char *c;
  c=strstr(a,"  ");
  while(c!=NULL)
    {
      i=strlen(a)-strlen(c);
      for(i;i<strlen(a);i++)
        a[i]=a[i+1];
      c=strstr(a,"  ");
    }
  for(i=0;i<strlen(a);i++)
    a[i]=a[i+1];
  printf("%s\n",a);
}
//xoa cach 2
char *trim(char c[])
{
	int i,j,n;
	n=strlen(c);
	for(i=0;i<n;i++)
	{
		if(c[i]==' '&&c[i+1]==' ')
		{
			for(j=i;j<n;j++)
				c[j]=c[j+1];
			i--;
		}
	}
    if(c[i]==' ')
      for(i=0;i<n;i++)
		c[i]=c[i+1];
	return c;
}
//nhap ten kem dau cach
void nhapten(pl a[],int n)
{
	int i,j,k=0;

	for(j=1;j<=n;j++)

	{
		do{
			printf("nhap ten nguoi choi thu %d\n",j);
			gets(a[j].Name);

			for(i=0;i<strlen(a[j].Name);i++)
				if(a[j].Name[i]==' ')k++;

		}while(k==0);
	}

}
//tim uoc chung
int uocchung(int a,int b)
{
	do{
		if(a>b)b=a-b;
		if(a<b)a=b-a;
	}while(a==b);
	return a;
}
//xau dx
int str(char str[])
{
	int i,j=0,n;
	n=strlen(str)-1;
	if(n%2==0){
		for(i=0;i<=n/2-1;i++)
		{
			if(str[i]==str[n-i])j++;
		}
		if(2*j==n)return 1;
		else return 0;

	}
	if(n%2!=0){
		for(i=0;i<=n/2;i++)
		{
			if(str[i]==str[n-i])j++;
		}
		if(2*j-1==n)return 1;
		else return 0;
	}
}
main(){
	int mn,yn;
	srand(time(NULL));yn=rand ();
	int i,j,k,l;
	char c,ch;
	do{
		printf("chuong trinh tro choi\n");
		printf("1:\n2:\nq:quit\n");
		do{
			c=getchar();
			if(c!='1'&&c!='2'&&c!='q')printf("moi nhap lai\n");

		}while(c!='1'&&c!='2'&&c!='q');
		switch(c){
		case'1':
         
          break;
		case'2':break;
		case'q':break;
		}

	}while(c!='q');

}
 do{
				printf("lus chon\n")	;
				printf("voi a: b: q:quit\n");
				do{
					ch=getchar();
					if(ch!='a'&&ch!='b'&&ch!='q')printf("moi nhap lai\n");
				}while(ch!='a'&&ch!='b'&&ch!='q');
				switch(ch){
				case'a':

					break;
				case'b':
					break;
				case'q':break;
				}
			}while(ch!='q');



