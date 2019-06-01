#include <stdio.h>
#include <conio.h>

void main()
{
    int CP, SP, i, count=0;

    for(i=1; i<=10; i++)
    {

    printf("\nEnter Cost price and selling price of product %d: ",i);
    scanf("%d%d",&CP,&SP);

    if (CP<SP)
    {
        printf("\nProfit: %d",(SP-CP));
        count++;
    }
    else
    {
        printf("\nLoss: %d",(CP-SP));
    }
    }
    printf("\nNo of profits: %d", count);
}
