
#include<stdio.h>
main()
{ char phauthuat,c,*baohiem;
  int days,thuoc,tienphauthuat,t,phinoitru,thanhtoan;
  printf("Moi ban nhap vao thong tin sau \n");
  printf("So ngay nam vien la bao nhieu ?  ");scanf("%d",&days);
  printf("Tien thuoc can tra la bao nhieu ?  ");scanf("%d%*c",&thuoc);
  printf("Ban co phai phau thuat khong (c hoac k) ? ");scanf("%c%*c",&phauthuat);
  if (phauthuat=='c') {printf("Nhap tien phau thuat : ");scanf("%d%*c",&tienphauthuat);} else tienphauthuat=0;
  phinoitru=days*150000;t=phinoitru+tienphauthuat+thuoc;
  printf("Nhap loai bao hiem : ");scanf("%c",&c);
  switch (c)
    { case 'G' : thanhtoan=t*3/10;baohiem="Gold";break;
    case 'S' : thanhtoan=t*5/10;baohiem="Silver";break;
    case 'C' : thanhtoan=t*7/10;baohiem="Citizen";break;
    default : baohiem="Khong co bao hiem";thanhtoan=t;break;
    }
  printf("\tBill\t\t\n");
  printf("Tien thuoc : \t%d(VND)\t\n",thuoc);
  printf("Phi noi tru : \t%d(VND)\t\n",phinoitru);
  printf("Phi phau thuat : %d(VND)\t\n",tienphauthuat);
  printf("Tong cong : \t%d(VND)\t\n",t);
  printf("Bao hiem : \t%s\t\n",baohiem);
  printf("Thanh toan : \t%d(VND)\t\n",thanhtoan);
}