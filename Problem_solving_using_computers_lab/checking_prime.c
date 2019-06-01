#include<stdio.h>
#include<conio.h>

void main()
{
    int x,i,k=0;

    printf("\nEnter the number: ");
    scanf("%d",&x);

    for(i=2;i<=x/2;i++)
    {
        if(x%i==0)
        {
            k++;
            break;
        }
    }
    if(k>0)
    {
        printf("NOT PRIME");
    }
    else{
        printf("IT IS A PRIME");
    }
    getch();
}
