#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Algorithm for merge sort

// The merge() function is used for merging two halves.

void merge(int arr[], int l, int m, int r) 
{ 

    //n1 and n2 are the size of temp arrays L and R

    int n1 = m - l + 1; 
    int n2 = r - m; 
    int L[n1], R[n2]; 

    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (int j = 0; j < n2; j++) 
        R[j] = arr[m + 1 + j]; 

    // Merge the temp arrays back into arr[l..r]

    int i = 0; // Initial index of first subarray 
    int j = 0; // Initial index of second subarray 
    int k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2)
    { 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } 
        else { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 

    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 

   // Copy the remaining elements of R[], if there 
       //are any 
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 

void merge_sort(int arr[], int left, int right) 
{ 
    if (left < right) 
    { 
        // Same as (left+right)/2, but avoids overflow for large l and r 
        int mid = left + (right - left) / 2;   //can also be written as mid=(left+right)/2, but overflow can occur

        // Sort first and second halves using recursion
        merge_sort(arr, left, mid); 
        merge_sort(arr, mid + left, right); 

    // finally merge it
        merge(arr, left, mid, right); 
    } 
} 

int main()
{
	     int n;
        cin>>n;

        int arr[n];

        for(int i=0;i<n;i++)
        {
        	cin>>arr[i];
		    }
        merge_sort(arr,0,n-1);
        for(int i=0;i<n;i++)
        {
        	cout<<arr[i];
		   }
        return 0;

    }
