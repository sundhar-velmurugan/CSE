#include<stdio.h>
#include<conio.h>
void main()
{
    int d,n;
    printf("\nEnter the number: ");
    scanf("%d",&n);
    if (n%2==0)
        printf("\nThe smallest divisor is %d",2);
    else
    {
        d=3;
        while(n%d!=0 && d*d<n)
        {
            d=d+2;
        }
        if (n%d==0)
            printf("\nThe smallest divisor is %d",d);
        else
            printf("\nThe smallest divisor is %d",1);

    }
    getch();
}
