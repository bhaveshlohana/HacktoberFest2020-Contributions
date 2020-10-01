//PROGRAM FOR INSERTION SORT: DAA
#include<iostream> 
using namespace std; 
void insertionSort(int arr[], int n)  
{  
    int i, k, j;  
    for (i = 1; i < n; i++) 
    {  
        k = arr[i];  
        j = i - 1;  
        while (j >= 0 && arr[j] > k) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = k;  
    }  
} 
void prntArr(int arr[], int n)  
{  
    int i;  
    for (i = 0; i < n; i++)  
    cout << arr[i] << " ";  
    cout << endl; 
}  

//MainFunction
int main()  
{  
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the array elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    } 
    insertionSort(arr, n);  
    prntArr(arr, n);  
  
    return 0;  
}  