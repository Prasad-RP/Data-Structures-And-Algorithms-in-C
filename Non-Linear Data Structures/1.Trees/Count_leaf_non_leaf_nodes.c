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

int Countleaf(struct node *root)
{
    if(root==NULL)
        return 0;
    if(root->left==NULL && root->right==NULL)
        return 1;
    else
        return Countleaf(root->left)+Countleaf(root->right);
}

int Count_Nonleaf(struct node *root)
{
    if(root==NULL ||(root->left==NULL && root->right==NULL))
        return 0;
    else
    // root node is also non leaf node
        return 1+Count_Nonleaf(root->left)+Count_Nonleaf(root->right);
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
    printf("\nProgram For Binary Tree:\n");
    struct node *root;
    //creating a binary tree
    root=CreateNode(10);
    struct node * p1=CreateNode(8);
    struct node * p1_1=CreateNode(7);
    struct node * p1_2=CreateNode(5);
    struct node * p2=CreateNode(9);
    struct node * p2_2=CreateNode(6);
    struct node * p1_1_2=CreateNode(0);
    /* tree looks like this
                10
                /\
               8  9
              /\   \
             7  5   6
            /
           0
     */
// linking nodes of tree

    root->left=p1;
    root->right=p2;
    p1->left=p1_1;
    p1->right=p1_2;
    //not necessary to link NULL
    //  p2->left=NULL;
    p2->right=p2_2;
    p1_1->left=p1_1_2;
    //  p1_1->right=NULL;
    // traversing the tree

    printf("InOrder of Tree\n");
    InOrder(root);
    printf("\nPreOrder of Tree\n");
    PreOrder(root);
    printf("\nPostOrder of Tree\n");
    PostOrder(root);
    printf("\nNo. of Non Leaf Nodes =%d\n", Count_Nonleaf(root));
    printf("\nNo. of Leaf Nodes =%d\n", Countleaf(root));


}
