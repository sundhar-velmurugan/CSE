#include<stdio.h>
#include<conio.h>
void main()
{
    float n,m,num;
    n=0.0001;
    printf("\nEnter the number: ");
    scanf("%f",&num);
    for (m=0;m<num;m=m+n)
    {
        if(m*m>num)
        {
            m=m-n;
            break;
        }
    }
    printf("\nThe square root of the number %f is %f",num,m);
    getch();
}
