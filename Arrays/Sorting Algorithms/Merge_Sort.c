#include <stdio.h>

void merge(int A[], int mid, int low, int high)
{
    int i, j, k, B[100];
    i= k = low;
    j = mid + 1;
   //  = low;

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }

}

void mergesort(int A[], int low, int high) {
    int mid;
    if(low<high) {
        mid = (low + high) /2;
        mergesort(A, low, mid);
        mergesort(A, mid+1, high);
        merge(A, mid, low, high);
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
    mergesort(A,0,n-1);
    printf("__Sorted Array__\n");
    for(i=0; i<n; i++)
    {
        printf("%d\t",A[i]);
    }
}