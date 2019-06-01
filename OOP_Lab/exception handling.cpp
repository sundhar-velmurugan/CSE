#include<iostream>
#include<conio.h>
using namespace std;

int main(){
    int num, randomno;
    try{
        try{
            cin>>num;
            throw num;
            cout<<"This thing never gets executed."<<endl;
        }catch(int k){
            cout<<"Caught "<<k<<endl;
            randomno=5;
            throw randomno;
        }
    }catch(...){
        cout<<"Default exception."<<endl;
    }
    getch();
    return 1;
}
