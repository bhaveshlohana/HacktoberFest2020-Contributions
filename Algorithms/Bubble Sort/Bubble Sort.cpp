#include <iostream>
#include <algorithm>
using namespace std;
void print(int arr[], int n){
	for(int i=0;i<n;i++)
		cout<<arr[i]<<", ";
	cout<<endl;
}
void bubble_sort_recursive_pure(int arr[], int n, int i){
	if(n==1)
		return;
	if(i==n-1)
		return bubble_sort_recursive_pure(arr, n-1, 0);
		//max element is at right, unsorted array is 0 to n-1, again start comparing i=0
	if(arr[i] > arr[i+1]){
		swap(arr[i], arr[i+1]);
		// debug array
		print(arr,n);
	}

	bubble_sort_recursive_pure(arr, n, i+1);
}

void bubble_sort_recursive(int arr[], int n){
	if(n==1)
		return;
	for(int i=0;i<n-1;i++) // inner loop
		if(arr[i]>arr[i+1]){
			swap(arr[i], arr[i+1]); // arrays are passed by reference default
		}
	bubble_sort_recursive(arr, n-1);
}

void bubble_sort_iterative(int arr[], int n){
	

	int f=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				swap(arr[j], arr[j+1]);
				f=0;
			}
		}
		if(f){
			cout<<"Already Sorted:\n";
			break;
		}
	}
}
int main(){
	int n;
	cin>>n;
	int arr[n];// = {2,13,3,5,8,61}; // n=6
	// scan elements
	for(int i=0;i<n;i++)
		cin>>arr[i];
	//bubble_sort_iterative(arr,n);
	//bubble_sort_recursive(arr,n);
	bubble_sort_recursive_pure(arr,n, 0);
	// printing sorted array
	cout<<"Sorted: ";
	print(arr,n);

	return 0;
}


/*

As bubble moves to the top, 
similarly large element moves at the end of every iteration.
A after each iteration decrease each iteration length

Note : for sorted array this can be detected after 1 teration.
*/
