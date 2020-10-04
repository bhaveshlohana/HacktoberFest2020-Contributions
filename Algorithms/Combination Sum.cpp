 #include<bits/stdc++.h>
 using namespace std;
 vector<int> t;
     vector<vector<int>> ans;
    void combination(vector<int>& candidates,  int target, int j){
        
        if(target==0){
            ans.push_back(t);
        }
        
        if(target<0 || j>=candidates.size()){
            return;
        }
        
        for(int i=j;i<candidates.size();i++)
        {
            if(candidates[i]<=target){
                t.push_back(candidates[i]);
                combination(candidates, target-candidates[i], i);
                t.pop_back();
            }
            
        }
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if(candidates.size()==0) return ans;
        combination(candidates, target, 0);
        return ans;
    }
    
    int main(){
    int target, n;
    cin>>target>>n;
    vector<int> candidates(n);
    for(int i=0;i<n;i++){
    cin>> candidates[i];
    }
    combinationSum(candidates, target);
    return 0;
    }
