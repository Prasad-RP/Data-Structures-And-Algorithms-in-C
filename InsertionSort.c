#include<stdio.h>
void insertionsort(int A[], int n) {
    int i,j,key;
    for(i=1; i<=n-1; i++) //for no.of passes
    {
        key=A[i];
        j=i-1;
      //loop for each pass
    while(j>=0 && A[j]>key){
    A[j+1]=A[j];
    j--;
    }
    A[j+1]=key;
    
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
     insertionsort(A,n);
    printf("\n__Using Insertion Sort__\n");
    printf("\n\n__Sorted Array__\n\n");
    for(i=0; i<n; i++)
    {
        printf("%d ",A[i]);
    }


}
