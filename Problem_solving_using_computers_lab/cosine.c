#include <stdio.h>
#include <conio.h>

void main ()
{
    int i,n,sign=-1;
    float x, var, cos=1, t=1;

    printf("Enter X: ");
    scanf("%f",&x);

    printf("\nEnter n: ");
    scanf("%d",&n);

    var=x;

    x=(x*3.14)/180;

    for(i=1;i<n+1;i++)
    {
        t=(sign*cos*x*x)/((2*i)*(2*i-1));
        cos=cos+t;
        sign=sign*-1;
    }
    printf("\nCos of %f: %f",var,cos);
    getch();
}
