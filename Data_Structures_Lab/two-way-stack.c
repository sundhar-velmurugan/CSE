#define MAX 20

struct TS{
    int arr[MAX];
    int top1, top2;
};

int empty1(struct TS *s){
    if (s->top1==-1)
        return 1;
    else
        return 0;
}
int empty2(struct TS *s){
    if (s->top2==MAX)
        return 1;
    else
        return 0;
}
int full(struct TS *s){
    if (s->top1==s->top2-1)
        return 1;
    else
        return 0;
}
int push1(struct TS *s, int data){
    if (full(s))
        return 0;
    else{
        s->top1+=1;
        s->arr[s->top1]=data;
        return 1;
    }
}
int push2(struct TS *s, int data){
    if (full(s))
        return 0;
    else{
        s->top2-=1;
        s->arr[s->top2]=data;
        return 1;
    }
}
int pop1(struct TS *s, int *data){
    if (empty1(s))
        return 0;
    else{
        *data=s->arr[s->top1];
        s->top1-=1;
        return 1;
    }
}
int pop2(struct TS *s, int *data){
    if (empty2(s))
        return 0;
    else{
        *data=s->arr[s->top2];
        s->top2+=1;
        return 1;
    }
}
int peek1(struct TS *s, int *data){
    if (empty1(s))
        return 0;
    else{
        *data=s->arr[s->top1];
        return 1;
    }
}
int peek2(struct TS *s, int *data){
    if (empty2(s))
        return 0;
    else{
        *data=s->arr[s->top2];
        return 1;
    }
}
