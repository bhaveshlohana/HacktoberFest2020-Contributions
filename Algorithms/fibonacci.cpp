#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int sum_ar[n];
    sum_ar[0]=1;
    sum_ar[1]=1;
    for(int i=2;i<n+1;i++)
    {
        sum_ar[i]=sum_ar[i-1]+sum_ar[i-2];
    }
    cout<<sum_ar[n];
}