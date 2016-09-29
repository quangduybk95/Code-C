#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
typedef struct{
	int x;
	int y;
	int r;
	int giao[10];
	int sum;
}circle;
void nhaptay(circle C[],int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		printf("nhap toa do x cho duong tron %d : ",i);
		scanf("%d%*c",&C[i].x);
		printf("nhap toa do y cho duong tron %d : ",i);
		scanf("%d%*c",&C[i].y);
		printf("nhap ban kinh : ");
		scanf("%d",&C[i].r);
		printf(" thong so duong tron %d : x=%d y=%d R=%d \n",i,C[i].x,C[i].y,C[i].r);

	}
}
void ran(circle C[],int n)
{		srand(time(NULL));
	int i,a,b,c;
	for(i=1;i<=n;i++){

		C[i].x=rand()%10+1;

		C[i].y=rand()%10+1;

		C[i].r=rand()%10+1;
		printf(" thong so duong tron %d : x=%d y=%d R=%d \n",i,C[i].x,C[i].y,C[i].r);
	}
}
void cmp(circle C[],int n)
{
  int i,j,max=0;
  for(i=1;i<=n;i++)
    {
      C[i].sum=0;
    }
  for(i=1;i<=n;i++)
    {
      for(j=i+1;j<=n;j++)
	{
	  if(i==j)continue;
	  if(sqrt(pow(C[i].x-C[j].x,2)+pow(C[i].y-C[j].y,2))<(C[i].r+C[j].r))
	    {
	      printf("duong tron %d cat duong %d\n",i,j);
	      C[i].giao[j]++;
	      C[i].sum++,C[j].sum++;
	    }
	}
    }
  for(i=1;i<=n;i++)
    {
      if(max<C[i].sum)
	max=C[i].sum;
    }
  for(i=1;i<=n;i++)
    {
      if(C[i].sum==max)printf("duong tron giao nhieu nhat la %d\n",i);
    }

}

main(){
	circle *C;
	int n,i;
	char c;
	printf("moi nhap so luong duong tron : ");
	scanf("%d",&n);
	C=(circle*)malloc(n*sizeof(circle));
	if(C==NULL)
	{
		printf("loi cap phat bo nho\n");
		return 0;
	}
	do{
		printf("lua chon nhap tay or sinh ngau nhien\n");
		printf("1:nhap tay+so sanh\n2:sinh ngau nhien+sosanh\nq:quit\n");
		do{
			c=getchar();
			if(c!='1'&&c!='2'&&c!='q')printf("moi nhap lai\n");

		}while(c!='1'&&c!='2'&&c!='q');
		switch(c){
		case'1':nhaptay(C,n);
			cmp(C,n);
          break;
		case'2':ran(C,n);
			cmp(C,n);
			break;
		case'q':break;
		}

	}while(c!='q');
}

