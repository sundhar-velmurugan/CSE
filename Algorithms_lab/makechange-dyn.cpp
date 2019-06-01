#include<iostream>
#include<conio.h>
#include<algorithm>
#include<limits.h>
using namespace std;
class mk{
    int **dpt, *coin, csize, amt, *ss, ssc;
public:
    void input();
    void create();
    int denom(int i){
        return coin[i];
    }
    void coinage(int **dpt, int i, int j);
};

void mk::input(){
    cout<<"Enter the amount: ";
    cin>>amt;
    cout<<"No of denominations: ";
    cin>>csize;
    coin = new int[csize];
    cout<<"Enter the denominations: "<<endl;
    for(int i=0; i<csize; i++){
        cin>>coin[i];
    }
    create();
    delete [] coin;
}


void mk::create(){
    int **dpt=new int* [csize];
    for (int i=0; i<=csize; i++){
        dpt[i]=new int[amt+1];
    }
    for(int i=0; i<csize; i++){
        dpt[i][0]=0;
    }
    cout<<"\nDynamic Programming Table: "<<endl;
    for(int i=0; i<csize; i++){
       for(int j=1; j<=amt; j++) {
            if(i==0 && j<denom(i))
                dpt[i][j]=INT_MAX;
            else if(i==0)
                dpt[i][j]=1+dpt[i][j-denom(i)];
            else if(j<denom(i))
                dpt[i][j]=dpt[i-1][j];
            else
                dpt[i][j]=min((1+dpt[i][j-denom(i)]), dpt[i-1][j]);
            cout<<dpt[i][j]<<'\t';
        }
        cout<<endl;
    }
    ssc=0;
    ss= new int[10];
    coinage(dpt, csize-1, amt);

    cout<<"\nSolution set"<<endl;
    for(int i=0; i<ssc; i++){
        cout<<i+1<<","<<ss[i]<<endl;
    }
    delete [] ss;
    for(int i=0; i<=csize; i++){
        delete [] dpt[i];
    }
    delete [] dpt;
}

void mk:: coinage(int **dpt, int i, int j){
    int t1, t2, r, c;
    t1=1+dpt[i][j-denom(i)];
    t2=dpt[i-1][j];
    if(t1<=t2){
        ss[ssc]=denom(i);
        ssc++;
        r=i;
        c=j-denom(i);
        if (r>=0 && c>0)
            coinage(dpt, r, c);
    }
    else{
        r=i-1;
        c=j;
        if (r>=0 && c>0)
            coinage(dpt, r, c);
    }
    return;
}

int main(){
    mk A;
    A.input();
    getch();
    return 0;
}
