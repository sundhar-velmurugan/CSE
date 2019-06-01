#include <stdio.h>
#include <conio.h>

int grade (int mark)
{
    int count=0;

    if(mark>=90){
        printf("S");}
    else if(mark>=80 && mark<90){
        printf("A");
        count++;}
    else if(mark>=70 && mark<80){
        printf("B");}
    else if(mark>=60 && mark<70)
        printf("C");
    else if(mark>=50 && mark<60)
        printf("D");
    else
        printf("U");

    return count;
}

void main ()
{
    int mark,c, count=0, i;

    for(i=1; i<=10; i++)
    {
        printf("\nEnter the mark of the student %d: ",i);
        scanf("%d",&mark);
        printf("\nGrade: ");
        c=grade(mark);
        if(c==1)
        {
            count++;
        }
    }
    printf("\nNo of A grades: %d",count);
    getch();
}
