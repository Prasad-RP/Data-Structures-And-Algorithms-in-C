// This code implements Binary Search algorithm
#include<stdio.h>
void main()
{
    int n,i,ele,ub,lb,mid;
     int A[50];
    printf("enter size of list :");
    scanf("%d",&n);
    printf("enter elements in Ascending order:\n");
    for(i=0;i<n;i++)
    {   
     scanf("%d",&A[i]);
    }
   printf("enter element for search: ");
    scanf("%d",&ele);  
   lb=0;
   ub=n-1;
   mid=(lb+ub)/2;
    
    while(lb<=ub){
  if(A[mid]==ele){
    printf("element found at %d index",mid);
   break;
    }
    else if(A[mid]<ele)
    lb=mid+1;
    else 
    ub=mid-1;
   mid=(lb+ub)/2; 
    }
    if(lb>ub)
    printf("element Absent");
         
}
/****** Code By Prasad Pansare ******/
