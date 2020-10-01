//Heap Sort Program
#include<iostream> 
using namespace std; 

void makeHeap(int arr[], int n, int i) 
{ 
    int largest = i;
    //left child
    int l = 2 * i + 1;
    //right child
    int r = 2 * i + 2;
  
    if (l < n and arr[l] > arr[largest]) 
        largest = l; 
    if (r < n and arr[r] > arr[largest]) 
        largest = r; 
  
    // do if largest is not root 
    if (largest != i) { 
        swap(arr[i], arr[largest]); 
        makeHeap(arr, n, largest); 
    } 
} 
void heapSort(int arr[], int n) 
{ 
    // rearranging the heap
    for (int i = n / 2 - 1; i >= 0; i--) 
        makeHeap(arr, n, i); 
  
    for (int i = n - 1; i >= 0; i--) { 
        // Move current root to end using swap function
        swap(arr[0], arr[i]); 
  
        makeHeap(arr, i, 0); 
    } 
}

int main()
{ 
    int n;
    cout<<"Enter the size of array:";
    cin>>n;
    int arr[n];
    cout<<"Enter the value is array:";
    for(int i=0; i<n; i++)
        {
            cin>>arr[i];    
        }
    heapSort(arr, n);
    cout << "The sorted array is \n"; 
    for (int i = 0; i < n; ++i) 
        cout <<arr[i]<<" "; 
    cout <<endl; 
} 