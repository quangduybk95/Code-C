/*Le Vinh Thien -8E*/
//Date created:
#include<stdio.h>
#include<string.h>
#define MAX 100
typedef struct
{
char ten[80];
char matkhau[25];
}TaiKhoan;
TaiKhoan danhsach[MAX];
int tongso=1,ss;
char thoat='2';

//nguyen ham
void menu_admin();
void menu_user();
int dangnhap(char *ten, char *matkhau);
void admin_add(TaiKhoan danhsach[]);
void admin_xoa(TaiKhoan danhsach[]);
void admin_in(TaiKhoan danhsach[]);
void user_doi(int a);
//ham dang nhap
int dangnhap(char *ten,char *matkhau)
{
	int i;

	for (i=1;i<=tongso;i++)
		if ((strcmp(ten,danhsach[i].ten)==0)&&(strcmp(danhsach[i].matkhau,matkhau))==0){
		ss=i;
		return 1;
		}
		return 0;
}
// menu ADMIN
void menu_admin()
{
	char kt;
	do{
		printf("\nBan dang la ADMIN:");
		printf("\n1. Them");
		printf("\n2. Xoa");
		printf("\n3. In");
		printf("\n4. Dang xuat");
		printf("\n5. THOAT");
		printf("\nBan chon?: ");scanf("%c%*c",&kt);
		switch(kt)
		{
			case '1':admin_add(danhsach);break;
			case '2':admin_xoa(danhsach);break;
			case '3':admin_in(danhsach);break;
			case '5': thoat='1';break;
		}
	} while(kt!='4'&&kt!='5');
	printf("\n------------------------------------------------------");
}
//xoa tai khoan
void admin_xoa(TaiKhoan danhsach[])
{
	char xoa_ten[MAX];
	int i,j,kt=0;
	printf("\nXOA TAI KHOAN THEO TEN DANG NHAP");
	printf("\nNhap ten tai khoan muon xoa: ");scanf("%s%*c",xoa_ten);
	for (i=1;i<=tongso;i++)
		if(strcmp(xoa_ten,danhsach[i].ten)==0)
			{
				for (j=i;j<tongso;j++)
				danhsach[j]=danhsach[j+1];
				break;
			} kt++;
	if (kt==tongso) printf("\nTai khoan can xoa khong ton tai!");
	else {
		printf("\n Xoa thanh cong!");
		tongso--;
	}
	printf("\n------------------------------------------------------");
}
// them tai khoan
void admin_add(TaiKhoan danhsach[])
{
	
	tongso++;
	printf("\nNGUOI DUNG MOI %d",tongso);
	printf("\nNhap ten ng dung moi : ");scanf("%s%*c",danhsach[tongso].ten);
	printf("\nNhap pass ng dung moi: ");scanf("%s%*c",danhsach[tongso].matkhau);
	printf("\n------------------------------------------------------");
}
// in danh sach tai khoan
void admin_in(TaiKhoan danhsach[])
{
	int i;
	printf("\nDANH SACH TAI KHOAN");
	printf("\n%-30s%-30s","Ten tai khoan","Mat Khau");
	for (i=1;i<=tongso;i++)
			printf("\n%-30s%-30s",danhsach[i].ten,danhsach[i].matkhau);
	printf("\n------------------------------------------------------");
}
// munu USER
void menu_user()
{
	char kt;
	do
	{
		printf("\n BAN LA USER: %s",danhsach[ss].ten);
		printf("\nMENU:");
		printf("\n1. Doi mat khau");
		printf("\n2. Dang xuat");
		printf("\n3. THOAT");
		printf("\nBan chon?: ");scanf("%c%*c",&kt);
		switch(kt)
		{
			case '1':user_doi(ss);break;
			case '3':thoat='1';break;
		}
	} while ((kt!='2')&&(kt!='3'));
	printf("\n------------------------------------------------------");
}
// doi mat khau
void user_doi(int a)
{
	char new[100];
	printf("\nDOI MAT KHAU");
	printf("\nTen:%-25s  Matkhau: %-25s ",danhsach[ss].ten,danhsach[ss].matkhau);
	do
	{
		printf("\nMat khau moi: ");
		scanf("%s%*c",new);
		if (strcmp(new,danhsach[ss].matkhau)==0) printf("\nGiong mat khau cu, xin doi lai");
	}
	while (strcmp(new,danhsach[ss].matkhau)==0);
	strcpy(danhsach[ss].matkhau,new);
	printf("\nDoi thanh cong, mat khau moi la: %s",danhsach[ss].matkhau);
	printf("\n--------------------------------------------");
	 
}
// chuong trinh chinh
main()
{
	char id[MAX],pass[MAX];
	strcpy(danhsach[1].ten,"admin");
	strcpy(danhsach[1].matkhau,"admin");
	int i,dem=0;
	do
	{
		printf("\nTen dang nhap: ");scanf("%s%*c",id);
		printf("\nMat khau     : ");scanf("%s%*c",pass);
		if (dangnhap(id,pass)==1)
			{
				printf("\nDang nhap thanh cong!!");
				if (strcmp(id,"admin")==0) menu_admin();
				else menu_user();
			}
		else
		{
			 printf("\n Ten dang nhap khong ton tai!! moi nhap lai");
			 dem++;
			 printf("\nBan da nhap sai %d/3 lan",dem);
			 printf("\n------------------------------------------");
		}
	}
	while ((thoat!='1')&&(dem!=3));
	printf("\nGOODBYE!!");
}
