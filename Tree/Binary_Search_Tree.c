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

struct node *Search(struct node* root, int ele)
{
    while(root!=NULL)
    {
        if(ele==root->data)
            return root;
        if(ele>root->data)
            root=Search(root->right, ele);
        else
            root=Search(root->left, ele);
    }
    return NULL;
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
    struct node *root=NULL, *ptr;
    int ch,v,ele;
    do
    {   printf("\n1.Create\n2.Insert\n3.Search\n4.Preorder");
        printf("\n5.Inorder\n6.Posorder");
        printf("\n7.Quit");
        printf("\nEnter Your Choice :");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            root=Create();
            break;
        case 2:
            printf("Enter Value to Insert: ");
            scanf("%d",&v);
            root=InsertBST(root,v);
            break;
        case 3:
            printf("Enter Element to Search: ");
            scanf("%d",&ele);
            ptr=Search(root,ele);
            if(ptr==NULL)
            {
                printf("Element not found\n");
            }
            else {
                printf("Element Found\n");
            }
            break;
        case 4:
       printf("Preorder of this Tree\n");  
            PreOrder(root);
            break;
        case 5:
         printf("Inorder of this Tree\n");
            InOrder(root);
            break;
        case 6:
         printf("Postorder of this Tree\n");
            PostOrder(root);
            break;
        }
    } while(ch!=7);
}