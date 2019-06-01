//NOT WORKING

#include <stdio.h>
#include <conio.h>
#include <ctype.h>

void main()
{
    int count1=0, count2=0;
    char ch;

    FILE *f=fopen("C:\\Users\\Sundhar V\\Documents\\Codeblocks\\C\\count.txt","r");
    while ((ch=fgetc(f))!=EOF)
    {
        if(isspace(ch))
        {
            count1++;
        }
        if (ispunct(ch))
        {
            count2++;
        }
    }

    printf("\nNumber of words: %d\nNumber of lines: %d",count1,count2);

    getch();

}
