#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node {
    int data;
    struct node *left;
    struct node *right;
};
struct node *InsertBST(struct node *root, int val)
{
    if(root==NULL)
    {
        root=(struct node *)malloc(sizeof(struct node));
        root->data=val;
        root->left=NULL;
        root->right=NULL;
        return root;
    }
    else {
        if(val<root->data)
            root->left=InsertBST(root->left, val);
        else if(val>root->data)
            root->right=InsertBST(root->right, val);
        else printf("Duplicate key! \n");
        return root;
    }
}
struct node *Create()
{
    int i,n, info;
    struct node *root=NULL;
    printf("\nEnter Total no.of nodes of BST: ");
    scanf("%d",&n);
    root=NULL;
    printf("Enter Values of Tree: \n");
    for(i=0; i<n; i++)
    {
        scanf("%d",&info);
        root=InsertBST(root,info);
    }
    return root;
}

void mirror(struct node *root)
{
    if(root==NULL)
        return;
    else {
        struct node *temp;
        mirror(root->left);
        mirror(root->left);
// swapping left and right
        temp=root->left;
        root->left=root->right;
        root->right=temp;
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
    struct node *root=NULL;
    root=Create();
    printf("\nInorder of Given tree\n");
    InOrder(root);
   printf("\nInorder of mirror tree\n");
   mirror(root);
    InOrder(root);



}