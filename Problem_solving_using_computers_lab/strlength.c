#include<stdio.h>
#include<conio.h>
extern int strLength (char *str)
{
    int len=0;
    while(*str!=0){
        ++len;
        str++;
    }
    return len;
}
void main()
{
    int length=0;
    char str1[100]={'\0'};
    printf("\nEnter the string:");
    gets(str1);
    length=strLength(str1);
    printf("\nThe length of the string : %d",length);
    getch();
}
