#include <stdio.h>
#include <conio.h>
struct students{
    int regno;
    char name[50];
};
void main()
{
    int i;

    struct students s[2];

    printf("Enter the details:\n");
    for(i=0;i<2;i++){
        printf("\nStudent %d: \nRegno: ",i+1);
        scanf("%d",&s[i].regno);
        printf("\nName: ");
        scanf("%s",s[i].name);
    }

    FILE *fp= fopen("C:\\Users\\Sundhar V\\Documents\\Codeblocks\\C\\file_to_store_data.bin","w+b");
    if (fp==NULL){
        printf("\nERROR!!");
        return 0;
    }
    fwrite(s,sizeof(struct students),2,fp);
    fseek(fp,0,0);
    fread(s,sizeof(struct students),2,fp);
    for(i=0;i<2;i++){
        printf("\nRegno: %d\nName: %s",s[i].regno,s[i].name);
    }
    fclose(fp);
    getch();
}
