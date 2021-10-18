#include<stdio.h>
#include<stdlib.h>
// structure of stack
struct stack {
    int size;
    int top;
    int *array;

};
// various operations on stack
// Operation 1:
// checks weather the stack is Full or not
int isFull(struct stack *sp) {
    if(sp->top==sp->size-1) {
        return 1;
    }
    else {
        return 0;
    }
}
// Operation 2:
// checks weather the stack is Empty or not
int isEmpty(struct stack *sp) {
    if(sp->top==-1) {
        return 1;
    }
    else {
        return 0;
    }
}
// Operation 3:
// Insert or push Element in stack
void Push(struct stack *sp, int val) {
    if(isFull(sp)) {
        printf("Stack Overflow\n");
    }
    else {
        sp->top++;
        sp->array[sp->top]=val;
    }
}
// Operation 4:
// delete or pop Element in stack
void Pop(struct stack *sp) {
    int val;
    if(isEmpty(sp)) {
        printf("Stack Underflow\n");
    }
    else {
        // removing top most element
        // since last in first out principle
        val=sp->array[sp->top];
        sp->top--;
        printf("Element %d is Popped\n",val);
    }
}
// Operation 5:
// checks the position of Element in stack
int peek(struct stack * sp,int i) {
    int position=sp->top-i+1;
    if(position<0) {
        printf("Invalid Position");
        return -1;
    }
    else {
        return sp->array[position];
    }
}
// Operation 6:
// Finding the Top most Element in stack
int stacktop(struct stack * sp) {
    return sp->array[sp->top];
}
// Operation 7:
// Finding the bottom Element in stack
int stackbottom(struct stack * sp) {
    return sp->array[0];
}
void display(struct stack * sp)
{
    int i,j;
    if(sp->top==-1) {
        printf("Stack is Empty\n");
    }
    else
    {
        for(i=sp->top; i>=0; i--)
        {
            printf("Element: %d\n",sp->array[i]);

        }
    }

}
void main()
{
    int data,n,i;
// creating a stack
    struct stack * sp;
    sp=(struct stack *)malloc(sizeof(struct stack));
    sp->size=50;
    sp->top=-1;
    sp->array=(int *) malloc(sp->size * sizeof(int));
    printf("Enter Size of Stack\n");
    scanf("%d",&n);
    // pushing or inserting elements in stack for operations
    for(i=0; i<n; i++) {
        printf("Enter Element For Index %d: ",i);
        scanf("%d",&data);
        Push(sp,data);
    }
    printf("Stack Elements before Operations\n");
    display(sp);
    int ch,info,pos;
    do {
        printf("\nEnter Your chice\n 1.Push\n 2.Pop\n 3.IsEmpty\n 4.IsFull\n");
        printf(" 5.Peek\n 6.Stak Top\n 7.Stack Bottom\n8.Exit: ");
        scanf("%d",&ch);
        switch(ch) {
        case 1:
            printf("Enter element to Push\n");
            scanf("%d",&info);
            Push(sp,info);
            printf("Element %d Is Push in stack successfully\n",info);
            printf("Stack Elements after Push Operations\n");
            display(sp);
            break;
        case 2:
            Pop(sp);
            printf("Stack Elements after Pop Operations\n");
            display(sp);
            break;
        case 3:
            printf("%d",isEmpty(sp));
            break;
        case 4:
            printf("%d",isFull(sp));
            break;
        case 5:
            printf("Enter Position of to check which element is there\n");
            scanf("%d",&pos);
            printf("Element At Position %d=%d ",pos,peek(sp,pos));
            break;
        case 6:
            printf(" Element At Top= %d",stacktop(sp));
            break;
        case 7:
            printf(" Element At Bottom= %d",stackbottom(sp));
            break;
        case 8:
            break;
        }
    } while(ch!=8);
}