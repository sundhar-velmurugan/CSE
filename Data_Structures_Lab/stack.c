#define MAX 10
struct Stack{
    int arr[MAX];
    int top;
};

int Full(struct Stack *s){
    if (s->top==MAX-1)
        return 1;
    else
        return 0;
}
int Empty(struct Stack *s){
    if (s->top==-1)
        return 1;
    else
        return 0;
}
int Push(struct Stack *s, int data){
    if (Full(s))
        return 0;
    else{
        s->top+=1;
        s->arr[s->top]=data;
        return 1;
    }
}
int Pop (struct Stack *s, int *data){
    if (Empty(s))
        return 0;
    else{
        *data=s->arr[s->top];
        s->top-=1;
        return 1;
    }
}
int Peek (struct Stack *s, int *data){
    if (Empty(s))
        return 0;
    else{
        *data=s->arr[s->top];
        return 1;
    }
}
