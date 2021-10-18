#include<stdio.h>
#include<stdlib.h>
struct cqueue
{
    int size;
    int front;
    int rear;
    int* arr;
};
int isFull(struct cqueue *q)
{
    if((q->rear+1)%q->size==q->front)
    {
        return 1;
    }
    return 0;
}
int isEmpty(struct cqueue *q)
{
    if(q->rear==q->front)
    {
        return 1;
    }
    return 0;

}
void enqueue(struct cqueue *q, int val)
{
    if(isFull(q))
    {
        printf("Queue Overflow\n");
    }
    else
    {
        q->rear=(q->rear+1)%q->size;
        q->arr[q->rear]=val;
        printf("Enqueued Element: %d\n", val);
    }

}
int dequeue(struct cqueue *q)
{
    int a=NULL;
    if(isEmpty(q))
    {
        printf("Queue Underflow\n");
    }
    else
    {
        q->front=(q->front+1)%q->size;
        a=q->arr[q->front];
    }
    return a;
}
void display(struct cqueue *q)
{
    int j;
    for(j=q->front+1; j<=q->rear; j++)
    {
        printf("Element=%d \n",q->arr[j]);
    }
}
void main()
{
    struct cqueue *q;
    q=(struct cqueue *)malloc(sizeof(struct cqueue));
    q->size=4;
    q->front=q->rear=0;
    q->arr=(int *)malloc(q->size *sizeof(int));
    enqueue(q,1);
    enqueue(q,2);
    enqueue(q,3);
    printf("Elements of Queue After Enqueue\n");
    display(q);
    printf("Dequeued Element :%d\n",dequeue(q));
    printf("Dequeued Element :%d\n",dequeue(q));
    //   printf("Dequeued Element :%d\n",dequeue(q));
    printf("Dequeued Element :%d\n",dequeue(q));
    printf("Elements of Queue After Dequeue\n");
    display(q);
    printf("using circular Queue\n");
    enqueue(q,4);
    enqueue(q,5);
}