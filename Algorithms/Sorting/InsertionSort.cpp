#include<iostream>
using namespace std;

int main()
{
    int *arr,size,i,value,hole;
    cout<<"Enter size of array\n";
    cin>>size;
    arr = new int[size];
    cout<<"Enter elements of array\n";
    for(i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    for(i=1;i<=size-1;i++)
    {
        value=arr[i];
        hole=i;
        while(hole>0 && arr[hole-1]>value)
        {
            arr[hole]=arr[hole-1];
            hole--;
            // arr[hole]=value;
        }
        arr[hole]=value;
    }
    cout<<"Sorted array is\n";
    for(i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}