#include <stdio.h>
#include <conio.h>
char *strCopy (char *src,char *dest)
{
    while (*src!='\0')
    {
        *dest=*src;
        dest++;
        src++;
    }
    *dest='\0';
    return dest;
}
void main()
{
    char str[100],t[100];
    printf("\nEnter the string: \n");
    gets(str);
    strCopy(str,t);
    printf("\nSource string: %s",str);
    printf("\nTarget string: %s",t);
    getch();
}
