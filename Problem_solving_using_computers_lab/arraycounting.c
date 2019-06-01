#include <stdio.h>
#include <conio.h>
void main()
{
    int student[100],mark[101]={0},i,j,s;
    printf("\nEnter the number of students:");
    scanf("%d",&s);
    for(i=0;i<s;i++)
    {
        printf("\nEnter th mark for student %d :",i+1);
        scanf("%d",&student[i]);
        j=student[i];
        mark[j]=mark[j]+1;
    }
    for(j=0;j<101;j++)
    {
        printf("\nStudents who scored %d marks : %d",j,mark[j]);
    }
    getch();
}
