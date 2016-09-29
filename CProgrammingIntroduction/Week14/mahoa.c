#include<stdio.h>
#include<string.h>
void mahoa(char a[],int k)
{ int i,n=strlen(a);
for(i=0 ;i<=n-1 ;i++ )
  {
    if (((('z'-a[i])>=k)&&(a[i]!=' '))||((('Z'-a[i])>=k)&&(a[i]!=' '))) a[i]=a[i]+k;
    else if (((('z' - a[i])<k)&&(a[i]!=' '))||((('Z' - a[i])<k)&&(a[i]!=' '))) a[i]=a[i]-(26-k);}
 }
void giaima(char a[],int k)
{ int i,n=strlen(a);
for(i=0 ;i<=n-1 ;i++ )
  {
    if ((((a[i]-'a')<k)&&(a[i]!=' '))||(((a[i]-'A')<k)&&(a[i]!=' '))) a[i]=a[i]+(26-k);
    else if ((((a[i]-'a')>=k)&&(a[i]!=' '))||(((a[i]-'A')>=k)&&(a[i]!=' '))) a[i]=a[i]-k;}
 }


main()
{
  char a[100];int k,ch;
  do { printf("\t\t\t\tMenu\n");
    printf("\n");
    printf("1. Nhap xau va so buoc nhay bam phim 1\n");
    printf("2. Ma hoa chon phim 2 \n");
    printf("3. Giai ma chon phim 3 \n");
    printf("4. Ket thuc chon phim 4 \n");
    printf("\n");
    printf("Moi ban chon chuc nang (1-4) : ");scanf("%d%*c",&ch);
    printf("\n");
    while((ch!=1)&&(ch!=2)&&(ch!=3)&&(ch!=4)) {printf("Ban nhap sai moi ban nhap lai chuc nang (1-4) ");scanf("%d",&ch);printf("\n");}
    switch (ch) {
    case 1 : {printf("Nhap xau : ");gets(a);printf("Nhap so buoc nhay : ");scanf("%d",&k);break;}

      case 2 : {mahoa(a,k);
        printf("Xau sau ma hoa : %s \n",a);printf("\n");break;}
      case 3 :
        {giaima(a,k);
          printf("Xau sau giai ma : %s \n",a);printf("\n");break;}
      case 4 : {printf("Ket thuc \n");printf("\n");break;}
      }}
      while(ch!=4);}
