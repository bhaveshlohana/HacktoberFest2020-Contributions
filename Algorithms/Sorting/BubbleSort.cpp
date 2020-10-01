#include<iostream>
using namespace std;

int main()
{
    int n,i,temp,j;
    cout<<"Enter no. elements in an Array\n";
    cin>>n;
    int a[n];
    cout<<"Enter elements of an Array\n";
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]<a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }

    }
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
