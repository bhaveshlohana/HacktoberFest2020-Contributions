#include <iostream>
using namespace std;

int partition(int a[], int l, int h)
{
    int i, j, pivot, temp;
    pivot = a[h];
    i = l;
    for(j=l; j<h; j++)
    {
        if(a[j]<=pivot)
        {
            temp = a[j];
            a[j] = a[i];
            a[i] = temp;
            i++;
        }
    }
    temp = a[h];
    a[h] = a[i];
    a[i] = temp;
    return (i);
}

void quick_sort(int a[], int l, int h)
{
    int P;
    if(l < h)
    {
        P = partition(a, l, h);
        quick_sort(a, l, P-1);
        quick_sort(a, P+1, h);
    }
}

int main()
{
    int array[50];
    int i, n;
    cout<<"Enter number of elements in array: ";
    cin>>n;
    for(i=0; i<n; i++)
    {
        cout<<"Enter element at position "<<i<<" : ";
        cin>>array[i];
    }
    quick_sort(array, 0, n-1);
    cout<<"\nSorted Array: ";
    for(i=0; i<n; i++)
    {
        cout<<array[i]<<"  ";
    }
    
    return 0;
}
