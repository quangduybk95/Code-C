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


int main(int argc, char* argv[]){

	if(argc!=2)
	{
		printf("Doi so co dang: $./check file.txt\n");
		return 1;
	}

	header *head;
	head=(header *)malloc(1*sizeof(header));

	FILE *f;
	if((f=fopen(argv[1],"r"))==NULL)
	{
		printf("Cannot open file: %s\n",argv[1]);
		return 1;
	}

	int irc,size=0;
	irc=fread(head,sizeof(header),1,f);

	if(irc==0){
		printf("File chua co HEADER\n");
		return 1;
	}

	char c;
	while((c=fgetc(f))!=EOF) size++;
	fclose(f);

	if(size==head[0].size){
		printf("Noi dung HEADER:\n");
		printf("%d byte\n%s\n%s\n",head[0].size,head[0].name,head[0].date);
	}
	else{
		printf("FILE chua co HEADER\n");
	}
	printf("=>End of CHECK\n");
}
