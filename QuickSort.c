#include<stdio.h>
int partition(int A[], int low, int high)
{
    int pivot=A[low];
    int temp;
    int i=low+1;
    int j=high;
    do {
        while(A[i]<=pivot) {
            i++;
        }
        while(A[j]>pivot) {
            j--;
        }
        if(i<j) {
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
        }
    } while(i<j);
    temp=A[low];
    A[low]=A[j];
    A[j]=temp;
    
    return j;
}
void quicksort(int A[], int low, int high)
{
    int index;
    if(low<high) {
        index=partition(A,low,high);
        quicksort(A, low, index-1);
        quicksort(A, index+1, high);
        partition(A,low,high);
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
    quicksort(A,0,n-1);
    printf("\n__Sorted Array__\n");
    for(i=0; i<n; i++)
    {
        printf("%d ",A[i]);
    }


}