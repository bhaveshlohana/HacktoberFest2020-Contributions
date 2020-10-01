#include <iostream>
using namespace std;

void merge(int a[], int left, int mid, int right)
{
    int i, j, k, n1, n2;
    int l[50], r[50];
    n1 = mid - left + 1;
    n2 = right - mid;
    for(i=0; i<n1; i++)
    {
        l[i] = a[left+i];
    }
    for(j=0; j<n2; j++)
    {
        r[j] = a[mid+1+j];
    }
    i = 0;
    j = 0;
    k = left;
    while(i<n1 && j<n2)
    {
        if(l[i]<=r[j])
        {
            a[k] = l[i];
            i++;
        }
        else
        {
            a[k] = r[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        a[k] = l[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        a[k] = r[j];
        j++;
        k++;
    }
}

void merge_sort(int a[], int left, int right)
{
    if(left < right)
    {
        int mid;
        mid = (left + right)/2;
        merge_sort(a, left, mid);
        merge_sort(a, mid+1, right);
        merge(a, left, mid, right);
    }
}

int main()
{
    int i, n;
    int arr[50];
    cout<<"Enter the length of array: ";
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

