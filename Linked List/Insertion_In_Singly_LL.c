#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*head=NULL;
void display(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element:%d\n", ptr->data);
        ptr = ptr->next;
    }
}
void insertAtFirst(struct Node * head) {
    int info;
    struct Node *ptr;
    printf("Enter Element for Insertion: ");
    scanf("%d",&info);
    ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = info;
    ptr->next=head;
    head=ptr;
    printf("Linked list after Insertion\n");
    display(ptr);
}
void insertAtEnd(struct Node * head) {
    int info;
    struct Node *ptr;
    struct Node *p=head;
    printf("Enter Element for Insertion: ");
    scanf("%d",&info);
    ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = info;

    while(p->next!=NULL) {
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
    printf("Linked list after Insertion\n");
    display(head);
}
void insertAtIndex(struct Node * head) {
    int info,index;
    struct Node *ptr;
    struct Node *p=head;
    printf("Enter Element for Insertion: ");
    scanf("%d",&info);
    printf("Enter Index for Insertion except first and last\n ");
    scanf("%d",&index);
    ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = info;
    int i=0;
    while(i!=index-1) {
        p=p->next;
        i++;
    }
    ptr->next=p->next;
    p->next=ptr;
    printf("Linked list after Insertion\n");
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
        }
    }
    display(head);
}
void main()
{
    int ch;
    create();
    do {
        printf("Enter your choice\n 1.Insert At Beginning:\n 2.Insert At End:\n 3.Insert At Index :\n 4.Exit: ");
        scanf("%d",&ch);
        switch(ch) {
        case 1:
            insertAtFirst(head);
            break;
        case 2:
            insertAtEnd(head);
            break;
        case 3:
            insertAtIndex(head);
            break;
        case 4:
            break;

        }
    } while(ch!=4);


}