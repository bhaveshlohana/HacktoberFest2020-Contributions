/*
Shops and candies

There are n shops in a row. You have a number of coins to spend while
shopping. These coins are denoted by c1,c2,…cn where Ci is the number of
coins that you have to spend when you shop at the ith shop.

you start shopping from the very first shop and move towards the nth shop sequentially
For every shop that you skip, you have to buy one candy. Each candy costs x coins. You cannot skip
more than three shops in a row. Also you cannot skip first and last shop.

your task is to determine the minimum number of coins that you have spent after shopping
from the nth shop.

Constraints
2<= n <= 2x10^5
1<= x , Ci <= 2x10^5*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int64_t n,x;
    cin>>n>>x;
    vector<int64_t>coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    vector<int64_t>dp(n,INT_MAX);
    dp[0]=coins[0];
    for(int i=1;i<n;i++){
        for(int j=i-1;j>=max(0,i-4);j--)
        {
            dp[i]=min(dp[i],dp[j]+(x*(i-j-1))+coins[i]);
        }
    }
    cout<<dp[n-1];
}
