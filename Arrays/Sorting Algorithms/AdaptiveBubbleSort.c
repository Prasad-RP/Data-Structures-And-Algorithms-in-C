#include<stdio.h>
//Adaptive bubble sort is useful when
//array is already sorted..time and memory is saved
void bubblesortAdaptive(int A[], int n)
{
    int i,j,temp;
    int sorted=0;
    for(i=0; i<n-1; i++) {
        printf("\ntotal number of pass %d \n",i+1);
        sorted=1;
        for(j=0; j<n-1-i; j++) {
            if(A[j]>A[j+1]) {
                temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
                sorted=0;
            }
        }
        if(sorted==1) {
            return;
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
    bubblesortAdaptive(A,n);
    printf("\n\n__Sorted Array__\n\n");
    for(i=0; i<n; i++)
    {
        printf("%d ",A[i]);
    }
}
/****** Code By Prasad Pansare ******/
