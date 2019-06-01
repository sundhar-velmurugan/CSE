#include <stdio.h>
#include <conio.h>
void main()
{
    int i=0,j=0,k=0,l=0,u=0,n=0,x=0,t=0,a[50]={'\0'};
    printf("\nEnter the number of elements in the array: ");
    scanf("%d",&n);
    printf("\nEnter the values: \n");
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\nEnter the value of k");
    scanf("%d",&k);
    l=0;
    u=n-1;
    while(l<u)
    {
        i=l;
        j=u;
        x=a[k];
        while((i<=k)&&(j>=k))
        {
                if (a[i]<x)
                    i++;
                if (a[j]>x)
                {
                    j--;
                }

                t=a[i];
                a[i]=a[j];
                a[j]=t;
                i++;
                j--;
        }
        if(j<k){
            l=i;}
        if(i>k){
            u=j;}
    }
    printf("\nThe %dth smallest element is %d",k,a[k]);
    getch();
}
