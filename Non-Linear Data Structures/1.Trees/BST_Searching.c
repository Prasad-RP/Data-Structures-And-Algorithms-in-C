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
//Iterative function to searching in Binary Search Tree
struct node *ITRSearch(struct node * root,int key)
{
    while(root!=NULL)
    {
        if(key==root->data)
            return root;
        else if(key<root->data)
            root=root->left;
        else
            root=root->right;
    }
    return NULL;
}
//Recursive function to searching in Binary Search Tree
struct node *Search(struct node * root,int key)
{
    while(root!=NULL)
    {
        if(key==root->data)
            return root;
        if(key<root->data)
            root=Search(root->left,key);
        else
            root=Search(root->right, key);
    }
    return NULL;
}

void main()
{
    printf("\nProgram For Binary Search Tree:\n");
    struct node *root=NULL;
    int x;
    root=Create();
    // searching in Binary Tree without using Recursion
    printf("Enter Element to Search: ");
    scanf("%d",&x);
    struct node *ptr=ITRSearch(root,x);
    printf("\nUsing Iterative Search");
    if(ptr==NULL)
    {
        printf("\nElement not found\n");
    }
    else {
        printf("\nElement found: %d",ptr->data);
    }
 // searching in Binary Tree using Recursion
    struct node *p=Search(root,x);
    printf("\nSearching Using Recursion");
    if(p==NULL)
    {
        printf("Element not found\n");
    }
    else {
        printf("\nElement found: %d",p->data);
    }

}