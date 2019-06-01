#include<iostream>
#include<conio.h>
#include<limits.h>
using namespace std;

struct obj{
    int wt;
    int val;
}o[10];

int weight(int i){
    return o[i].wt;
}

int value(int i){
    return o[i].val;
}

class fks{
    int **dpt, objno, W, *ss, ssc;
public:
    void getdata();
    void create();
    void backtrack(int **dpt, int i, int j);
};

void fks:: getdata(){
    cout<<"Enter the number of objects: ";
    cin>>objno;

    cout<<"Enter details:"<<endl;
    for(int i=0; i<objno; i++){
        cout<<"Weight of Object "<<i+1<<':';
        cin>>o[i].wt;
        cout<<"Value of Object "<<i+1<<':';
        cin>>o[i].val;
    }

    cout<<"Enter the maximum weight: ";
    cin>>W;
    create();
}

void fks:: create(){
    int **dpt=new int* [objno];
    for (int i=0; i<objno; i++){
        dpt[i]=new int[W+1];
    }
    for(int i=0; i<objno; i++){
        dpt[i][0]=0;
    }
    cout<<"\nDynamic Programming Table: "<<endl;
    for(int i=0; i<objno; i++){
       for(int j=1; j<=W; j++) {
            if(i==0 && j>=value(i))
                dpt[i][j]=value(i);
            else if(i==0)
                dpt[i][j]=0;
            else if(weight(i)<=j)
                dpt[i][j]=max(dpt[i-1][j], value(i)+dpt[i-1][j-weight(i)]);
            else
                dpt[i][j]=dpt[i-1][j];
            cout<<dpt[i][j]<<'\t';
        }
        cout<<endl;
    }
    ssc=0;
    ss= new int[10];
    backtrack(dpt, objno, W);

    cout<<"\nSolution set"<<endl;
    for(int i=0; i<ssc; i++){
        if (ss[i]<objno)
            cout<<"Obj "<<ss[i]+1<<", ";
    }
    cout<<" are in solution set.";
    delete [] ss;
    for(int i=0; i<=objno; i++){
        delete [] dpt[i];
    }
    delete [] dpt;
}
void fks:: backtrack(int **dpt, int i, int j){
    int t1, t2, r, c;
    t1=dpt[i-1][j];
    t2=value(i)+dpt[i-1][j-weight(i)];
    if(t1<=t2){
        ss[ssc]=i;
        ssc++;
        r=i-1;
        c=j-weight(i);
        if (r>=0 && c>0)
            backtrack(dpt, r, c);
    }
    else{
        r=i-1;
        c=j;
        if (r>=0 && c>0)
            backtrack(dpt, i-1, j);
    }
    return;
}
int main(){
    fks A;
    A.getdata();
    getch();
    return 0;
}
