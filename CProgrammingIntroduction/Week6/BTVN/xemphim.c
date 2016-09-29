#include<stdio.h>
main()
{      char name[10],thu[8];char *luatuoi,*thoigian;
  int tuoi,gt;float t;
  printf("Nhap ten phim : ");gets(name);
  printf("Nhap thoi gian xem phim la thu may : ");gets(thu);
  printf("Nhap tuoi cua nguoi mua ve : ");scanf("%d",&tuoi);
  if (tuoi<18) (luatuoi="tre em") ; else if (tuoi>=65) (luatuoi="nguoi gia");else (luatuoi="nguoi lon");
  if ((thu=="thu 7")||(thu=="chu nhat")) {gt=7;thoigian="cuoi tuan"; if (luatuoi=="tre em") (t=gt*0.5); else if (luatuoi=="nguoi gia") (t=gt*0.7);else (t=gt);}
  else {gt=10;thoigian="trong tuan"; if (luatuoi=="tre em") (t=gt*0.5); else if (luatuoi=="nguoi gia") (t=gt*0.7);else (t=gt);}

printf("Tuoi     \t\t: \t%d\n",tuoi); 
printf("Lua tuoi \t\t: \t%s\n",luatuoi);
printf("Thoi gian xem phim \t:\t%10s\n",thoigian);
printf("Gia ve \t\t\t:\t%.2f$\n",t);
}


