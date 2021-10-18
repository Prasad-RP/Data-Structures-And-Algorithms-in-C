#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
}*head=NULL;
void display(struct Node * head)
{
struct Node *ptr= head;
    while (ptr != NULL)
    {
        printf("Element:%d\n", ptr->data);
        ptr = ptr->next;
    }
}
void Reverse(struct Node * head)
{
struct Node *p= head->next;
    while (p->next!= NULL)
    {
        p=p->next;
    }
    //at that point ptr is at last node
    printf("Reversed Linked List\n");
    while (p!= NULL)
    {
    printf("Element:%d\n", p->data);
        p = p->prev;// reverse traversal
        
    }
}
void create() {
    int info,i,n;
    struct Node *q,*ptr;
    printf("Enter Size of list: ");
    scanf("%d",&n);
    for(i=0; i<n; i++) {
        ptr = (struct Node *)malloc(sizeof(struct Node));
        printf("\nEnter data of node %d : ", i+1);
        scanf("%d", &info);
        ptr->data = info;
        ptr->prev=NULL;
        ptr->next=NULL;
        if(head==NULL) {
           head=ptr;
        }
        else {
        q=head;
        while(q->next!=NULL) {
        q=q->next;
        }
        q->next=ptr;
        ptr->prev=q;
       }
    }
    display(head);
}
void main()
{
    create();
    Reverse(head);
}