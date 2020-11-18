//G4G Problem
//Given an array A[ ] denoting the time taken to complete N tasks, determine the minimum amount of time required to finish the tasks considering that you can skip any task, but skipping two consecutive tasks is forbidden.
 
//Input:
//N = 2
//A[] ={10,20}
//Output: 10
//Explanation: we can take time of 10 units and skip 20 units time.
//This is a simple problem of dp. We require dp here to store the previous computed
//minimum sum. If not using dp, we can use simply two extra variables along with
//the other two & update their value everytime.
#include<bits/stdc++.h>
using namespace std;
vector<int>vec;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n+1],sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            sum+=arr[i];
        }
        int dp[n+1];
        dp[0]=arr[0];
        dp[1]=arr[1];
        if(n==1)
            cout<<0<<endl;
        else if(n==2)
        {
            cout<<min(arr[0],arr[1])<<endl;
        }
        else
        {
            for(int i=2;i<n;i++)
            {
                dp[i]=min(dp[i-1],dp[i-2])+arr[i];
            }
            cout<<min(dp[n-1],dp[n-2])<<endl;
        }
    }
    return 0;
}
