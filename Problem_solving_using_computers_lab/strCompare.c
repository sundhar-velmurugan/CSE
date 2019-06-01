#include<stdio.h>
#include<conio.h>
int strCompare(char *s1,char *s2)
{
    while(*s1==*s2 && *s1!='\0')
    {
     s1++;
     s2++;
    }
    return (*s1-*s2);
}
void main()
{
    char str1[100],str2[100];
    int result;
    printf("\nEnter the strings: \n");
    gets(str1);
    gets(str2);
    result=strCompare(str1,str2);
    printf("\n%d",result);
    if(result>0)
    {
        printf("\n string1 greater than string2");
    }else if(result == 0)
    {
        printf("\n string1 equal to string2");
    }else
    {
        printf("\n string1 less than string2");
    }
    getch();
}
