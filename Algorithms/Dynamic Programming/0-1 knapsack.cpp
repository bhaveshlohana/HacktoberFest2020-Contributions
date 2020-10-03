#include<bits/stdc++.h>
using namespace std;
int main(){
  // storing the capacity of the knapsack and the number of packages/bags
  int capacity, bag;
  cin>>capacity>>bag;

  int weight[bag]; //weights of the bag
  int value[bag]; // value of each bag

  for(int i=0;i<bag;i++){
  cin>>weight[i];
  }

  for(int i=0;i<bag;i++){
  cin>>value[i];
  }

  int dp[bag+1][capacity+1];

  for(int i=0;i<=bag;i++){
  dp[i][0]=0;
  }
   for(int i=0;i<=capacity;i++){
    dp[0][i]=0;
  }

  for(int i=1;i<=bag;i++){
  for(int j=1;j<=capacity;j++){

    if(weight[i-1]>j){
    dp[i][j]= dp[i-1][j] // the case where the weight of the bag is greater than the capacity of the knapsack
    }
    else{
    dp[i][j]= max(dp[i-1][j], dp[i-1][j-weight[i-1]]+val[i-1]); // we compare that if we get the maximum profit by including or excluding this weight of capacity less than the knapsack
    }

  }
  }
cout<< dp[bag][capacity]<<capacity;
return 0;
}
