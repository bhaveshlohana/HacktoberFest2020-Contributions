#include<bits.stdc++.h>
using namespace std;

int coinChange(vector<int> coins, int amount){
//coins : array of coins
//amount : amount to be reached

  vector<int> dp(amount+1); //dp[i] is number of ways to make amount = i from coins[]
  dp[0] = 1; //1 way to make amount = 0 i.e add no coins!
  for(int coin: coins){
    for(int i=coin; i<=amount;i++){
      dp[i] += dp[i-coin];
    }
    return dp[amount];
  }

}

int main(){
  cout<< coinChange({1,2,4,5,10}, 16); 
}
