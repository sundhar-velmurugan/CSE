#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void main()
{
    int n,i;
    printf("\nEnter the number of terms:");
    scanf("%d",&n);
    printf("\nThe random numbers are:");
    for (i=1;i<=n;i++)
    {
        printf("\n%d) %d",i,rand());
    }
    getch();
}
