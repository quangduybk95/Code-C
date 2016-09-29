#include <stdio.h>
main()
{
  printf("Forecast\n");
  printf("Today    ^.^       %d%c  %d%c\n", 23,'o',18,'o');
  printf("Tomorrow >.<       %d%c  %d%c\n", 22,'o',20,'o');
  printf("Tuesday  >.<       %d%c  %d%c\n", 22,'o',18,'o');
  printf("Tomorrow ^.^       %d%c  %d%c\n", 22,'o',19,'o');
  printf("Tomorrow >.<       %d%c  %d%c\n", 22,'o',19,'o');
  printf("             Extended Forecast\n"              );
  printf("\n");
  printf("Details\n");
  printf("\n");
  printf("Feels Like %d%c       ",21,'o');
  printf("Visibility %4.2f%s    ",4.01,"km");
  printf("Humidity   %d%c       ",83,'%');
  printf("UV Index   %d %s     \n",0,"(Low)");
  printf("Tonight - Overcast. Low around %d%s%3.1f%s  ",65,"F(", 18.3,"C).");
  printf("Winds E at 5 to 10 mph (8.0 to 16.1 kph).\n");
  printf("Tomorrow - Showers in the morning , then cloudy in the afternoon. High 71F (21.7C). Winds E at 5 to 10 mph (8.0 to\n");
  printf("16.1 kph). Chance of rain 30%%\n");

}
