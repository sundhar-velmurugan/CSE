#include <stdio.h>
#include <conio.h>
void main()
{
    int i,j,n,mean=0,t;
    printf("\nEnter the number of elements: ");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for (i=0;i+1<n;i+=2){
        mean = mean + a[i]+a[i+1];
    }
    mean= mean/n;
    printf("Mean: %d", mean);
    for(i=0,j=n-1;i<j;i++,j--){
        while(a[i]<=mean){
            i++;
        }
        while(a[j]>mean){
            j--;
        }
        t=a[i];
        a[i]=a[j];
        a[j]=t;
        while(a[i]<=mean){
            i++;
        }
        while(a[j]>mean){
            j--;
        }
    }
    printf("\nThe ordered array : \n");
    for(i=0;i<n;i++){
        printf("\n%d",a[i]);
    }
    getch();
}
