#include <stdio.h>
#include <conio.h>
void main()
{
    int n,i,j,t;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int a[n];
    scanf("\nEnter the elements: \n");
    for (i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(i=1,j=n;i<=n/2;i++,j--)
    {
        t=a[i];
        a[i]=a[j];
        a[j]=t;
    }
    printf("\nThe elements are: ");
    for (i=1;i<=n;i++){
        printf("\n%d",a[i]);
    }
    getch();
}
