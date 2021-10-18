#include<stdio.h>
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *front;
struct Node *rear;

void display(struct Node * front)
{
    struct Node *ptr=front;
    printf("\nElements of Queue\n");
    while (ptr != NULL)
    {
        printf("Element:%d\n", ptr->data);
        ptr = ptr->next;
    }
}
void enqueue(int val)
{
    struct Node *ptr=(struct Node*) malloc(sizeof(struct Node));
    if(ptr==NULL) {
        printf("Queue Overflow\n");
    }
    else {
        ptr->data=val;
        ptr->next=NULL;
        if(front==NULL)
        {
            front=rear=ptr;
        }
        else {
            rear->next=ptr;
            rear=ptr;
        }
    }
}
int dequeue()
{
    int val;
    struct Node *ptr=front;

    if(front==NULL) {
        printf("Queue Underflow\n");
    }
    else {
        front=front->next;
        val=ptr->data;
        free(ptr);
        return val;
    }
}
void main()
{
    int n,i, data;
    printf("Enter initial Size of Queue: ");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        printf("Enter Element at %d index: ");
        scanf("%d",&data);
        enqueue(data);
    }
    printf("Elements of Queue\n");
    display(front);
    int ch,info;
    do {
        printf("Enter Your choice\n");
        printf("1.Enqueue\n2.Dequeue\n3.Exit: ");
        scanf("%d",&ch);
        switch(ch) {
        case 1:
            printf("Enter Element to Enqueue: ");
            scanf("%d",&info);
            enqueue(info);
            printf("Queue After Enqueue\n");
            display(front);
            break;
        case 2:
            printf("Dequeued Element=%d\n",dequeue());
            printf("Queue After Dequeue\n");
            display(front);
            break;
        case 3:
            break;
        }
    } while(ch!=3);
}