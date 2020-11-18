#include<bits/stdc++.h>
using namespace std;
*int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int key,j;
    for(int i=1;i<n;i++)
    {
        key=a[i];
        j=i-1;
        while(a[j]>=key && j>=0)
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=key;
    }
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}


