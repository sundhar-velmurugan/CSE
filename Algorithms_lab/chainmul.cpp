#include<iostream>
#include<conio.h>
#include<limits.h>
using namespace std;

class chain{
    int **dpt, n, *d, **table;
public:
    void create();
    void fillt(int **dpt, int **table);
    int cmm(int **dpt, int i, int j);
};

void chain:: create(){
    cout<<"Enter the number of matrices: ";
    cin>>n;
    int **dpt=new int* [n+1];
    for (int i=0; i<=n; i++){
        dpt[i]=new int[n+1];
    }
    int **table=new int* [n+1];
    for (int i=0; i<=n; i++){
        table[i]=new int[n+1];
    }
    d=new int[n+1];

    cout<<"Enter the orders: "<<endl;
    for(int i=0; i<=n; i++){
        cout<<"d ["<<i<<"] : ";
        cin>>d[i];
    }

    fillt(dpt, table);
    for(int i=0; i<=n; i++){
        delete [] table[i];
    }
    delete [] table;
    for(int i=0; i<=n; i++){
        delete [] dpt[i];
    }
    delete [] dpt;
    delete [] d;
}

void chain :: fillt(int **dpt, int **table){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i>=j){
                dpt[i][j]=0;
                table[i][j]=0;
            }
        }
    }
    for(int s=1; s<=n-1; s++){
        int ti, tj;
        ti=n-s;
        tj=n;
        for(int t=0; t<n-s; t++){
            table[ti][tj]=cmm(dpt, ti, tj);
            ti--;
            tj--;
        }
    }
    cout<<"\nDynamic Programming Table: "<<endl;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout<<dpt[i][j]<<'\t';
        }
        cout<<endl;
    }
    cout<<"\n Tracking the Order table: "<<endl;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout<<table[i][j]<<'\t';
        }
        cout<<endl;
    }
}

int chain::cmm(int **dpt, int i, int j){
    int m, i1, i2, i3, exp, bk=0, flag=0;
    m=INT_MAX;
    for(int k=1; k<=j-1; k++){
        i1=i-1;
        i2=k;
        i3=j;
        if(i1<i2 && i2<i3){
            exp=dpt[i][k]+dpt[k+1][j]+(d[i1]*d[i2]*d[i3]);
            //m=min(m, exp);
            if(exp<=m){
                m=exp;
                flag=1;
            }
            else
                flag=0;
            if (flag==1){
                if(i2==i1+1 && i3==i2+1){
                    bk=0;
                }
                else{
                    bk=i2;
                }
            }
        }
    }
    dpt[i][j]=m;
    return bk;
}

int main(){
    chain A;
    A.create();
    getch();
    return 0;
}
