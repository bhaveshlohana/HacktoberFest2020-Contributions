#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right)
{
    /*function for merging parts of arr in correct order*/
    int i, j, k, n1, n2;
    int l[50], r[50];
    n1 = mid - left + 1; /*length of left half of array to be merged*/
    n2 = right - mid; /*length of right half of array to be merged*/
    for(i=0; i<n1; i++)
    {
        l[i] = arr[left+i];
        /*copying the left half of required part of arr into separate array*/
    }
    for(j=0; j<n2; j++)
    {
        r[j] = arr[mid+1+j];
        /*copying the right half of required part of arr into separate array*/
    }
    /*now we have to write elements of l and r into arr in sorted order*/
    i = 0;
    j = 0;
    k = left;
    while(i<n1 && j<n2)
    {
        /*writing the smaller element out of l[i] and r[j] to arr*/
        if(l[i]<=r[j])
        {
            arr[k] = l[i];
            i++;
        }
        else
        {
            arr[k] = r[j];
            j++;
        }
        k++;
    }
    /*now the comparison between elements of l and r is complete; 
    one of l or r might have elements larger than the largest element of the other;
    these need to be copied into arr now;
    only one of the following loops will run depeding on which of i or j have reached their upper limit*/
    while(i<n1)
    {
        arr[k] = l[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k] = r[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int left, int right)
{
    /*recursive function for sorting an array; Sorts the first half and then the second half by calling itself repeatedly*/
    /*completes the sorting in O(nlogn) time*/
    if(left < right)
    {
        int mid;
        mid = (left + right)/2;
        merge_sort(arr, left, mid); /*sorting the left half of the array*/
        merge_sort(arr, mid+1, right); /*sorting the right half of the array*/
        merge(arr, left, mid, right); /*merging the two sorted arrays*/
    }
}

int main()
{
    int i, n;
    int arr[1000];
    cout<<"Enter the length of array (less than or equal to 1000) : ";
    cin>>n;
    for(i=0; i<n; i++)
    {
        cout<<"Enter element at "<<i<<" : ";
        cin>>arr[i];
    }
    merge_sort(arr, 0, n-1);
    cout<<"\nSorted Array: "<<endl;
    for(i=0; i<n; i++)
    {
        cout<<arr[i]<<"  ";
    }

    return 0;
}

