#include <stdio.h>
#include <conio.h>

void main()
{
    int i,j,n,t,a[50];

    printf("\nNumber of elements:");
    scanf("%d",&n);

    printf("\nEnter the elements: \n");

    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
    }

    printf("\nSORTED ARRAY: ");

    for(i=0;i<n;i++)
    {
        printf("\n%d",a[i]);
    }

    printf("\nSmallest number: %d\nLargest number: %d",a[0],a[n-1]);
    getch();
}
