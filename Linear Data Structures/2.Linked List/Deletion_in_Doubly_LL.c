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
void DeleteAtFirst(struct Node * head) {
    struct Node * p=head;
    head=head->next;
    head->prev=NULL;
    p->next=NULL;
    free(p);
    printf("Linked List after Deleting First Node \n");
    display(head);

}
void DeleteAtEnd(struct Node * head) {
    struct Node * p=head;
    struct Node * q=head->next;
    while(q->next!=NULL)
    {
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    q->prev=NULL;
    free(q);
    printf("\nLinked list After Deletion\n");
    display(head);
}
void DeleteAtIndex(struct Node * head) {
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
    q->prev=NULL;
    q->next->prev=p;
    free(q);

    free(q);
    printf("\nLinked list After Deletion\n");
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
            ptr->next=NULL;
        }
    }
    printf("Linked List Before Deletion\n");
    display(head);
}
void main()
{
    create();
    int ch;
    do {
        printf("Enter your choice\n 1.Delete At Beginning:\n 2.Delete At Index:\n 3.Delete At End\n 4.Exit: ");
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
            break;
        }
    } while(ch!=4);
}