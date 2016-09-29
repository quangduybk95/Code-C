#include<stdio.h>
#include<stdlib.h>

typedef struct address{
	char name[20];
	char email[25];
	char tel[11];
} sinhvien;
typedef struct node node;
typedef struct node{
	sinhvien info;
	node *next;
}node;
	node *root;
    node *cur;

node *make_new_node(sinhvien tt){
	node *new;
	new=(node *)malloc(sizeof(node));
	new->info=tt;
	new->next=NULL;
	return new;
};

sinhvien make_data()
{
	sinhvien tt;
	printf("Nhap tt\n");
	printf("Nhap name: ");gets(tt.name);
	printf("Nhap Tel : ");gets(tt.tel);
	printf("Nhap mail: ");gets(tt.email);
	return tt;
}
void printf_data(sinhvien tt)
{
	printf("%-25s%-15s%-25s\n",tt.name,tt.tel,tt.email);
}
main()
{
	node *new=make_new_node(make_data());
	printf_data(new->info);
}
