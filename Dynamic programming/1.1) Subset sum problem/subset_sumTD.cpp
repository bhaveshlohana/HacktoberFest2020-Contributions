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
  for(int i=0;i<n+1;i++){
    dp[i][0]=1;
  }
  for(int j=1;j<s+1;j++){
    dp[0][j]=0;
  }
  for(int i=1;i<n+1;i++){
    for(int j=1;j<s+1;j++){
      dp[i][j]=dp[i-1][j];
      if(integers[i-1]<=j){
        dp[i][j]=dp[i][j]||dp[i-1][j-integers[i-1]];
      }
    }
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
