#include<bits/stdc++.h>
#define int long long int
using namespace std;

int dp[100][1000];

void Read(vector<int> &integers){
  for(int i=0;i<integers.size();i++){
    cin>>integers[i];
  }
}

int Solve(vector<int> &integers,int n,int s){
  if(s==0 && n>=0)
  return 1;

  if(n==0 && s>0)
  return 0;

  if(dp[n][s]!=-1)
  return dp[n][s];

  dp[n][s]=Solve(integers,n-1,s);

  if(integers[n-1]<=s){
    dp[n][s]= dp[n][s] || Solve(integers,n-1,s-integers[n-1]);
  }

  return dp[n][s];
}

int32_t main(){
  memset(dp,-1,sizeof(dp));
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin>>t;
  for (size_t x = 0; x < t; x++) {
    int n,s;
    cin>>n>>s;
    vector<int> integers(n);
    Read(integers);
    bool Result=Solve(integers,n,s);
    if(Result)
    cout<<"1\n";
    else
    cout<<"0\n";
    //cout<<"Case #"<<x+1<<": "<<Result<<endl;
  }

}
