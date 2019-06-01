#include<stdio.h>
#include<conio.h>

int fib(int n)
{
    if(n>2)
        return (fib(n-1)+fib(n-2));
    if (n==2)
        return 1;
    if (n==1)
        return 0;
}
void main()
{
    int n,t;
    printf("\nEnter the nth term: ");
    scanf("%d",&n);
    t=fib(n);
    printf("\nThe %dth fibonacci number is : %d",n,t);
    getch();
}
