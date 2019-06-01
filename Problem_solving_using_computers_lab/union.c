#include<stdio.h>
#include<conio.h>
#include<string.h>
union data
{
    int i;
    float f;
    char s[100];
};
int main()
{
    union data data1;
    printf("\nEnter the integer: ");
    scanf("%d",&data1.i);
    printf("\nThe integer is: %d",data1.i);
    printf("\nEnter the floating point value: ");
    scanf("%f",&data1.f);
    printf("\nThe floating point value is: %f",data1.f);
    printf("\nEnter the word: ");
    scanf("%s",&data1.s);
    printf("\nThe word is: %s",data1.s);
    getch();
    return 0;
}
