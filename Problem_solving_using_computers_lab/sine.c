#include <stdio.h>
#include <conio.h>

void main()
{
    float sine, x, val, t;
    int sign=-1, n, i;
    printf("Value of x: ");
    scanf("%f",&x);

    printf("\nNumber of terms: ");
    scanf("%d",&n);

    val=x;
    x=(3.14*x)/180;
    sine=x;
    t=x;

    for(i=1;i<=n;i++)
    {
        t=(t*sign*x*x)/(2*i+(2*i+1));
        sine=sine+t;
        sign=sign*-1;
    }

    printf("\nSine of %f : %f",val,sine);
    getch();
}
