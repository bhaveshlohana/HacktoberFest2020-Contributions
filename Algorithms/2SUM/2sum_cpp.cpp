#include <bits/stdc++.h> 
using namespace std; 
  
// Involes the concept of Hashing
int getPairsCount(int arr[], int n, int sum) { 
    unordered_map<int, int> m; 
    for (int i=0; i<n; i++) 
        m[arr[i]]++; 
  
    int count = 0; 
    for (int i=0; i<n; i++) {
        //counting the numbers of pair 
        count += m[sum-arr[i]];

        //case when both elements of pair are equal
        if (sum-arr[i] == arr[i]) 
            count--; 
    } 
    // count/2 is taken to remove the count of repitition
    return count/2; 
} 

int main() { 
    // Desired Array
    int arr[] = {1, 6 ,8 ,9 ,10 ,-5, -7} ; 
    int n = sizeof(arr)/sizeof(arr[0]);
    
    // The desired sum 
    int sum = 5; 
    //Print the number of pairs with sum is equal to desired sum
    cout << "Number of pairs with desired sum is " << getPairsCount(arr, n, sum); 
    return 0; 
} 