#include <bits/stdc++.h> 
using namespace std; 

// Print all elements of range [low, high] that 
// are not present in arr[0..n-1] 
void printMissing(int arr[], int n, int low, 
				int high) 
{ 
	// Insert all elements of arr[] in set 
	unordered_set<int> s; 
	for (int i = 0; i < n; i++) 
		s.insert(arr[i]); 

	// Traverse throught the range an print all 
	// missing elements 
	for (int x = low; x <= high; x++) 
		if (s.find(x) == s.end()) 
			cout << x << " "; 
} 

int main() 
{ 
	int arr[] = { 1, 3, 5, 4 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	int low = 1, high = 10; 
	printMissing(arr, n, low, high); 
	return 0; 
} 
