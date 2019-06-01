#include<iostream>
#include<string.h>
#define MAX 10000
using namespace std;
class mul{
public:
    char * multiply(char [],char[]);
};
int main(){
    char a[MAX];
    char b[MAX];
    char *c;
    mul A;
    cout<<"Enter the first number : ";
    cin>>a;
    cout<<"Enter the second number : ";
    cin>>b;
    cout<<"Multiplication of two numbers : ";
    c = A.multiply(a,b);
    cout<<c;
    return 0;
}

char * mul:: multiply(char a[],char b[]){
    char mul[MAX];
    char c[MAX];
    char temp[MAX];
    int la,lb;
    int i,j,k=0,x=0,y;
    long int r=0;
    long sum = 0;
    la=strlen(a)-1;
    lb=strlen(b)-1;

    for(i=0;i<=la;i++){
            a[i] = a[i] - 48;
    }

    for(i=0;i<=lb;i++){
            b[i] = b[i] - 48;
    }

    for(i=lb;i>=0;i--){
         r=0;
         for(j=la;j>=0;j--){
             temp[k++] = (b[i]*a[j] + r)%10;
             r = (b[i]*a[j]+r)/10;
         }
         temp[k++] = r;
         x++;
         for(y = 0;y<x;y++){
             temp[k++] = 0;
         }
    }

    k=0;
    r=0;
    for(i=0;i<la+lb+2;i++){
         sum =0;
         y=0;
         for(j=1;j<=lb+1;j++){
             if(i <= la+j){
                 sum = sum + temp[y+i];
             }
             y += j + la + 1;
         }
         c[k++] = (sum+r) %10;
         r = (sum+r)/10;
    }
    c[k] = r;
    j=0;
    for(i=k-1;i>=0;i--){
         mul[j++]=c[i] + 48;
    }
    mul[j]='\0';
    return mul;
}
