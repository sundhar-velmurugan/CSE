#include<iostream.h>
#include<conio.h>

class area
{
public:
void area1(int a)
{
cout<<a*a;
}
void area1(int a,int b)
{
cout<<a*b;
}
};
void main()
{
clrscr();
area obj;
obj.area1(5);
cout<<"\n";
obj.area1(20,30);
getch();
}