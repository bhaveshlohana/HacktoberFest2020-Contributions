//Time Complexity: O(n)
//Algorithmic Paradigm: Dynamic Programming


#include<iostream>
#include<bits/stdc++.h>

using namespace std; 
  
int kadane(int a[], int size) 
{ 
    int maxsofar = INT_MIN, maxhere = 0; 
  
    for (int i = 0; i < size; i++) 
    { 
        maxhere = maxhere + a[i]; 
        if (maxsofar < maxhere) 
            maxsofar = maxhere; 
  
        if (maxhere < 0) 
            maxhere = 0; 
    } 
    return maxsofar; 
} 

int main() 
{ 
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3 , 2, -5 ,6}; 
    int n = sizeof(a)/sizeof(a[0]); 
    int maxSum = kadane(a, n); 
    cout << "Maximum contiguous sum is " << maxSum; 
    return 0; 
} 
