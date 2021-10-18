#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// structure of stack
struct stack {
    int size;
    int top;
    char *array;

};
// I'm using it as global array
// becoz i can run it for too much large exp
char exp[];
int isFull(struct stack *sp) {
    if(sp->top==sp->size-1) {
        return 1;
    }
    else {
        return 0;
    }
}
// checks weather the stack is Empty or not
int isEmpty(struct stack *sp) {
    if(sp->top==-1) {
        return 1;
    }
    else {
        return 0;
    }
}
// Insert or push Element in stack
void Push(struct stack *sp,char val) {
    if(isFull(sp)) {
        printf("Stack Overflow\n");
    }
    else {
        sp->top++;
        sp->array[sp->top]=val;
    }
}

// delete or pop Element in stack
char Pop(struct stack *sp) {
    char val;
    if(isEmpty(sp)) {
        printf("Stack Underflow\n");
    }
    else {
        val=sp->array[sp->top];
        sp->top--;
        return val;
    }
}
char * stringrev(struct stack * sp,char * infix)
{
    
    char * rev=(char *) malloc(strlen(infix)+1 * sizeof(char));
    int i=0;// tracks the exp
    int j=0;// full the rev exp
    while(infix[i]!='\0')
    {
        Push(sp,infix[i]);
        i++;
    }
    while(!isEmpty(sp)) {
        rev[j]=Pop(sp);
        j++;
    }
    rev[j]='\0';
    return rev;
}
void main()
{
    printf("Enter The Expression\n");
    gets(exp);

    struct stack * sp;
    sp=(struct stack *)malloc(sizeof(struct stack));
    sp->size=strlen(exp);
    sp->top=-1;
    sp->array=(char *) malloc(sp->size * sizeof(char));
    printf("%s\n",stringrev(sp,exp));

}