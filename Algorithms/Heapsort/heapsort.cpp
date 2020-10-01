#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int> &arr,int i,int n)
{
    int left = 2*i+1;
    int right = 2*i+2;
    int largest;
    if(left<n && arr[left]>arr[i])
    {
        largest=left;
    }
    else
    {
        largest=i;
    }

    if(right<n && arr[right]>arr[largest])
    {
        largest=right;
    }

    if(largest!=i)
    {
        swap(arr[i],arr[largest]);
        heapify(arr,largest,n);
    }
}

void heapsort(vector<int> &arr,vector<int> &ans,int n)
{
    for(int i=n-1;i>=1;i--)
    {
        swap(arr[i],arr[0]);
        heapify(arr,0,i);
    }
}
int main()
{

    vector<int> arr;

    int n ;

    cout<<"Enter number of elements\n";
    cin>>n;

    cout<<"Enter the elements\n";
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        arr.push_back(temp);
    
    }


    for(int i=n/2-1;i>=0;i--)
    {
        heapify(arr,i,n);
    }
    
    vector<int> ans;
   
    cout<<"Before sorting\n";
    for(auto x:arr)
    {
        cout<<x<<" ";
    }
    cout<<endl;

    heapsort(arr,ans,n);

    cout<<"After sorting\n";
    for(auto x:arr)
    {
        cout<<x<<" ";
    }




}
