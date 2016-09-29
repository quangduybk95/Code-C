do
  {
    printf("\t\tMenu\n");
    printf("1.Bam phim 1 de \n");
    printf("2.Bam phim 2 de \n");
    printf("3.Bam phim 3 de \n");
    printf("4.Bam phim 4 de \n");
    printf("5.Bam phim 5 de \n");
    printf("\n");
    printf("Nhap phim chuc nang (1-5) : ");scanf("%d%*c",&ch);
    while((ch!=1)&&(ch!=2)&&(ch!=3)&&(ch!=4)&&(ch!=5))
      {
        printf("Ban nhap sai ,moi ban nhap lai (1-5) : ");
        scanf("%d%*c",&ch);
      }
    switch(ch)
      {
      case 1 :
      case 2 :
      }
  }
 while(ch!=5);
