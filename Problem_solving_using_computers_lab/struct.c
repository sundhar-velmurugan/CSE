#include <stdio.h>
#include <conio.h>
#include <string.h>

struct sturec
{
    char name[30];
    int rollno;
    char course[10];
    char branch[10];
};

void getdata(struct sturec stu);
void printdata(struct sturec *stu);

static char name[30];
static int r;
static char course[10];
static char branch[10];

int main()
{

struct sturec stu1;

getdata(stu1);
    strcpy(stu1.name,name);
    stu1.rollno=r;
    strcpy(stu1.course,course);
    strcpy(stu1.branch,branch);
printdata(&stu1);

getch();
return 0;
}

void getdata(struct sturec stu)
{

    printf("\nEnter the name: ");
    scanf("%[^\n]s",&name);
    printf("\nEnter the roll number:");
    scanf("%d",&r);
    printf("\nEnter the course name:");
    scanf("%s",&course);
    printf("\nEnter the branch name:");
    scanf("%s",&branch);
}

void printdata(struct sturec *stu)
{
    printf("\nName of the student : %s",stu->name);
    printf("\nRoll number : %d",stu->rollno);
    printf("\nCourse : %s",stu->course);
    printf("\nBranch : %s",stu->branch);
}
