#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node {
    int data;
    struct node *left;
    struct node *right;
};
struct node * CreateNode(int val)
{
    struct node *n;

    n=(struct node *)malloc(sizeof(struct node));
    n->data=val;
    n->left=NULL;
    n->right=NULL;
    return n;
}

void PreOrder(struct node *root)
{
    if(root!=NULL)
    {
        printf(" %d ",root->data);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}
void PostOrder(struct node *root)
{
    if(root!=NULL)
    {
        PostOrder(root->left);
        PostOrder(root->right);
        printf(" %d ",root->data);
    }
}
void InOrder(struct node *root)
{

    if(root!=NULL)
    {
        InOrder(root->left);
        printf(" %d ",root->data);
        InOrder(root->right);
    }
}
void main()
{
    printf("\nProgram For Binary Search Tree:\n");
    struct node *root;
    //creating a binary tree
    root=CreateNode(10);
    struct node * p1=CreateNode(8);
    struct node * p1_1=CreateNode(7);
    struct node * p1_2=CreateNode(5);
    struct node * p2=CreateNode(9);
    struct node * p2_2=CreateNode(6);
   /* tree looks like this
               10
               /\
              8  9
             /\   \
            7  5   6
*/
//linking nodes of tree

    root->left=p1;
    root->right=p2;
    p1->left=p1_1;
    p1->right=p1_2;
    p2->right=p2_2;
  // traversing the tree

    printf("InOrder of Tree\n");
    InOrder(root);
    printf("\nPreOrder of Tree\n");
    PreOrder(root);
    printf("\nPostOrder of Tree\n");
    PostOrder(root);

}
