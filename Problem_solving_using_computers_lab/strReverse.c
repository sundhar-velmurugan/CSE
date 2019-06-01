#include <stdio.h>
#include <conio.h>
#include <string.h>
char *strReverse (char *str1)
{
    char c;
    char *p1=str1;
    char *p2;
    p2=p1+(strlen(str1)-1);
    while(p2>p1)
    {
        c=*p1;
        *p1=*p2;
        *p2=c;
        p2--;
        p1++;
    }
    return str1;
}
void main()
{
    char a[100],b[100];
    printf("\nEnter the string:");
    gets(a);
    *b=strReverse(a);
    printf("\nThe reversed string : %s",b);
    getch();
}
