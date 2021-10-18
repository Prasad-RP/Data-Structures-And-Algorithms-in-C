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
//case 1: Insertion in Linked List at first
void insertAtBegining(struct Node * head)
{
    int info;
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    printf("\nEnter Element To insert at first: ");
    scanf("%d", &info);
    ptr->data = info;
    ptr->next=head;
    head->prev=ptr->next;
    ptr->prev=NULL;
    head=ptr;
    printf("Linked List after Insert at beginning: \n");
    display(head);
}
//case 2: Insertion in Linked List at given Index
void insertAtIndex(struct Node * head)
{
    int info, index;
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    printf("\nEnter Element To insert: ");
    scanf("%d", &info);
    printf("\nEnter Index where you want to insert: ");
    scanf("%d",&index);
    ptr->data = info;
    struct Node * p=head;
    struct Node * q=head->next;
    int i=0;
    while(i!=index-1) {
        p=p->next;
        q=q->next;
        i++;
    }
    ptr->prev=p;
    p->next=ptr;
    ptr->next=q;
    q->prev=ptr;
    printf("Linked List after Insert at Index %d: \n",index);
    display(head);
}
//case 3: Insertion in Linked List at End
void insertAtEnd(struct Node * head)
{
    int info;
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    printf("\nEnter Element To insert at End: ");
    scanf("%d", &info);
    ptr->data = info;
    struct Node *p= head;
    while (p->next!= NULL)
    {
        p=p->next;
    }
    // at that time p is at last node
    ptr->next=NULL;
    p->next=ptr;
    ptr->prev=p;
    printf("Linked List after Insert at End: \n");
    display(head);
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
    printf("Elements of Linked List\n");
    display(head);
}
void main()
{
    create();
    int ch;
    do {
        printf("Enter your choice\n 1.Insert At Beginning:\n 2.Insert At End:\n 3.Insert At Index:\n 4.Exit: ");
        scanf("%d",&ch);
        switch(ch) {
        case 1:
            insertAtBegining(head);
            break;
        case 2:
            insertAtEnd(head);
            break;
        case 3:
            insertAtIndex(head);
            break;
        }
    } while(ch!=4);
}