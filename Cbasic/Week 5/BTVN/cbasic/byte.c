/* Le Vinh Thien - 8C */
// Date Create:
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
typedef struct{
	int size;
	char name[25];
	char date[40];
}header;


int size_file(char s[])
{
	FILE *f;
	int byte=0;
	char c;
	if((f=fopen(s,"r"))==NULL)
	{
		printf("Cannot open file: %s\n",s);
		return -1;
	}

	while((c=fgetc(f))!=EOF)
	{
		byte++;
	}
    fclose(f);
	return byte;
}

void get_info(char s[],int a,header head[])
{
	time_t t;
	time(&t);

	strcpy(head[0].date,ctime(&t));
	head[0].size=a;

	printf("Kich thuoc: %d byte\n",head[0].size);
	printf("Ngay tao  : %s\n",head[0].date);
	printf("Tac gia   : ");gets(head[0].name);
}

int main(int argc, char* argv[])
{
	if(argc!=2)
	{
		printf("Doi so co dang: $ ./vd file\n");
		return 1;
	}
       int size=size_file(argv[1]);


       char tmp[size];
       header *head;
       head=(header *)malloc(1*sizeof(header));
       get_info(argv[1],size,head);

       FILE *f1,*f2;

       f1=fopen(argv[1],"r");
       int num=fread(tmp,size,1,f1);
       fclose(f1);

       f2=fopen(argv[1],"w+b");
       int irc=fwrite(head,sizeof(header),1,f2);
       fclose(f2);

       f2=fopen(argv[1],"a+");
       fwrite(tmp,size,1,f2);
       fclose(f2);
}
