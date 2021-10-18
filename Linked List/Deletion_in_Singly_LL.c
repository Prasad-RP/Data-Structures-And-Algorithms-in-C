#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
}*head=NULL;
// Function to display elements of linked list
void display(struct Node *ptr)
{

    while (ptr != NULL)
    {
        printf("Element:%d\n", ptr->data);
        ptr = ptr->next;
    }
}
// Function to create a linked list
void create() {
    int info,i,n;
    struct Node *q,*ptr;
    printf("Enter Size of list: ");
    scanf("%d",&n);
    for(i=0; i<n; i++) {
        ptr = (struct Node *)malloc(sizeof(struct Node));
        printf("\nEnter data of node %d : ",i+1);
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
// Case 1: Deleting first element of linked list
void DeleteAtFirst(struct Node *head)
{
    struct Node * ptr=head;
    head=head->next;
    free(ptr);
    printf("\nLinked list After Deletion\n");
    display(head);
}
//Case 2: Deleting The element At Given Index of linked list
void DeleteAtIndex(struct Node *head)
{
    int index,i;
    printf("Eneter Index for Deletion: ");
    scanf("%d",&index);
    struct Node * p=head;
    struct Node * q=head->next;
    for(i=0; i<index-1; i++)
    {
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
    printf("\nLinked list After Deletion\n");
    display(head);
}
//Case 3: Deleting last element of linked list
void DeleteAtEnd(struct Node *head)
{
    struct Node * p=head;
    struct Node * q=head->next;
    while(q->next!=NULL)
    {
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    printf("\nLinked list After Deletion\n");
    display(head);
}
//Case 4: Deleting with given Value of linked list
void DeleteTheValue(struct Node *head)
{
    int Value;
    printf("Enter Element Which Is To Be Delet: ");
    scanf("%d",&Value);
    struct Node * p=head;
    struct Node * q=head->next;
    while(q->data!=Value && q->next!=NULL)
    {
        p=p->next;
        q=q->next;
    }
    if(q->data==Value) {
        p->next=q->next;
        free(q);
    }
    else {
        printf("Element Not Found in Linked List\n");
    }
    printf("\nLinked list After Deletion\n");
    display(head);
}
void main()
{
    create();
    int ch;
    do {
        printf("Enter your choice\n 1.Delete At Beginning:\n 2.Delete At Index:\n 3.Delete At End\n 4.Delete The Given Value\n 5.Exit: ");
        scanf("%d",&ch);

        switch(ch) {
        case 1:
            DeleteAtFirst(head);
            break;
        case 2:
            DeleteAtIndex(head);
            break;
        case 3:
            DeleteAtEnd(head);
            break;
        case 4:
            DeleteTheValue(head);
            break;
        case 5:
            break;
        }
    } while(ch!=5);
}