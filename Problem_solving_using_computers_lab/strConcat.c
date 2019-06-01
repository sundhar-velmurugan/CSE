#include<stdio.h>
#include<conio.h>
char *strConcat(char *str1,char *str2)
{
    char *p1=str1;
    char *p2=str2;
    while(*p1!='\0'){
        p1++;}
    while(*p2!='\0'){
        *p1=*p2;
        p1++;
        p2++;}
        *p1='\0';
    return str1;
}
void main()
{
    char *str1[100],*str2[100];
    printf("\nEnter the strings:\n");
    gets(str1);
    gets(str2);
    strConcat(str1,str2);
    printf("\nThe combined string is:");
    puts(str1);
    getch();
}
