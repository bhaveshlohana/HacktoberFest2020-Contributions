/* Implementation of Longest Increasing Subsequence */

#include <bits/stdc++.h>
using namespace std;

int lis(int arr[],int n)
{   int dp[n];
    dp[0]= 1;
    
    int i,j;
    for(i=1;i<n;i++){
        dp[i]=1;
        for(j=0;j<i;j++)
        {   if(arr[j]<arr[i] && (1+dp[j])>dp[i])
                dp[i] = 1+dp[j];
        }
    }
    int ans= dp[0];
    for(i=0;i<n;i++)
        ans = max(ans,dp[i]);
    return ans;
}

int main() {
	  
	int n,i;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)
        cin>>arr[i];

    int ans = lis(arr,n);
    cout<<"Length of longest increasing subsequence: "<<ans<<endl;
	    
	return 0;
}