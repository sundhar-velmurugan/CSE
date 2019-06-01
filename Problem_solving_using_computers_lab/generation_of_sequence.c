#include <stdio.h>
#include <conio.h>

void main ()
{
    int i,n,t,a=0,b=1,c=1;

    printf("\nEnter the number of terms : ");
    scanf("%d",&n);

    printf("\nThe SERIES: ");
    for (i=0;i<n;i++)
    {
        if(i<=1)
            printf("\n%d",i);
        else if(i==2)
            printf("\n%d",1);
        else
        {
            t=a+b+c;
            printf("\n%d",t);
            a=b;
            b=c;
            c=t;
        }
    }
    getch();
}
