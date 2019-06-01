#define MAX 10
struct queue{
    int arr[MAX];
    int front, rear;
};
int full(struct queue *q){
    if ((q->rear+1)%MAX==q->front)
        return 1;
    else
        return 0;
}
int empty(struct queue *q){
    if (q->rear==-1 && q->front==-1)
        return 1;
    else
        return 0;
}
int enqueue(struct queue *q, int data){
    if (full(q))
        return 0;
    if(empty(q))
        q->front=q->rear=0;
    else
        q->rear=(q->rear+1)%MAX;
    q->arr[q->rear]=data;
}
int dequeue(struct queue *q, int *data){
    if (empty(q))
        return 0;
    *data=q->arr[q->front];
    if (q->front==q->rear)
        q->front=q->rear=-1;
    else
        q->front=(q->front+1)%MAX;
    return 1;
}
int extremes(struct queue *q, int *f, int *r){
    if (empty(q))
        return 0;
    else
        *f=q->arr[q->front];
        *r=q->arr[q->rear];
        return 1;
}

