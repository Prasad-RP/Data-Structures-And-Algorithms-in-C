#include<stdio.h>
#include<stdlib.h>
// this is an incomplete program
//may be do it later 😉
struct Node
{
    int data;
    struct Node *next;
}*head;
// Function to display elements of linked list
void display(struct Node * head)
{
struct Node * ptr=head;
    do
    {
        printf("Element:%d\n", ptr->data);
        ptr = ptr->next;
    }while (ptr!= head);
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
     
        if(head==NULL) {
        head=ptr;
       ptr->next=head;
        }
        else {
        ptr->next=head->next;
        head->next=ptr;
       head=ptr;
        }
    }
    display(head);
}

void main()
{
    create();
}