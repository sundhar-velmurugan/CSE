#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
FILE *f1;
int size,offset=0;
unsigned int ba;
char a[10],b[10];
clrscr();
printf("\nEnter th base address:");
scanf("%u",&ba);
printf("\n OFFSET VARIABLE SIZE\n");
f1=fopen("ip.c","r");
while(!feof(f1))
{
fscanf(f1,"%s%s",a,b);
if(strcmp(a,"int")==0)
size=2;
else if(strcmp(a,"float")==0)
size=4;
else if(strcmp(a,"char")==0)
size=1;
else if(strcmp(a,"double")==0)
size=8;
printf("\n%u\t %s\t %d",ba,b,size);
ba+=size;
}
getch();
}
