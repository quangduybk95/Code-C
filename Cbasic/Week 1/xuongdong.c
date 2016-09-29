#include <stdio.h>
#include <string.h>
main()
{
  int i;
 char s[100]="sap den trung thu roi";
  for (i=0;i<strlen(s);i++) if (s[i]==' ') printf("\n"); else printf("%c",s[i]);

}
