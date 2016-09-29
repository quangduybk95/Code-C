int main(void)
{
int a[3] = {17,289,4913}, *p, *q;
p = a;
q = p+2;
printf("a = %p\n",a);
printf("p = %p, q = %p\n", p, q);
printf("p trỏ đến %d và q trỏ đến %d\n", *p, *q);
printf("Khoảng cách con trỏ giữa p và q là %d\n", q-p);
printf("Khoảng cách nguyên giữa p và q là %d\n",(int)q-(int)p);
return 0;
}
