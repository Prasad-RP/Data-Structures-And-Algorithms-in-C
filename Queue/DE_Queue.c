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
void enqueue_r(struct queue *q, int val)
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

void enqueue_f(struct queue *q, int val)
{
    if(isFull(q))
    {
        printf("Queue Overflow\n");
    }
    else
    {
        q->arr[q->front]=val;
        q->front--;
    }
}

int dequeue_f(struct queue *q)
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

int dequeue_r(struct queue *q)
{
    int a=-1;
    if(isEmpty(q))
    {
        printf("Queue Underflow\n");
    }
    else
    {
        a=q->arr[q->rear];
        q->rear--;
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
        enqueue_r(q,data);
    }
    printf("Queue Elements before Operations\n");
    display(q);
    int ch,info;
    do{
    printf("Double Ended Queue operations\n");
    printf("\nEnter Your chice\n 1.Enqueue from rear\n2.Enqueue from front\n3.Dequeue from front\n4.dequeue from rear\n5.Exit: ");
    scanf("%d",&ch);
    switch(ch) {
    case 1:
        printf("Enter element to Enqueue from rear: \n");
        scanf("%d",&info);
        enqueue_r(q,info);
        printf("Element %d Is Enqueued in Queue successfully\n",info);
        printf("Queue Elements After Enqueue\n");
        display(q);
        break;
    case 2:
        printf("Enter element to Enqueue from front: \n");
        scanf("%d",&info);
        enqueue_f(q,info);
        printf("Element %d Is Enqueued in Queue successfully\n",info);
        printf("Queue Elements After Enqueue\n");
        display(q);
        break;    
    case 3:
        printf("Dequeued Element from front= %d \n",dequeue_f(q));
        printf("Queue Elements After Dequeue\n");
        display(q);
        break;
      case 4:
        printf("Dequeued Element from rear= %d \n",dequeue_r(q));
        printf("Queue Elements After Dequeue\n");
        display(q);
        break;  
        case 5:
        break;
    }
    }while(ch!=5);
}