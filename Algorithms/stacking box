//103 Stacking Boxes
#include<bits/stdc++.h>

using namespace std;

int findSeq(vector<vector<int>> box,vector<int> &dp,int index){
    if(index==0){
        return 1;
    }

    int ans=1;
    for(int j=index-1;j>=0;j++){
        if(dp[j]!=-1){
            ans=max(ans,1+dp[j]);
        }
        else{
            int cnt=0;
            for(int l=0;l<box[index].size();l++){
                if(box[index][l]>box[j][l]){
                    cnt++;
                }
            }
            if(cnt==box[index].size()){
                dp[j]=1+findSeq(box,dp,j);
                ans=max(ans,dp[j]);
            }
            
        }
    }

    return ans;
}

int main(){
    
    int n,k;
    while(cin>>k){
        cin>>n;
        vector<vector<int>> box(k,vector<int> (n));

        for(int i=0;i<k;i++){
            for(int j=0;j<n;j++){
                cin>>box[i][j];
            }
            sort(box[i].begin(),box[i].end());
        }

        vector<int> dp(k,-1);

        for(int i=0;i<k;i++){
            findSeq(box,dp,0);
        }
    }

    return 0;
}
