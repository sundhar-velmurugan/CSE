#include<stdio.h>
#include<conio.h>
#define MAX 10
int a[MAX];
void hash(){
    int i;
    for (i=0;i<MAX; i++){
        a[i]=-1;
    }
}
int insert(int key, int num){
    int i, count=0, m;
    if(a[key]==-1){
        a[key]=num;
    }
    else{
        i=key+1;
      //  printf("---Test---");
        while(i!=key){
            if(a[i]!=-1){
                count++;
                i=(i+1)%MAX;
               // printf("\nCount: %d, i=%d\n", count, i);
            }else{
                a[i]=num;
                break;
            }
            if(count==MAX)
                return 0;
        }
    }
    return 1;
}
int deleteh(int key, int element){
    int i, count=0;
    if(a[key]==element){
        a[key]=-1;
    }
    else{
        i=key+1;
        while(i!=key){
            if(a[i]!=element){
                count++;
                i=(i+1)%MAX;
            }
            if (a[i]==element){
                a[i]=-1;
                break;
            }
            if(count==MAX)
                return 0;
        }
    }
}
void main(){
    int j, k, l;
    hash();
    for(k=0;k<5;k++){
        scanf("%d", &j);
        l=j%MAX;
     //   printf("KEy: %d\n", l);
        insert(l, j);
    }
    for(j=0;j<MAX;j++){
        printf("\nHASH: %d", a[j]);
    }
    deleteh(22%MAX, 22);
    for(j=0;j<MAX;j++){
        printf("\nHASH: %d", a[j]);
    }
}
