#include<stdio.h>
#include<conio.h>
#include<string.h>

void main()
{
    char a[15];
    int b=0, n, i, c;

    printf("\nNumber: ");
    scanf("%s",a);

    n=strlen(a);
    for(i=0;i<n;i++)
    {
        c=a[i]-'0';
        b=b*10+c;
    }
    printf("\nNumber: %d",b);
    getch();
}
