#include<stdio.h>
#include<conio.h>

void main()
{
    int sum=0, i,n;

    printf("\nNo of terms: ");
    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        sum=sum+(i*i);
    }
    printf("\nSum: %d",sum);
}
