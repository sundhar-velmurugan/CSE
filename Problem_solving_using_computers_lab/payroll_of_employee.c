#include <stdio.h>
#include <conio.h>

struct Employee
{
    int emp_id;
    char name[20];
    int pay;
};

void main()
{
    int i,n;
    printf("Number of employees: ");
    scanf("%d",&n);

    struct Employee s[n];

    for(i=0;i<n;i++)
    {
        printf("\nEmployee %d: \n ID: ",i+1);
        scanf("%d",&s[i].emp_id);
        printf("\nName: ");
        scanf("%s",&s[i].name);
        printf("\nPay: ");
        scanf("%d",&s[i].pay);
    }

    FILE *fp= fopen("C:\\Users\\Sundhar V\\Documents\\Codeblocks\\C\\employee_details.bin","w+b");

    if(fp==NULL)
    {
        printf("ERROR");
    }

    fwrite(s,sizeof(struct Employee),3,fp);
    fseek(fp,0,0);
    fread(s,sizeof(struct Employee),3,fp);

    for(i=0;i<n;i++)
    {
        printf("\n\nEmployee %d\nID: %d \nName: %s \nPay: %d",i+1, s[i].emp_id,s[i].name,s[i].pay);
    }

    fclose(fp);
    getch();
}
