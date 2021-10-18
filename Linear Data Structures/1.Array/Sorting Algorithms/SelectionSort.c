#include<stdio.h>
void SelectionSort(int A[], int n) {
    int i,j,minindex,temp;
    
    for(i=0; i<n-1; i++) {
        minindex=i;
        for(j=i+1; j<n; j++) {
            if(A[j]<A[minindex]) {
                minindex=j;
            }
        }
        
        temp=A[i];
        A[i]=A[minindex];
        A[minindex]=temp;
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
        SelectionSort(A,n);
        printf("\n__Using Selection Sort__\n");
        printf("\n\n__Sorted Array__\n\n");
        for(i=0; i<n; i++)
        {
            printf("%d ",A[i]);
        }


    }
