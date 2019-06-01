#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;

class check{
    int *a, n;
public:
    check(){
        n=0;
    }
    void getdata();
    void putdata();
    void mergesort(int a[], int p, int r);
    void merges(int a[], int p, int q, int r);
    void func(int a[], int *dup, int *mis, int r);
    ~check(){};
};

void check :: getdata(){
    cout<<"Enter the number of elements: ";
    cin>>n;
    a=(int *)calloc(n, sizeof(int));
    cout<<"\nEnter the array elements:"<<endl;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    mergesort(a, 0, n-1);
}

void check:: putdata(){
    int duplicate=0, missing=0;
    func(a, &duplicate, &missing, n);
    if (duplicate==0 && missing==0)
        cout<<"The array is well formed."<<endl;
    else{
        cout<<"Duplicate: "<<duplicate<<'\n'<<"Missing: "<<missing<<endl;
        cout<<"It is a malformed array"<<endl;
    }
}

void check::func(int a[], int *dup, int *mis, int r){
    for (int i=1; i<r; i++){
        if(a[i]==a[i-1])
            *dup=a[i];
        else if(a[i]-2==a[i-1])
            *mis=a[i]-1;
    }
}

void check:: mergesort(int a[], int p, int r){
    if(p<r){
        int q=(p+r)/2;
        mergesort(a, p, q);
        mergesort(a, q+1, r);
        merges(a, p, q, r);
    }
}

void check::merges(int a[], int p, int q, int r){
    int t1=p, t2=q+1, *temp, x=0;
    temp=(int *)calloc(r-p+1, sizeof(int));
    while(t1<=q &&t2<=r){
        if (a[t1]<a[t2])
            temp[x++]=a[t1++];
        else
            temp[x++]=a[t2++];
    }
    while(t1<=q){
        temp[x++]=a[t1++];
    }
    while(t2<=r){
        temp[x++]=a[t2++];
    }
    for(t1=p, x=0; t1<=r; t1++, x++){
        a[t1]=temp[x];
    }
    free(temp);
}

int main(){
    check A;
    A.getdata();
    A.putdata();
    getch();
    return 1;
}
