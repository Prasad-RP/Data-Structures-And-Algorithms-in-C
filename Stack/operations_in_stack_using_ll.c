#include<stdio.h>
#include<stdlib.h>
// creating a stack using linked list
struct Node {
    int data;
    struct Node * next;
};

struct Node * top=NULL;
//case 1: displaying stack elements
void display(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element:%d\n", ptr->data);
        ptr = ptr->next;
    }
}
// case 2: check ing wheather the stack is empty or not
int isEmpty(struct Node *top) {
    if(top==NULL) {
        return 1;
    }
    else {
        return 0;
    }
}
// case 2: check ing wheather the stack is full or not
int isFull(struct Node *top) {
    struct Node *p=(struct Node*)malloc(sizeof(struct Node));
    if(p==NULL) {
        return 1;
    }
    else {
        return 0;
    }
}
/*case 3: pushing element in stack
 similar to Insertion in singly linked list
at beginning */
struct Node *Push(struct Node *top, int x)
{
    if(isFull(top)) {
        printf("Stack Overflow\n");
    }
    else {
        struct Node *n=(struct Node*)malloc(sizeof(struct Node));
        n->data=x;
        n->next=top;
        top=n;
        return top;
    }
}
/*case 4: popping element in stack
 similar to Deletion in singly linked list
at beginning */
void Pop(struct Node *tp)
{
    int x;
    if(isEmpty(tp)) {
        printf("Stack Underflow\n");
    }
    else {
        struct Node * n=tp;
        top=tp->next;
        x=n->data;
        free(n);
        printf("The Pooped Element is %d ",x);
    }
}
// case 5: peek operation
int peek(struct Node *top,int j) {
    int i=0;
    struct Node *ptr=top;
    for(i=0; (i<j-1 && ptr!=NULL); i++)
    {
        ptr=ptr->next;
    }
    if(ptr!=NULL) {
        return ptr->data;
    }
    else {
        return -1;
    }
}

int stacktop(struct Node* top)
{
    struct Node* ptr=top;
    return ptr->data;
}
int stackbottom(struct Node* top)
{
    struct Node* ptr=top;
    while(ptr->next!=NULL) {
        ptr=ptr->next;
    }
    return ptr->data;
}
void main()
{
    int data,n,i;
    printf("Enter Size of Stack: ");
    scanf("%d",&n);
    // pushing or inserting elements in stack for operations
    for(i=0; i<n; i++) {
        printf("Enter Element For Index %d: ",i);
        scanf("%d",&data);
        top=Push(top,data);
    }
    for(i=1; i<=n; i++) {
        printf("Element at position %d=%d \n",i,peek(top,i));
    }

    int ch,info,pos;
    do {
        printf("\nEnter Your chice\n 1.Push\n 2.Pop\n 3.IsEmpty\n 4.IsFull\n");
        printf(" 5.Peek\n 6.Stak Top\n 7.Stack Bottom\n 8.Exit: ");
        scanf("%d",&ch);
        switch(ch) {
        case 1:
            printf("Enter element to Push: ");
            scanf("%d",&info);
            top=Push(top,info);
            printf("Element %d Is Push in stack successfully\n",info);
            printf("Stack after Push\n");
            display(top);
            break;
        case 2:
            Pop(top);
            printf("\nStack after Pop\n");
            display(top);
            break;
        case 3:
            printf("%d",isEmpty(top));
            break;
        case 4:
            printf("%d",isFull(top));
            break;
        case 5:
            printf("Enter Position to peek\n");
            scanf("%d",&pos);
            printf("Element At Position %d=%d ",pos,peek(top,pos));
            break;
        case 6:
            printf(" Element At Top= %d",stacktop(top));
            break;
        case 7:
            printf(" Element At bottom= %d",stackbottom(top));
            break;
        case 8:
            break;
        }
    } while(ch!=8);
}