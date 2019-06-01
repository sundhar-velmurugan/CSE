#include <iostream>
#include <conio.h>
using namespace std;

class Sample{
public:
    int x,y;
    Sample(){
        x=y=0;
    }
    Sample(int a){
        x=y=a;
    }
    Sample(int a,int b){
        x=a;
        y=b;
    }
};

int main(){
    Sample obj1;
    Sample obj2(10);
    Sample obj3(10,20);

    cout<<"OBJ1's x and y value: "<<obj1.x<<','<<obj1.y<<endl;
    cout<<"OBJ2's x and y value: "<<obj2.x<<','<<obj2.y<<endl;
    cout<<"OBJ3's x and y value: "<<obj3.x<<','<<obj3.y<<endl;

    getch();
    return 1;
}
