#include <bits/stdc++.h> 
using namespace std; 
  
void swap(int *x, int *y)  
{  
    int temp = *x;  
    *x = *y;  
    *y = temp;  
}  
  
void selectionSort(int arr[], int n)  
{  
    int i, j, min;  
  
    for (i = 0; i < n-1; i++)  
    {  
        
        min = i;  
        for (j = i+1; j < n; j++)  
        if (arr[j] < arr[min])
            min = j;  
        swap(&arr[min], &arr[i]);  
    }  
}  

void printArray(int arr[], int n)  
{  
    for (int i=0; i < n; i++)  
        cout << arr[i] << " ";  
    cout << endl;  
}  
    
int main()  
{  
    int n;
    cout<<"enter the size of array : ";
    cin>>n;
    int arr[n];  
    for (int i = 0; i < n; i++){
        cin>>arr[i];
    }
    selectionSort(arr, n);  
    cout << "Sorted array: \n";  
    printArray(arr, n);  
    return 0;
}