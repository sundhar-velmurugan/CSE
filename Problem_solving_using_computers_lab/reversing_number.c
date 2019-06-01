#include <stdio.h>
#include <conio.h>

void main()
{
    int num, rev=0, x;

    printf("Enter the number:");
    scanf("%d",&num);

    do
    {
       x=num%10;
       rev= rev*10 + x;
       num=num/10;
    }while(num!=0);

    printf("\nReversed number : %d",rev);
    getch();
}
