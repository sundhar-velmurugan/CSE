#include <stdio.h>
#include <conio.h>
#include <math.h>

void main()
{
    int a,b,c;
    float x,y,root;

    printf("\nEnter the coefficient of x^2: ");
    scanf("%d",&a);
    printf("\nEnter the coefficient of x: ");
    scanf("%d",&b);
    printf("\nEnter the constant term: ");
    scanf("%d",&c);

    root= sqrt(b*b-4*a*c);

    x= (-b+root)/(2*a);
    y= (-b-root)/(2*a);

    printf("\nThe solution are: %f , %f",x,y);

    getch();
}
