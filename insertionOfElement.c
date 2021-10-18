#include <stdio.h>

int main()
{
    int array[50], position, c, n, value;
    
    printf("Enter number of elements in the array:-");
    scanf("%d", &n);
    
    printf("\nEnter %d elements:-\n", n);
    
    for (c = 0; c < n; c++)    
     scanf("%d", &array[c]);
    
    printf("\nEnter the location where you want to insert an element:-");
    scanf("%d", &position);
    
    printf("\nPlease enter the value:-");
    scanf("%d", &value);
    
    for (c = n - 1; c >= position - 1; c--)    
array[c+1] = array[c];
    array[position-1] = value;
    
    printf("\nResultant array :-\n");
    
    for (c = 0; c <= n; c++)    
printf("%d\n", array[c]);    
    
    return 0;
}
