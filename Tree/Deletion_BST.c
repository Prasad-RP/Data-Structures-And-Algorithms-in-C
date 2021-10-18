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

void InOrder(struct node *root)
{
    if(root!=NULL)
    {
        InOrder(root->left);
        printf(" %d ",root->data);
        InOrder(root->right);
    }
}

struct node* Inorder_predecessor(struct node * root)
{
    root=root->left;
    while(root->right!=NULL)
    {
        root=root->right;
    }
    return root;
}

struct node * Delete(struct node *root,int val)
{
    struct node *inpre;
    if(root==NULL) {
        return NULL;
    }
    if(root->left==NULL && root->right==NULL)
    {
        free(root);
        return NULL;
    }
// searching the node for deletion
    if(val<root->data) {
        root->left=Delete(root->left,val);
    }

    else if(val>root->data) {
        root->right=Delete(root->right,val);
    }
    else {
//deleting the node
        inpre=Inorder_predecessor(root);
        root->data=inpre->data;
        root->left=Delete(root->left,inpre->data);
    }
    return root;
}

void main()
{
    printf("\nProgram For Binary Search Tree:\n");
    struct node *root=NULL;
    int x;
    root=Create();
    printf("\nBefore Deletion Inorder Traversal\n");
    InOrder(root);
    printf("\nEnter element which is to be deleted: ");
    scanf("%d",&x);
    Delete(root,x);
    printf("\nAfter Deletion Inorder Traversal\n");   
    InOrder(root);

}