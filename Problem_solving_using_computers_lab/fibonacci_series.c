#include <stdio.h>
#include <conio.h>

int fib(int n)
{
    if(n<=1)
        return n;
    else
        return (fib(n-1)+fib(n-2));
}

void main()
{
    int n,i,t;

    printf("\nNumber of terms: ");
    scanf("%d",&n);

    printf("\nTHE SERIES: ");
    for (i=0;i<n;i++)
    {
        printf("\n%d",fib(i));
    }
    getch();
}
