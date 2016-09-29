/*Le Vinh Thien*/
#include<stdio.h>
#include<string.h>
typedef struct
{
	char s[100];
} bien;
bien xau[100];
char tg[100];//=>bien trung gian cua phan tach ten
/* xoa dau cach*/
void delete(char s[],int i);
void trim(char s[]);
/*tach ten*/
char *tach_ten(char s[]);
/*Sap xep theo ten*/
void sap_xep(bien xau[]);

//xoa dau cach
void delete(char s[],int i)
{
	int j;
	for(j=i;j<=strlen(s);j++)
		s[j]=s[j+1];
}
void trim(char s[])
{
	int i;
	// trim left
	while (s[0]==' ')
		delete(s,0);
	//trim right
	while(s[strlen(s)-1]==' ')
		s[strlen(s)-1]='\0';
	//trim middle
	for (i=1;i<strlen(s);i++)
		while((s[i]==' ')&&(s[i+1]==' ')) delete(s,i+1);		
}
// tach ten
char *tach_ten(char s[])
{
	int i,j,k=0;
	strcpy(tg,"\0");
	// tim vi tri co dau cach o phan dau phan ten
	for (i=strlen(s)-1;i>1;i--)
		if (s[i-1]==' ') break;
	// gan phan ten vao 1 bien tg dc khai bao o tren cung
	for (j=i;j<=strlen(s)-1;j++)
		{
			tg[k]=s[j];
			k++;
		}
		tg[k]='\0';// xoa bo nho dem cua bien tg
	// tra ket qua la phan ten ve cho ham
	return tg;
}
// Sap xep
void sap_xep(bien xau[])
{
	int i,j;
	char s[100],a[100],b[100];
	bien tmp;
	for (i=1;i<=2;i++)
		for (j=i+1;j<=3;j++)
		{
			// can 2 bien trung gian de luu gia tri ten la a,b
			// neu dung if (strcmp(tach_ten(xau[i].s),tach_ten(xau[j].s))>0) thi se k dc
			strcpy(a,tach_ten(xau[i].s));
			strcpy(b,tach_ten(xau[j].s));
			if (strcmp(a,b)>0)
			{
				tmp=xau[i];
				xau[i]=xau[j];
				xau[j]=tmp;
			}
		}
}
main()
{
	int i;
	//khoi tao gia tri
	strcpy(xau[1].s,"     le    thien   yen");
	strcpy(xau[2].s,"     le      thien   hoa       ");
	strcpy(xau[3].s,"         le    thien       anh              ");
	strcpy(xau[4].s," lethienvinh ");
	// demo
		//xau ban dau khi chua qua cac ham
		printf("\n1. Xau ban dau:\n");
		for (i=1;i<=3;i++)
			printf("%s\n",xau[i].s);
		//xau sau khi bo day cach
		printf("\n2. Xau bo dau cach dau:\n");
		for (i=1;i<=3;i++)
			{
				trim(xau[i].s);
				printf("%s\n",xau[i].s);
			}
		//tach ten
		printf("\n3. Xau da dc tach ten :\n");
		for (i=1;i<=3;i++)
			printf("%s\n",tach_ten(xau[i].s));
		// ket qua sau khi sap xep
		sap_xep(xau);
		printf("\n4. Xau da dc sap xep theo ten:\n");
		for (i=1;i<=3;i++)
			printf("%s\n",xau[i].s);
		
}
