void strdoinoidung(char *s1, char *s2)
{
char st[100];
int i;
i = 0;
while (s1[i] != '\0')
{
st[i] = s1[i];
i++;
}
st[i] = '\0';
i = 0;
while (s2[i] != '\0')
{
s1[i] = s2[i];
i++;
}
s1[i] = '\0';
i = 0;
while (st[i] != '\0')
{
s2[i] = st[i];
i++;
}
s2[i] = '\0';
}
//////////////////////////////////// Copy xau s tu vi tri x den y
char *strcpyxy(char s1[100], char s[100], int x, int y)
{
int i, k=0;
for(i=(x-1);i<=(y-1);i++)
{
s1[k]=s[i];
k++;
}
s1[k]='\0';
return s1;
}
//////////////////////////////////// Xoa xau tai vi tri i
char *strdel(char *s, int i)
{
while (s[i] != '\0') 
{
s[i] = s[i+1];
i++;
}
return s;
}
//////////////////////////////////// Kiem tra dau cach
int ktdaucach(char *s)
{
int i=0;
while (s[i] != '\0')
{
if (s[i] == ' ') return 1;
i++;
}
return 0;
}
//////////////////////////////////// Xoa dau cach thua
void strtrim(char *s)
{
int i, j;
char st[500];
i = j = 1;
if (s[0] == ' ') j = 0;
else st[0] = s[0];
while (s[i] != '\0')
{
if (s[i] == ' ' && s[i-1] == ' ') 
{
i++;
continue;
}
st[j] = s[i];
j++;
i++;
}
if (st[j-1] == ' ') j--;
for (i=0; i<j; i++)
{
s[i] = st[i];
}
s[j] = '\0';
}
////////////////////////////////////// Viet hoa Ho Va Ten
void vietHoaTen(char *s)
{
int i = 0;
while (s[i] != '\0')
{
if ((i == 0 || s[i-1] == ' ') && s[i] >= 'a' && s[i] <= 'z') 
{ 
s[i] = s[i] + 'A' - 'a';
}
i++;
}
}
///////////////////////////////////////// Sap xep ten theo bang chu cai - dung thu vien <string.h>
typedef struct hovaten
{
char ho[15];
char dem[30];
char ten[15];
} hovaten;
hovaten tachHoVaTen(char *s) // Tach ho va ten
{
hovaten temp;
int i=0, j, len, x, y, k;
len = strlen(s);
for (i=0; i<len; i++) if (s[i] == ' ') break;
for (j=0; j<i; j++) temp.ho[j] = s[j];
x = i+1;
temp.ho[j] = '\0';
for (j=len-1; j>=0; j--) if (s[j] == ' ') break;
k = 0;
for (i=j+1; i<len; i++)
{
temp.ten[k] = s[i];
k++;
}
temp.ten[k] = '\0';
y = j-1;
k=0;
if (x<y)
for (i=x; i<=y; i++) 
{
temp.dem[k] = s[i];
k++;
}
temp.dem[k] = '\0';
return temp;
}
int namecmp(char *s1, char *s2) // so sanh ho va ten, giong strcmp
{
hovaten a, b;
a = tachHoVaTen(s1);
b = tachHoVaTen(s2);
if (strcmp(a.ten,b.ten) > 0)
return 1;
else 
if (strcmp(a.ten,b.ten) < 0)
return -1;
else
if (strcmp(a.dem,b.dem) > 0)
return 1;
else if (strcmp(a.dem,b.dem) < 0)
return -1;
else 
if (strcmp(a.ho,b.ho) > 0)
return 1;
else 
if (strcmp(a.ho,b.ho) < 0)
return -1;
return 0;
}
