#include<stdio.h>
#include<conio.h>

void main()
{
    int dec,hex[50],i=1,r,j;
    long int bin;
    printf("Binary :");
    scanf("%ld",&bin);

    while(bin!=0)
    {
        r=bin%10;
        dec=dec+r*i;
        i=i*2;
        bin=bin/10;
    }
    i=0;
    r=0;
    while(dec!=0)
    {
        r=dec%16;
        if(r>9)
        {
            r=r+55;
        }
        else
        {
            r=r+48;
        }
        hex[i]=r;
        dec=dec/16;
        i++;
    }
    printf("\nHex: ");
    for(j=i-1;j>=0;j--)
    {
        printf("%d",hex[j]);
    }
}
