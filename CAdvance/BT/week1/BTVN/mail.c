#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

typedef struct data
{
  char email[40];
}elementtype;

void randomData(FILE *f1, FILE *f2, elementtype a[], int n)
{
  int i,kt1,kt2,count1,count2;
  char s1[81], s2[81];
  char user[20], domain[20], total[40];
  srand(time(NULL));
  for(i=0;i<n;i++)
    {
      rewind(f1); rewind(f2);
      count1=-1,count2=-1;
      kt1=rand()%25;
      while(fgets(s1,80,f1)!=NULL&&count1<=kt1)
        {
          if(count1==kt1)
            {
              fseek(f1,-strlen(s1),1);
              fscanf(f1,"%[^\n]%*c",user);
            }
          count1++;
        }
      kt2=rand()%25;
      while(fgets(s2,80,f2)!=NULL&&count2<=kt2)
        {
          if(count2==kt2)
            {
              fseek(f2,-strlen(s2),1);
              fscanf(f2,"%[^\n]%*c",domain);
            }
          count2++;
        }
      strcpy(a[i].email,user);
      strcat(a[i].email,domain);
    }
}

int compare(elementtype e1, elementtype e2)
{
  return strcmp((e1.email),(e2.email));
}

void swap(elementtype *e1, elementtype *e2)
{
  elementtype e;
  e=*e1;
  *e1=*e2;
  *e2=e;
}

void sort(elementtype a[], int l, int r) {
  if (r <= l) return;
  int i = l-1, j = r;
  int p = l-1, q = r;
  while(1)
    {
      while (compare(a[++i],a[r])<0);
      while (compare(a[r],a[--j])<0) if (j == l) break;
      if (i >= j) break;
      swap(&a[i],&a[j]);
      if (compare(a[i],a[r])==0) swap(&a[++p],&a[i]);
      if (compare(a[j],a[r])==0) swap(&a[--q],&a[j]);
    }
  swap(&a[i],&a[r]);
  j = i - 1;
  i = i + 1;
  int k;
  for (k = l ; k <= p; k++) swap(&a[k],&a[j--]);
  for (k = r-1; k >= q; k--) swap(&a[k],&a[i++]);
  sort(a, l, j);
  sort(a, i, r);
}

void writeData(FILE *f, elementtype a[], int n)
{
  int i;
  for(i=0;i<n;i++)
    fprintf(f,"%s\n",a[i].email);
}

void menu()
{
  printf("*********MENU************\n");
  printf("1. Sinh du lieu thu nghiem.\n");
  printf("2. Sap xep danh sach email,in & ghi vao file.\n");
  printf("3. Loai email trung, in &ghi vao file.\n");
  printf("0. Thoat.\n");
}

main()
{
  elementtype *a;
  int n,kt;
   printf("Nhap gioi han sinh email : "); scanf("%d%*c",&n);
   a=(elementtype*)malloc(n*sizeof(elementtype));
 do
   {
     menu();
     printf("Nhap lua chon : ");
     do
       {
         scanf("%d%*c",&kt);
         if(kt<0||kt>3) printf("Moi chon lai chuc nang : ");
       }while(kt<0||kt>3);
     switch(kt)
       {
       case 0:
         {
           printf("===>KET THUC CHUONG TRINH\n");
           break;
         }
         //sinh du lieu
       case 1:
         {
           int i;
           FILE *f1=fopen("user.txt","r");
           if(f1==NULL) return 0;
           FILE *f2=fopen("domain.txt","r");
           if(f2==NULL) return 0;
           printf("\nDang sinh du lieu....\n");
           randomData(f1,f2,a,n);
           for(i=0;i<n;i++)
           printf("%s\n",a[i].email);
           printf("===>Sinh du lieu xong.\n");
           fclose(f1); fclose(f2);
           break;
         }
       case 2:
         {
           int i,k=0,page=0,l=0;
           FILE *fw=fopen("mail.txt","w+");
           printf("Dang sap xep du lieu.....\n");
           printf("\nDanh sach \n");
           sort(a,0,n-1);
           for(i=0;i<n;i++)
             {
               k++;
               printf("\t\t%s\n",a[i].email);
               if(k%24==0||l==(n-k+1))
                 {
                   page++;
                   if((n-k)<24) l++;
                   printf("__________________ Trang %d________________\n",page);
                 }
             }
           printf("===>Sap xep xong.\n");
           if(fw==NULL) return 0;
           writeData(fw,a,n);
           fclose(fw);
           break;
         }
       case 3:
         {
           int i,j,k=1,t;
           elementtype *b;
           b=(elementtype*)malloc(n*sizeof(elementtype));
           strcpy(b[0].email,a[0].email);
           for(i=1;i<n;i++)
             {
               t=0;
               for(j=0;j<k;j++)
                 {
                   if(compare(a[i],b[j])==0) t=1;
                 }
               if(t!=1)
                 {
                   strcpy(b[k].email,a[i].email);k++;
                 }
             }
           FILE *f=fopen("mailnodup.txt","w+");
           if(f==NULL) return 0;
           for(j=0;j<k;j++)
             printf("%s\n",b[j].email);
           for(j=0;j<k;j++)
             fprintf(f,"%s\n",b[j].email);
           printf("===>Da ghi du lieu vao file mailnodup.txt.\n");
           fclose(f);
           free(b);
           break;
         }
       }
   }while(kt!=0);
 free(a);
}
