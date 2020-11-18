Binary Search in C++

What is binary search in C++?

Binary search is another searching algorithm in C++. 
It is also known as half interval search algorithm.
It is efficient and fast searching algorithm.
The only condition required is that the elements in the list must be in sorted order. 
It works by repeatedly dividing in half the portion of the list that could contain the item, until you’ve narrowed down the possible locations to just one.

Working of binary search in C++

1.The searching algorithm proceed when the list is is in sorted order either ascending or descending.
2.Now divide the list into two halves.
3.If the element is at the center stop searching.
4.Else if the element is smaller then the last element of first half then further we will search in first half.
5.And if the element is greater than the first element of second half then further we will search in second half.
6.We will follow step 3 ,4 and 5 until our element is found.

Steps to implement Binary Searching with C++

1.In the given list, first we will find the middle of the list using formula M=(L+R)/2, where  M is the index of middle element, L is the index of leftmost element and R is the index of rightmost element.
2.If the element to be search is on the middle index then we will terminate the search as our element is found.
3.Else we will check if the element is smaller then the middle element or greater then the middle element.
4.If it is smaller then the middle element we will continue our search in first half.
5.And if it greater then the middle element we will continue our search in second half.
6.We will repeat all the previous steps until our element is found.

Algorithm for Binary Search in C++

while(low<=high)
      mid=(low+high)/2;
if(a[mid]<search_element)
      low=mid+1;
else if(a[mid]>search_element)
      high=mid-1;
If found return index
else return -1

C++ Program for Binary Search

#include<bits/stdc++.h>
using namespace std;

int binary_search(int arr[], int left, int right, int key);

int main()
{
    int n,i,res=0,key;
    cout<<"Enter the size of array :";
    cin>>n;
    int *arr = new int(n);
    cout<<"Enter the array elements in sorted order :";
    for(i=0;i<n;i++)
    cin>>arr[i];
    cout<<"Enter key element to be found :";
    cin>>key;
    res = binary_search(arr,0,n,key);
    if(res!=-1)
    cout<<"Key element found at position "<<res+1;
    else
    cout<<"Key element not found";
}

int binary_search(int arr[], int left, int right, int key)
{
    int mid;
    if(right>=left)
    {
        mid=(left+right)/2;
        if(arr[mid]==key)
        return mid;
        else 
        if(arr[mid]<key)
        return binary_search(arr,mid+1,right,key); 
        else
        return binary_search(arr,left,mid-1,key);
    }
    return -1;
}


Advantages of binary searching technique

Binary search has following advantage:-

1.Works faster then linear search.
2.It is a simple algorithm.

Time Complexity
For Binary Search
Best
O(1)

Average
O(log n)

Worst
O(log n)

Space Complexity
O(1)

Average Comparisions
Log(N+1)

Complexity Analysis of Binary Search:

To understand O(log n) complexity:

Sorted Array of 10 elements: 2, 5, 8, 12, 16, 23, 38, 56, 72, 91
Let us say we want to search for 23.

Finding the given element:
Now to find 23, there will be many iterations with each having steps as follows:

Iteration 1:

Array: 2, 5, 8, 12, 16, 23, 38, 56, 72, 91
1.Select the middle element. (here 16)
2.Since 23 is greater than 16, so we divide the array into two halves and consider the sub-array after element 16.
3.Now this subarray with the elements after 16 will be taken into next iteration.

Iteration 2:

Array: 23, 38, 56, 72, 91
1.Select the middle element. (now 56)
2.Since 23 is smaller than 56, so we divide the array into two halves and consider the sub-array before element 56.
3.Now this subarray with the elements before 56 will be taken into next iteration.

Iteration 3:

Array: 23, 38
1.Select the middle element. (now 23)
2.Since 23 is the middle element. So the iterations will now stop.

Calculating Time complexity:

Let say the iteration in Binary Search terminates after k iterations. 
In the above example, it terminates after 3 iterations, so here k = 3

At each iteration, the array is divided by half. So let’s say the length of array at any iteration is n

At Iteration 1,
Length of array = n

At Iteration 2,
Length of array = n⁄2

At Iteration 3,
Length of array = (n⁄2)⁄2 = n⁄2^2

Therefore, after Iteration k,
Length of array = n⁄2^k

Also, we know that after
After k divisions, the length of array becomes 1

Therefore
Length of array = n⁄2^k = 1
=> n = 2^k

Applying log function on both sides:
=> log2 (n) = log2 (2k)
=> log2 (n) = k log2 (2)
As (log a (a) = 1)
Therefore,
=> k = log2 (n)
Hence, the time complexity of Binary Search is

log2 (n)
