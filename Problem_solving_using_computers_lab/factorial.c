#include <stdio.h>
#include <conio.h>

int fact (int x)
{
    if (x==0)
        return 1;
    else
        return (fact(x-1)*x);
}

void main()
{
    int x,f;

    printf("\nEnter the number: ");
    scanf("%d",&x);

    f=fact(x);

    printf("Factorial of %d : %d",x,f);

    getch();
}
