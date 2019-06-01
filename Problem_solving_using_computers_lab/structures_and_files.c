#include <stdio.h>
#include <conio.h>

struct Student
{
    int regno;
    char name[50];
    float cgpa;
};

void main()
{
    int i,n;
    FILE *fp;

    printf("\nEnter the number of students: ");
    scanf("%d",&n);

    struct Student s[n];

    for(i=0;i<n;i++)
    {
        printf("Reg no: ");
        scanf("%d",&s[i].regno);
        printf("Name: ");
        scanf("%s",s[i].name);
        printf("CGPA: ");
        scanf("%f",&s[i].cgpa);
    }
    fp = fopen("C:\\Users\\Sundhar V\\Documents\\Codeblocks\\saved_data_from_struct.txt","w+");

    for(i=0;i<n;i++)
    {
        fprintf(fp,"%d\t%s\t%f\n",s[i].regno,s[i].name,s[i].cgpa);
    }

    fseek(fp,0,0);

    i=0;

    while((fscanf(fp,"%d%s%f",&s[i].regno,&s[i].name,&s[i].cgpa))!= -1)
    {
        printf("Reg no: %d\tName: %s\tCGPA: %f\n",s[i].regno,s[i].name,s[i].cgpa);
        i++;
    }

    fclose(fp);

}
