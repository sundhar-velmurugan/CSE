#include<iostream>
#include<conio.h>
#include<fstream>
#include<string.h>
#include<stdlib.h>
using namespace std;

int main(){
    string line;
    int i, no;
    fstream fp;

    fp.open("sample.bin", ios::out|ios::in|ios::binary);
    cout<<"Number of names: ";
    cin>>no;
    fflush(stdin);
    for(i=0;i<no;i++){
        cout<<"Enter name "<<i+1<<": ";
        getline(cin, line);
        fp<<line<<endl;
    }

    fp.seekp(0);
    i=0;
    cout<<"Contents of the file: "<<endl;
    while(getline(fp, line)){
        if (i<no){
            cout<<line<<endl;
        }
        i+=1;
    }
    fp.close();
    getch();
    return 1;
}
