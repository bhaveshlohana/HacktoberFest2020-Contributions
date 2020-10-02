#include<stdio.h> 
#include<stdlib.h> 

int lbs( int arr[], int n ) 
{ 
    int i, j; 
    
    /* Allocate memory for LIS[] and initialize LIS values as 1 for 
    	all indexes */
    int *lis = new int[n]; 
    for (i = 0; i < n; i++) 
    	lis[i] = 1; 
    
    /* Compute LIS values from left to right */
    for (i = 1; i < n; i++) 
    	for (j = 0; j < i; j++) 
    		if (arr[i] > arr[j] && lis[i] < lis[j] + 1) 
    			lis[i] = lis[j] + 1; 
    
    /* Allocate memory for lds and initialize LDS values for 
    	all indexes */
    int *lds = new int [n]; 
    for (i = 0; i < n; i++) 
    	lds[i] = 1; 
    
    /* Compute LDS values from right to left */
    for (i = n-2; i >= 0; i--) 
    	for (j = n-1; j > i; j--) 
    		if (arr[i] > arr[j] && lds[i] < lds[j] + 1) 
    			lds[i] = lds[j] + 1; 
    
    
    /* Return the maximum value of lis[i] + lds[i] - 1*/
    int max = lis[0] + lds[0] - 1; 
    for (i = 1; i < n; i++) 
    	if (lis[i] + lds[i] - 1 > max) 
    		max = lis[i] + lds[i] - 1; 
    return max; 
} 

int main() 
{ 
int arr[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 
			13, 3, 11, 7, 15}; 
int n = sizeof(arr)/sizeof(arr[0]); 
printf("Length of LBS is %d\n", lbs( arr, n ) ); 
return 0; 
} 
