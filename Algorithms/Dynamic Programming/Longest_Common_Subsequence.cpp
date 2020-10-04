/* Implementation of Longest Common Subsequence */

#include<bits/stdc++.h>
using namespace std;

int main() {
    
    int n,m,i,j;
    string a,b;
    
    cout<<"Enter two strings: ";
    cin>>a>>b;

    n = a.length();
    m = b.length();

    int dp[n+1][m+1];
    for(i=0;i<=n;i++)
    {   for(j=0;j<=m;j++)
        {
            if(i==0||j==0)
                dp[i][j]=0;
            else if(a[i-1]==b[j-1])
            {   
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
                dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
        }
        
    }

    cout<<"Length of longest common subsequence: "<<dp[n][m]<<endl;
    
	return 0;
}