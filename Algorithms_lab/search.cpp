#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;

class plotsearch{
    int *a, *b, *c, *d, *e;
    int ar, br, cr, dr, er;
    double alt, blt, clt, dlt, elt, abit, bbit, cbit, dbit, ebit,
    abrt, bbrt, cbrt, dbrt, ebrt;
public:
    plotsearch(){
        a=new int[10];
        b=new int[100];
        c=new int[1000];
        d=new int[10000];
        e=new int[100000];

        ar=0, br=0, cr=0, dr=0, er=0;
        alt=0, blt=0, clt=0, dlt=0, elt=0;
        abit=0, bbit=0, cbit=0, dbit=0, ebit=0;
        abrt=0, bbrt=0, cbrt=0, dbrt=0, ebrt=0;
    }
    void populate();
    void linear();
    void linearsearch(int a[], int n, int key);
    void sorting();
    void mergesort(int a[], int p, int r);
    void merges(int a[], int p, int q, int r);
    void binaryiter();
    void ibin(int a[], int p, int r);
    void binaryrec();
    void rbin(int a[], int p, int r, int key);
    ~plotsearch(){
        delete[] a;
        delete[] b;
        delete[] c;
        delete[] d;
        delete[] e;
    }
};

void plotsearch:: populate(){
    cout<<"Number to be Searched: \n"<<endl;
    srand (time(NULL));
    for(int i=0; i<10; i++){
        a[i]= rand()%10+1;
    }
    ar=rand()%10+1;
    cout<<"'a' array: "<<ar<<endl;
    for(int i=0; i<100; i++){
        b[i]= rand()%100+1;
    }
    br=rand()%100+1;
    cout<<"'b' array: "<<br<<endl;
    for(int i=0; i<1000; i++){
        c[i]= rand()%1000+1;
    }
    cr=rand()%1000+1;
    cout<<"'c' array: "<<cr<<endl;
    for(int i=0; i<10000; i++){
        d[i]= rand()%10000+1;
    }
    dr=rand()%10000+1;
    cout<<"'d' array: "<<dr<<endl;
    for(int i=0; i<100000; i++){
        e[i]= rand()%100000+1;
    }
    er=rand()%100000+1;
    cout<<"'e' array: "<<er<<endl;
    linear();
    sorting();
    binaryiter();
    binaryrec();
}

void plotsearch::linear(){
    cout<<"-----------------------------------------------------------\n"<<endl;
    cout<<"Linear Search results: \n"<<endl;
    clock_t tStart = clock();
    linearsearch(a, 10, ar);
    alt=(double)(clock() - tStart)/CLOCKS_PER_SEC;
    alt*=1000;
    printf("Time taken: %.2fms\n", alt);

    clock_t tStart1 = clock();
    linearsearch(b, 100, br);
    blt=(double)(clock() - tStart1)/CLOCKS_PER_SEC;
    blt*=1000;
    printf("Time taken: %.2fms\n", blt);

    clock_t tStart2 = clock();
    linearsearch(c, 1000, cr);
    clt=(double)(clock() - tStart2)/CLOCKS_PER_SEC;
    clt*=1000;
    printf("Time taken: %.2fms\n", clt);

    clock_t tStart3 = clock();
    linearsearch(d, 10000, dr);
    dlt=(double)(clock() - tStart3)/CLOCKS_PER_SEC;
    dlt*=1000;
    printf("Time taken: %.2fms\n", dlt);

    clock_t tStart4 = clock();
    linearsearch(e, 100000, er);
    elt=(double)(clock() - tStart4)/CLOCKS_PER_SEC;
    elt*=1000;
    printf("Time taken: %.2fms\n", elt);
}

void plotsearch::linearsearch(int a[], int n, int key){
    int counter =0;
    for(counter = 0; counter < n; counter++){
        if(a[counter] == key){
            cout<<"Number "<<key<<" found at position "<<counter+1<<endl;
            break;
        }
    }
    if(counter == n){
     cout<<"Number "<<key<<" Not Present in Input Array"<<endl;
    }
}

void plotsearch:: sorting(){
    mergesort(a, 0, 10-1);
    mergesort(b, 0, 100-1);
    mergesort(c, 0, 1000-1);
    mergesort(d, 0, 10000-1);
    mergesort(e, 0, 100000-1);
}

void plotsearch:: mergesort(int a[], int p, int r){
    if(p<r){
        int q=(p+r)/2;
        mergesort(a, p, q);
        mergesort(a, q+1, r);
        merges(a, p, q, r);
    }
}

void plotsearch::merges(int a[], int p, int q, int r){
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

void plotsearch::binaryiter(){
    cout<<"-----------------------------------------------------------\n"<<endl;
    cout<<"Binary Iterative Search results in sorted array: \n"<<endl;

    clock_t tStart = clock();
    ibin(a, ar, 10);
    abit=(double)(clock() - tStart)/CLOCKS_PER_SEC;
    abit*=1000;
    printf("Time taken: %.2fms\n", abit);

    clock_t tStart1 = clock();
    ibin(b, br, 100);
    bbit=(double)(clock() - tStart1)/CLOCKS_PER_SEC;
    bbit*=1000;
    printf("Time taken: %.2fms\n", bbit);

    clock_t tStart2 = clock();
    ibin(c, cr, 1000);
    cbit=(double)(clock() - tStart2)/CLOCKS_PER_SEC;
    cbit*=1000;
    printf("Time taken: %.2fms\n", cbit);

    clock_t tStart3 = clock();
    ibin(d, dr, 10000);
    dbit=(double)(clock() - tStart3)/CLOCKS_PER_SEC;
    dbit*=1000;
    printf("Time taken: %.2fms\n", dbit);

    clock_t tStart4 = clock();
    ibin(e, er, 100000);
    ebit=(double)(clock() - tStart4)/CLOCKS_PER_SEC;
    ebit*=1000;
    printf("Time taken: %.2fms\n", ebit);
}

void plotsearch::ibin(int a[], int key, int r){
    int first=0, last, middle;
    last=r;
    middle = (first+last)/2;
	while (first <= last){
		if(a[middle] < key){
			first = middle + 1;
		}
		else if(a[middle] == key){
			cout<<"Number "<<key<<" found at location "<<middle+1<<endl;
			break;
        }
		else{
			 last = middle - 1;
		}
		middle = (first + last)/2;
	}
	if(first > last){
		cout<<"Number "<<key<<" is not present in the array"<<endl;
	}
}

void plotsearch:: binaryrec(){
    cout<<"-----------------------------------------------------------\n"<<endl;
    cout<<"Binary Recursive Search results in sorted array: \n"<<endl;

    clock_t tStart = clock();
    rbin(a, 0, 10, ar);
    abrt=(double)(clock() - tStart)/CLOCKS_PER_SEC;
    abrt*=1000;
    printf("Time taken: %.2fms\n", abrt);

    clock_t tStart1 = clock();
    rbin(b, 0, 100, br);
    bbrt=(double)(clock() - tStart1)/CLOCKS_PER_SEC;
    bbrt*=1000;
    printf("Time taken: %.2fms\n", bbrt);

    clock_t tStart2 = clock();
    rbin(c, 0, 1000, cr);
    cbrt=(double)(clock() - tStart2)/CLOCKS_PER_SEC;
    cbrt*=1000;
    printf("Time taken: %.2fms\n", cbrt);

    clock_t tStart3 = clock();
    rbin(d, 0, 10000, dr);
    dbrt=(double)(clock() - tStart3)/CLOCKS_PER_SEC;
    dbrt*=1000;
    printf("Time taken: %.2fms\n", dbrt);

    clock_t tStart4 = clock();
    rbin(e, 0, 100000, er);
    ebrt=(double)(clock() - tStart4)/CLOCKS_PER_SEC;
    ebrt*=1000;
    printf("Time taken: %.2fms\n", ebrt);
}

void plotsearch:: rbin(int a[], int p, int r, int key){
    int middle;
    if (p > r){
        cout<<"Number "<<key<<" is not present in the array"<<endl;
        return;
    }
    middle = (p + r) / 2;
    if (a[middle] == key){
        cout<<"Number "<<key<<" found at location "<<middle+1<<endl;
    }
    else if (a[middle] > key){
        rbin(a, p, middle - 1, key);
    }
    else if (a[middle] < key){
        rbin(a, middle + 1, r, key);
    }
}

int main(){
    plotsearch A;
    A.populate();
    getch();
    return 1;
}
