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
char infix[];
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
// gives top element of stack
int stacktop(struct stack * sp) {
    return sp->array[sp->top];
}
// this function gives precedence of operator
int precedence(char ch)
{
    if(ch=='^' || ch=='$')
    {
        return 3;
    }
    if(ch=='*' || ch=='/')
    {
        return 2;
    }
    if(ch=='+' || ch=='-')
    {
        return 1;
    }
    return -1;
}
// this function checks character is operator
int isoperator(char ch)
{
    if(ch=='+'|| ch=='-' || ch=='*' || ch=='/')
    {
        return 1;
    }
    else return 0;
}

char* Infix_Postfix(struct stack * sp,char * infix)
{
    char * postfix=(char *) malloc(strlen(infix)+1 * sizeof(char));
    int i=0;// tracks the infix exp
    int j=0;// full the postfix exp
    while(infix[i]!='\0') {
        if(!isoperator(infix[i])) {
            postfix[j]=infix[i];
            j++;
            i++;
        }
        else {
            if(precedence(infix[i])>precedence(stacktop(sp)))
            {
                Push(sp,infix[i]);
                i++;
            }
            else {
                postfix[j]=Pop(sp);
                j++;
            }
        }
    }
    while(!isEmpty(sp)) {
        postfix[j]=Pop(sp);
        j++;
    }
    postfix[j]='\0';
    return postfix;
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
    gets(infix);
    struct stack * sp;
    sp=(struct stack *)malloc(sizeof(struct stack));
    sp->size=strlen(infix);
    sp->top=-1;
    sp->array=(char *) malloc(sp->size * sizeof(char));
    printf("exp length=%d \n",strlen(infix));
    printf("infix to postfix: %s\n",Infix_Postfix(sp,infix));
    char * s1=stringrev(sp,infix);
    char * s2=Infix_Postfix(sp,s1);
    printf("infix to Prefix: %s\n",stringrev(sp,s2));
}