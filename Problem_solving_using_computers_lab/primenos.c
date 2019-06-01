#include<stdio.h>
#include<conio.h>
void main()
{
    int n,i=3,count,c;
    printf("\nEnter the number of prime numbers required: ");
    scanf("%d",&n);

    if(n>=1)
    {
        printf("\nThe first %d prime numbers are:\n%d",n,2);
    }
    for(count =2;count<=n;i++)
    {
        for(c=2;c<=i-1;c++)
        {
            if (i%c==0)
                break;
        }
            if(c==i)
            {
                printf("\n%d",i);
                count++;
            }

    }
    getch();
}
