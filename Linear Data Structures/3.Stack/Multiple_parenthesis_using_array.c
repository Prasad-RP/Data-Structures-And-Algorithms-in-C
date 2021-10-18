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
int match(char a, char b) {
    if(a=='{' && b=='}')
    {
        return 1;
    }
    if(a=='(' && b==')')
    {
        return 1;
    }
    if(a=='[' && b==']')
    {
        return 1;
    }
    return 0;
}
int parenthesis_match(char * exp) {
    int length=strlen(exp);
    char popped_ch;
    printf("exp length=%d \n", length);
    struct stack * sp;
    sp=(struct stack *)malloc(sizeof(struct stack));
    sp->size=length;
    sp->top=-1;
    sp->array=(char *) malloc(sp->size * sizeof(char));
    for(int i=0; exp[i]!='\0'; i++) {
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[') {
            Push(sp,exp[i]);
        }
        else if(exp[i]==')' || exp[i]=='}' || exp[i]==']') {
            if(isEmpty(sp)) {
                return 0;
            }
            popped_ch=Pop(sp);
            if(!match(popped_ch,exp[i])) {
                return 0;
            }
        }
    }
    if(isEmpty(sp)) {
        return 1;
    }
    else {
        return 0;
    }
}

void main()
{

    printf("Enter The Expression\n");
    gets(exp);
    if(parenthesis_match(exp))
    {
        printf("Parenthesis is balanced\n");
    }
    else
        printf("Parenthesis is  not balanced\n");


}