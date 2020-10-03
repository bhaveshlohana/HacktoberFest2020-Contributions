#include <iostream>
#include<algorithm>
using namespace std;
int coinChange(int coins[],int t,int money){
    int ans=0;
    while(money>0){
       //if money=39 uperbound will give index of coin 50
        int idx= upper_bound(coins,coins+t,money)-1-coins;
         cout<<coins[idx]<<" ";
         money=money-coins[idx];
         ans++;
    }
    return ans;
}



int main() {
  int money;
  cin>>money;
  int coins[]={1,2,5,10,20,50,100,200,500,2000};//size of coins =4*10=40;
  
  int t=sizeof(coins)/sizeof(int);
  
  cout<<coinChange(coins,t,money);
  return 0;
}
