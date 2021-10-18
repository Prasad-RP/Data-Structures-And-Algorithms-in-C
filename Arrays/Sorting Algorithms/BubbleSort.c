#include<stdio.h>
void bubblesort(int A[], int n)
{
    int i,j,temp;
    for(i=0; i<n-1; i++) {
        for(j=0; j<n-1-i; j++) {
            if(A[j]>A[j+1]) {
                temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
            }
        }

    }


}

void main()
{
    int n,i;
    int A[50];
    printf("enter size of list :");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        printf("enter element no %d: ",i+1);
        scanf("%d",&A[i]);
    }
    bubblesort(A,n);
    printf("__Sorted Array__\n");
    for(i=0; i<n; i++)
    {
        printf("%d ",A[i]);
    }


}
