#include<stdio.h>
#include<stdlib.h>
struct queue
{
    int size;
    int front;
    int rear;
    int* arr;
};
int isFull(struct queue *q)
{
    if(q->rear==q->size-1)
    {
        return 1;
    }
    return 0;
}
int isEmpty(struct queue *q)
{
    if(q->rear==q->front)
    {
        return 1;
    }
    return 0;

}
void enqueue(struct queue *q, int val)
{
    if(isFull(q))
    {
        printf("Queue Overflow\n");
    }
    else
    {
        q->rear++;
        q->arr[q->rear]=val;
    }
}
int dequeue(struct queue *q)
{
    int a=-1;
    if(isEmpty(q))
    {
        printf("Queue Underflow\n");
    }
    else
    {
        q->front++;
        a=q->arr[q->front];
    }
    return a;
}
void display(struct queue *q)
{
    int j;
    for(j=q->front+1; j<=q->rear; j++)
    {
        printf("Element=%d \n",q->arr[j]);
    }

}
void main()
{   int n,i,data;
    struct queue *q;
    q=(struct queue *)malloc(sizeof(struct queue));
    q->size=100;
    q->front=q->rear=-1;
    q->arr=(int *)malloc(q->size *sizeof(int));
    printf("Enter Size of Queue: ");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        printf("Enter Element For Index %d: ",i);
        scanf("%d",&data);
        enqueue(q,data);
    }
    printf("Queue Elements before Operations\n");
    display(q);
    int ch,info;
    do{
    printf("\nEnter Your chice\n 1.Enqueue\n 2.Dequeue\n 3.IsEmpty\n 4.IsFull\n");
    scanf("%d",&ch);
    switch(ch) {
    case 1:
        printf("Enter element to Enqueue\n");
        scanf("%d",&info);
        enqueue(q,info);
        printf("Element %d Is Enqueued in Queue successfully\n",info);
        printf("Queue Elements After Enqueue\n");
        display(q);
        break;
    case 2:
        printf("Dequeued Element= %d \n",dequeue(q));
        printf("Queue Elements After Dequeue\n");
        display(q);
        break;
    case 3:
        printf("%d ",isEmpty(q));
        break;
    case 4:
        printf("%d ",isFull(q));
        break;
        case 5:
        break;
    }
    }while(ch!=5);
}