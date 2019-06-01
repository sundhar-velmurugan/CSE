#include<stdlib.h>
int insertion(int arr[], int n){
    int hold, last, walker, current;
    last=n;
    current=2;
    while(current<=last){
        hold=arr[current];
        walker=current-1;
        while(walker>=1&&hold<arr[walker]){
            arr[walker+1]=arr[walker];
            walker-=1;
        }
        arr[walker+1]=hold;
        current+=1;
    }
    return 1;
}
int shell(int arr[], int n){
    int hold, current, incre, last, walker;
    last=n;
    incre=last/n;
    while(incre>0){
        current=1+incre;
        while(current<=last){
            hold=arr[current];
            walker=current-incre;
            while(walker>=1 && hold<arr[walker]){
                arr[walker+incre]=arr[walker];
                walker-=incre;
            }
            arr[walker+incre]=hold;
            current=current+1;
        }
        incre=incre/2;
    }
    return 1;
}
int selection(int arr[], int n){
    int hold, current, last, walker, smallest, temp;
    last=n;
    current=1;
    while(current<=last){
        walker=current+1;
        smallest=current;
        while(walker<=last){
            if(arr[walker]<arr[smallest]){
                smallest=walker;
            }
        }
        temp=arr[smallest];
        arr[smallest]=arr[current];
        arr[current]=temp;
        current+=1;
    }
    return 1;
}
int bubble(int arr[], int n){
    int hold, walker, last, current, temp;
    last=n;
    current=1;
    while(current<=last){
        walker=last;
        while(walker>current){
            if(arr[walker]<arr[walker-1]){
                temp=arr[walker-1];
                arr[walker-1]=arr[walker];
                arr[walker]=temp;
            }
            walker-=1;
        }
        current+=1;
    }
    return 1;
}
int count(int arr[], int n){
    int max, i;
    max=arr[1];
    for(i=2;i<=n;i++){
        if (arr[i]>max)
            max=arr[i];
    }
    int *cnt;
    cnt=calloc(sizeof(cnt), max);
    for (i=1;i<=max;i++){
        cnt[arr[i]]+=1;
    }
    return 1;
}
