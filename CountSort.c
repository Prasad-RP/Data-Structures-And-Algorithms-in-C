#include<stdio.h>
#include<stdlib.h>
int Maximum(int A[], int n) {
    int i,Max;
    for(i=0; i<n; i++)
    {
        if(Max<A[i]) {
            Max=A[i];
        }
    }
    return Max;
}
void CountSort(int A[], int n) {
    int i,j;
//finding maximum element from Arrray
    int Max=Maximum(A,n);
//to create count array
    int* count=(int *) malloc((Max+1)*sizeof(int));
    for(i=0; i<Max+1; i++)
    {
        // initialize elements of count array to 0
        count[i]=0;
    }
    // increment the corresponding index of count array
    for(i=0; i<n; i++)
    {
        count[A[i]]=count[A[i]]+1;
    }
    i=0;//counter for count array
    j=0;//counter for given array
    while(i<=Max) {
        if(count[i]>0) {
            A[j]=i;
            count[i]=count[i]-1;
            j++;
        }
        else {
            i++;
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
    CountSort(A,n);
    printf("\n__Using Count Sort__\n");
    printf("\n\n__Sorted Array__\n\n");
    for(i=0; i<n; i++)
    {
        printf("%d ",A[i]);
    }


}