#include <bits/stdc++.h>
using namespace std;
int i;
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition (int arr[], int low, int high)   // partition Algorithm
{
	int pivot = arr[high]; // pivot
	int i = (low - 1); // Index of smaller eleme

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than the pivot
		if (arr[j] < pivot)
		{
			i++; // increment index of smaller element
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSort(int arr[], int low, int high)  // QuickSort Algorithm
{
	if (low < high)
	{
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

/* Function to print an array */
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	int n;
    cout<<"Enter the Size of the array :- "<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements in the array :- \n";
    for(i = 0 ; i < n ; ++i){
        cin>>arr[i];
    }
	quickSort(arr, 0, n - 1);
	cout << "The Sorted array is :-  \n";
	printArray(arr, n);
	return 0;
}

// This code is contributed by rathbhupendra
