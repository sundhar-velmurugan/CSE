//Non inline member function
#include<iostream.h>
#include<conio.h>
class phone
{
   char name[15];
   int calls;
   int max;
   int rem;
   public:
	  void getdata();
	  void remaining();
	  void display();

};
void phone::getdata()
{
    cout<<"\nEnter the customer name:";
    cin>>name;
    cout<<"\nEnter the calls:";
    cin>>calls;
    cout<<"\nEnter the maximum no of calls:";
    cin>>max;
}
void phone::remaining()
{
   rem=max-calls;
}
void phone::display()
{
    cout<<"\nCustomer name is:"<<name;
    cout<<"\nNo of calls is:"<<calls;
    cout<<"\nMaxcalls is :"<<max;
    cout<<"\nRemianing calls is:"<<rem;
}
int size=50;
void main()
{
   int n,i;
   phone p[15];
   clrscr();
   cout<<"\nEnter the no of customer:";
   cin>>n;
   for(i=1;i<=n;i++)
   {
      p[i].getdata();
      p[i].remaining();
      cout<<"\n";
   }
   for(i=1;i<=n;i++)
   {
   p[i].display();
   }
   getch();
}