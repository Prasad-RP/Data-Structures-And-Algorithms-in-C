#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
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
    printf("Elements of Linked List\n");
    display(head);
}
void main()
{
    create();
}