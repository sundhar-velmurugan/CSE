//and heap sort
#include<stdio.h>
#include<conio.h>
#define MAX 100
int heapsize=0, heap[MAX]={'\0'};
void insert(int data){
    int i;
    ++heapsize;
    heap[heapsize]=data;
    for (i=heapsize; heap[i/2]>data; i/=2){
            //printf("Inside: %d---\n", i);
        heap[i]=heap[i/2];
    }
 //   printf("outside: %d---\n", i);
    heap[i]=data;
}
int deletemin(){
    int min, last, child, i;
    min=heap[1];
    last=heap[heapsize--];
    for(i=1; i*2<=heapsize; i=child){
        child=i*2;
        if(child!=heapsize&&heap[child+1]<heap[child])
            child++;
        if(last>heap[child])
            heap[i]=heap[child];
        else
            break;
    }
    heap[i]=last;
    printf("\nMin: %d", min);
    return min;
}
void main(){
    int i, n, b[8];
    for (i=0;i<7;i++){
        scanf("%d", &n);
        insert(n);
    }
    for(i=1;i<=7;i++){
        b[i]=deletemin();
    }
    for(i=1;i<=7;i++){
        printf("\nResult: %d", b[i]);
    }
    getch();
}
