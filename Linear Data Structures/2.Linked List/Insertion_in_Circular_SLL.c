#include <stdio.h>
#include <stdlib.h>
// Insertion in singly linked list
struct Node
{
    int data;
    struct Node *next;
};
void display(struct Node * head)
{
    struct Node *ptr=head;
    do
    {
        printf("Element:%d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}
void insertAtbegining(struct Node * head) {
    int info;
    struct Node *ptr;
    printf("Enter Element for Insertion: ");
    scanf("%d",&info);
    ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data=info;
    struct Node *p=head->next;
    while(p->next!=head)
    {
        p=p->next;
    }
    //at that time p is at last node
    p->next=ptr;
    ptr->next=head;
    head=ptr;
    printf("Linked List after Insertion at beginning\n");
    display(head);
}
void insertAtEnd(struct Node * head) {
    int info;
    struct Node *ptr;
    printf("Enter Element for Insertion: ");
    scanf("%d",&info);
    ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data=info;
    struct Node *p=head->next;
    while(p->next!=head)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->next=head;
    printf("Linked List after Insertion at End\n");
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
    printf("Linked list after Insertion At %d Index\n",index);
    display(head);
}
void main()
{
    int ch;
    struct Node *head,*second,*third,*fourth;
    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    head->data = 1;
    head->next = second;
    // linking second nd third node
    second->data = 2;
    second->next = third;
    // linking third ND fourth node
    third->data = 3;
    third->next = fourth;
    // connecting fourth node ND head
    fourth->data = 4;
    fourth->next = head;
    printf("Linked List before Insertion\n");
    display(head);
    do {
        printf("Enter your choice\n 1.Insert At Beginning\n 2.Insert At End\n 3.Insert At Index\n 4.Exit: ");
        scanf("%d",&ch);
        switch(ch) {
        case 1:
            insertAtbegining(head);
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