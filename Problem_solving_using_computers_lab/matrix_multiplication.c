#include <stdio.h>
#include <conio.h>

void main()
{
    int i,j,k,a[3][3],b[3][3],c[3][3],s;

    printf("\nElements of matrix 1:\n");

    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("\nElements of matrix 2:\n");

    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }

    printf("\nMatrix 1:\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("\t%d",a[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix 2:\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("\t%d",b[i][j]);
        }
        printf("\n");
    }

    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
           s=0;
           for(k=0;k<3;k++)
           {
               s=s+a[i][k]*b[k][j];
           }
           c[i][j]=s;
        }
    }

    printf("\nProduct MARTIX:\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("\t%d",c[i][j]);
        }
        printf("\n");
    }
    getch();
}
