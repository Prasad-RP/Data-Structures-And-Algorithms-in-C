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
    printf("Enter Total no.of nodes of BST: ");
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

void PostOrder(struct node *root)
{
  if(root!=NULL)
    {
        PostOrder(root->left);
        PostOrder(root->right);
        printf(" %d ",root->data);
    }
}

void main()
{
    printf("\nProgram For Binary Search Tree:\n");
    struct node *root=NULL, *ptr;
    root=Create();
    PostOrder(root);
}