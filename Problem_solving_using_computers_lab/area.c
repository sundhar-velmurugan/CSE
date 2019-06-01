//APPARENTLY POLYMORPHISM IS MOT FEASIBLE IN C

/*#include <stdio.h>
#include <conio.h>

int area (0.5,int a,int b)
{
    return (0.5*a*b);
}
int area (int a, int b)
{
    return (a*b);
}
int area (int a)
{
    return (a*a);
}

void main()
{
    int a,b,choice, k;

    printf("\nENTER CHOICE: \n1. Triangle\n2.Rectangle\n3. Square\n");
    scanf("%d",&choice);

    printf("\nEnter the dimensions: ");

    if (choice!=3)
    {
        scanf("%d%d",&a,&b);
    }
    else
    {
        scanf("%d",a);
    }
    switch(choice)
    {
    case 1:
        k=area(0.5,a,b);
        break;

    case 2:
        k=area(a,b);
        break;

    case 3:
        k=area(a);
        break;

    default:
        print("\nWrong CHOICE!!!");
        break;
    }
    printf("\nAREA: %d",k);
}
*/
