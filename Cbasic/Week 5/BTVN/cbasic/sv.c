/* Le Vinh Thien - 8C */
// Date Create: 15-09-2014
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define OUT "bangdiem.txt"

//tong so sv
int MAX=0;
// mang luu tru
typedef struct {
	char stt[5];
	char mssv[9];
	char ten[35];
	char sdt[12];
	char diem[3];
} list;

// nguyen ham
void getinfo(char s[], int i, list *sv);
void nhap(int i,list *sv);
int run(char s[],list *sv);

// ham lay so sv
int gettotal(char s[])
{
  FILE *f;
  char a[100];
  int i=0;

  if((f=fopen(s,"r"))==NULL)
    {
      printf("cannot open %s\n",s);
      return 0;
    }

  	while(fgets(a,81,f)!=NULL)
	{
		i++;
	}
    fclose(f);
    return i;
}
// lay thong tin moi sv
void getinfo(char s[], int i,list *sv)
{
  int j,n,m,k=0,v;
      // lay diem
	for(n=strlen(s)-2 ;n>=0 ;n-- )
		if (s[n]==' ') break;
	for(j=n+1 ;j<=strlen(s)-2 ;j++ )
	{
		sv[i].diem[k]=s[j];
		k++;
	}
	sv[i].diem[k]='\0';
    v=n;
    k=0;
    // lay sdt
    	for(j=n-1 ;j>=0 ;j-- )
		if (s[j]==' ') break;
        n=j;
	for(j=n+1 ;j<=v ;j++ )
	{
		sv[i].sdt[k]=s[j];
		k++;
	}
	sv[i].diem[k]='\0';

	// lay  stt
	k=0;
	for (m=0;m<=strlen(s)-1;m++)
		if(s[m]!=' ')
		{
			sv[i].stt[k]=s[m];
			k++;
		}
		else break;
	sv[i].stt[k]='\0';
	// lay mssv
	k=0;
	for(j=m+1 ;j<=strlen(s)-1 ;j++ )
		if(s[j]!=' ')
		{
			sv[i].mssv[k]=s[j];
			k++;
		}
		else break;
     sv[i].mssv[k]='\0';
	m=j;
	// lay ten;
	k=0;
	for (j=m+1;j<n;j++)
	{
		sv[i].ten[k]=s[j];
		k++;
	}
    sv[i].ten[k]='\0';
    }


// ham chinh
int main(int argc, char* argv[]){
  list *sv;
  int i;
	if(argc!=2) {
		printf("Error: Doi so phai co dang: $ ./sv file.txt\n");
		return 1;
	}
    MAX=gettotal(argv[1]);
    // cap phat bo nho dong
    sv=(list *)malloc((MAX)*sizeof(list));
    if(sv==NULL)
      {
        printf("Loi cap phat bo nho!\n");
        return 1;
      }

    FILE *f1;
    if((f1=fopen(argv[1],"r"))==NULL){
      return 1;
    }
    char s[100];
    for(i=0;i<=MAX;i++)
      {
        fgets(s,80,f1);
        getinfo(s,i,sv);
      }


    FILE *f;
    if((f=fopen("grade.dat","w"))==NULL)
      {
        printf("Cannot access file grade.dat\n");
        return 1;
      }
    // ghi vao grade.dat
    int irc=fwrite(sv,sizeof(list),MAX,f);
    printf("=>Noi dung fle grade.dat:\n");
    fclose(f);
    // doc du lieu tu grade.dat
    if((f=fopen("grade.dat","r"))==NULL)
      {
        printf("Cannot access file grade.dat\n");
        return 1;
      }
    list *tt;
    tt=(list *)malloc((MAX)*sizeof(list));
    irc=fread(tt,sizeof(list),MAX,f);
   for(i=0 ;i<=MAX ;i++ )
        printf("%-5s%-15s%-30s%-15s%-5s\n",tt[i].stt,tt[i].mssv,tt[i].ten,tt[i].sdt,tt[i].diem);
    free(tt);
}
