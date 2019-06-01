#include <stdio.h>
#include <conio.h>
void main()
{
    int i,j,student[101]={0},n;
    printf("Enter the number of students: ");
    scanf("%d",&n);
    int temp[n];
    printf("\nEnter the marks : \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&temp[i]);
        j=temp[i];
        student[j]=student[j]+1;
    }
    for(i=0;i<=100;i++)
    {
        printf("\n No of students scored %d : %d ",i,student[i]);
    }
    getch();
}
