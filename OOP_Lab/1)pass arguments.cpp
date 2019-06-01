//Returning a value from a function
#include<iostream.h>
#include<conio.h>
int sum(int num1,int num2)
{
return(num1+num2);
}
void main()
{
int val1,val2,total;
clrscr();
cin>>val1>>val2;
total=sum(val1,val2);
cout<<"Total is"<<total;
getch();
}






