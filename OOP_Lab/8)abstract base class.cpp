#include <iostream>
#include <conio.h>
using namespace std;

class Base{     //pure abstract class
public:
    virtual void display()=0;
};

class Derived : public Base{
public:
    void display(){
        cout<<"Displaying contents of the display() function in Derived class";
    }
};

int main(){
    Derived obj;
    obj.display();
    getch();
    return 1;
}
