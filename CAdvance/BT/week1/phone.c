#include<stdio.h>
#include<time.h>
#include<string.h>
#define OUT "phone.txt"
#define TIME "runtime.txt"
typedef struct {
	int send;
	int receive;
	char time[40];
	int during;
} list;
list ds[10000000],dsa[10000000],dsb[10000000];
void rnd(int n)
{
	int i = 0;
	FILE *f;
	f = fopen(OUT,"w+");
	for(i = 1 ;i <= n ;i++ )
	{
		int send = (rand()%90000000)+9999999;
		int receive = (rand()%90000000)+9999999;
		int hh =  rand()%24;
		int mm =  rand()%60;
		int ss =  rand()%60;
		int during =  rand()%3600;
		fprintf(f,"09%d\t09%d\t%d:%d:%d\t%d\n",send,receive,hh,mm,ss,during);
	}
	fclose(f);
}
void rnd2(int k, int n)
{
	int i = 0;
	FILE *f;
	f = fopen(OUT,"a");
	for(i = k ;i <= n ;i++ )
	{
		int send = (rand()%90000000)+9999999;
		int receive = (rand()%90000000)+9999999;
		int hh =  rand()%24;
		int mm =  rand()%60;
		int ss =  rand()%60;
		int during =  rand()%3600;
		fprintf(f,"09%d\t09%d\t%d:%d:%d\t%d\n",send,receive,hh,mm,ss,during);
	}
	fclose(f);
}
int read()
{
	int j = 0;
	FILE *f;
	f = fopen(OUT,"r");
	while(!feof(f))
	{
		int send;
		int receive;
		char time[40];
		int during;
		int i = fscanf(f,"%d\t%d\t%s\t%d\n",&send,&receive,time,&during);
		if (i == 4)
		{
			dsa[j].send = dsb[j].send = ds[j].send = send;
			dsa[j].receive = dsb[j].receive = ds[j].receive = receive;
			strcpy(ds[j].time,time);
            strcpy(dsa[j].time,time);
            strcpy(dsb[j].time,time);
			dsa[j].during = dsb[j].during = ds[j].during = during;
			j++;
		}
	}
	fclose(f);
	printf("=>Doc xong va cho vao mang\n");
	return j;
}
// quich sort
void swap(list *a,list *b)
{
  list tmp=*a;
  *a=*b;
  *b=tmp;
}

int sosanh(list a, list b){
  if (a.during<b.during) return -1;
  if (a.during>b.during) return 1;
  return 0;
}

void quichsort(list a[], int left, int right)
{

  int i,j;
  list key;
  if(left<right)
    {
      key=a[(left+right)/2];
      i=left-1;j=right+1;
      do
        {
          do i++; while(sosanh(a[i],key)==-1);
          do j--; while (sosanh(a[j],key)==1);
          if (i<j) swap(&a[i],&a[j]);
        }
      while(i<j);
      swap(&a[left],&a[j]);
      quichsort(a,left,j);
      quichsort(a,j+1,right);
    }

 }
void save(int n)
{
	int i = 0;
	FILE *f;
	f = fopen(OUT,"w+");
	for(i=0 ;i <= n ;i++ )
	{
		fprintf(f,"0%d\t0%d\t%s\t%d\n",ds[i].send,ds[i].receive,ds[i].time,ds[i].during);
	}
	fclose(f);
}
// insert sort
void insertionsort(list a[],int n)
{
	int i, j;
	list next;
	for (i=0; i<n; i++) {
		next= a[i];
		for (j=i-1;j>=0 && next.during< a[j].during;j--)
			a[j+1] = a[j];
		a[j+1] = next;
	}
}
// selection sort
void selectionsort(list a[],int MAX)
{
  int i, j, min;
  list tmp;
  for (i = 0; i < MAX-1; i++)
	{
      min = i;
      for (j = i+1; j <=MAX-1 ; j++)
        if ( a[j].during < a[min].during)
          min = j;
      tmp= a[i];
      a[i]= a[min];
      a[min] = tmp;
	}
}
main()
{
  int n,k,m;
  srand(time(NULL));

  char kt;
  do
	{
      printf("MENU:\n");
      printf("1. Lay du lieu\n");
      printf("2. Sap xep\n");
      printf("3. Them du lieu\n");
      printf("0. EXIT\n");
      printf("hay chon yeu cau :");scanf("%c%*c",&kt);
      switch( kt){
      case '1': {
        printf("Nhap gioi han: ");scanf("%d%*c",&n);
        printf("Dang tao ds ...\n");
        rnd(n);
        printf("=>Tao ds xong\n");
        printf("Xin hay doi ...\n");
        n = read();
        printf("Co %d du lieu\n",n);
      } break;
      case '2':{

        time_t t1,t2;
        time(&t1);
        printf("Dang thuc hien..\n");
        quichsort(ds,0,n-1);
        time(&t2);
        int qtime = (int)(t2-t1);
        time(&t1);
        insertionsort(dsa,n-1);
        time(&t2);
        int qinsert = (int)(t2-t1);
        time(&t1);
        selectionsort(dsb,n-1);
        time(&t2);
        int qselect = (int)(t2-t1);
        printf("=>Chay lan 1: \n");
        printf("=>%d so\n Quicksort: %d s \n Insertionsort: %d s \n Selectionsort: %d s\n",n,qtime,qinsert,qselect);
        FILE *f2 = fopen(TIME,"w+");
        fprintf(f2,"=>Chay lan 1: \n");
        fprintf(f2,"=>Quicksort: %d s \n Insertionsort: %d s \n Selectionsort: %d s\n",qtime,qinsert,qselect);
        fclose(f2);
        save(n-1);
      }break;
      case '3':{
        printf("Them du lieu n%% ?:");scanf("%d%*c",&m);
        k = n;
        float tg = n * 11/10;
        n = (int) tg;
        printf("%d => %d \n",k,n);
        rnd2(k,n-1);
        printf("=>Tao ds xong\n");
        printf("Dang cho vao mang du lieu ...\n");
        n = read();
        printf("Co %d du lieu\n",n);
         time_t t1,t2;
        time(&t1);
        printf("Dang thuc hien..\n");
        quichsort(ds,0,n-1);
        time(&t2);
        int qtime = (int)(t2-t1);
        time(&t1);
        insertionsort(dsa,n-1);
        time(&t2);
        int qinsert = (int)(t2-t1);
        time(&t1);
        selectionsort(dsb,n-1);
        time(&t2);
        int qselect = (int)(t2-t1);
        printf("=>Chay lan 2: \n");
        printf("=>Quicksort: %d s \n Insertionsort: %d s \n Selectionsort: %d s\n",qtime,qinsert,qselect);
         FILE * f2 = fopen(TIME,"a");
        fprintf(f2,"=>Chay lan 2: \n");
        fprintf(f2,"=>%d so \n Quicksort: %d s \n Insertionsort: %d s \n Selectionsort: %d s\n",n,qtime,qinsert,qselect);
        fclose(f2);
        save(n-1);
      }break;
      }
	}
  while(kt!='0');
}
