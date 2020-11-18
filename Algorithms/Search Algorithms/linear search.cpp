Linear Search in C++

What is a linear search in C++ ?
Linear search is one of the simplest algorithm of data structure. 
In the process of linear search, the element to be searched is compared with every element of the list one by one until the element that is to be searched is found. 
If the element is not found till the end this means that the element is not present in the list. 
This can be performed on both the sorted list or the unsorted list.


Algorithm to implement linear search in C++
1.Read the element to be search from the user.
2.Compare the search element with the first element in the list.
3.If they both match,terminate the function.
4.Else compare the search element with the next element in the list.
5.Repeat steps 3 and 4 until the element to be search is found.


Program to implement linear search algorithm in C++

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,n,key;
    
    cout<<"Enter the size of the array: ";
    cin>>n;
    int *arr = new int(n);  
    
    cout<<"Enter the array elements: ";
    for(i=0;i<n;i++)
    cin>>arr[i];
    
    cout<<"Enter the key to be searched: ";
    cin>>key;
    
    for(i=0;i<n;i++)    //Searching element using linear search.
    {
      if(key==arr[i])
      {
        cout<<"The key element is found at index : "<<i+1;
        break;
      }
    }
    if(i==n)
    cout<<"Element not found";
}


Time Complexity
For Linear Search
Best
O(1)