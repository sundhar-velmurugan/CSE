#include<iostream>
#include<conio.h>
using namespace std;
class Base{   //abstract class
public:
    float sum;
    virtual float average()=0;//pure virtual member function
    int add(int a, int b){
        sum = a+b;
        return sum;
    }
};

class Derived : public Base{
public:
    float average(){
        return (sum/2);
    }
};

int main(){
    int x, y;
    Derived obj;
    cout<<"Enter x and y"<<endl;
    cin>>x>>y;
    obj.add(x,y);
    cout<<"Average: "<<obj.average()<<endl;
    getch();
    return 1;
}
