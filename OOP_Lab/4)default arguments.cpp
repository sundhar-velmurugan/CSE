#include<iostream>
#include<conio.h>
using namespace std;
class Compute{
private:
    unsigned long int result=0;
    int i;
public:
    int power(int number, int x=2){
        result=number;
        for(i=1;i<x;i++){
            result*=number;
        }
        return result;
    }
};

int main(){
    int num, pow, choice;
    Compute obj;
    cout<<"To find:\n1)Square of the number\n2)Higher powers"<<endl;
    cin>>choice;
    cout<<"Enter the number"<<endl;
    cin>>num;
    switch(choice){
        case 1:
            cout<<"Square of the number: "<<obj.power(num)<<endl;
            break;
        case 2:
            cout<<"Enter the power: "<<endl;
            cin>>pow;
            cout<<"The "<<pow<<"th power of "<<num<<": "<<obj.power(num,pow);
            break;
        default:
            cout<<"WORNG CHOICE!!!";
    }
    getch();
    return 1;
}
