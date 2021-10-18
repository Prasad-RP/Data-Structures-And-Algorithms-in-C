// This code implements Linear Search algorithm
#include<stdio.h>
void main()
{
    int n,i,ele;
     int A[50];
    printf("enter size of list :");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    { 
    printf("enter element no %d: ",i+1);
     scanf("%d",&A[i]);
    }
   printf("enter element for search: ");
    scanf("%d",&ele);  
   for(i=0;i<n;i++){
    if(A[i]==ele){
    printf("element found at %d index",i);
  break;
      }
   }
    if(i==n)
    printf("element not found");
}
/****** Code By Prasad Pansare ******/
