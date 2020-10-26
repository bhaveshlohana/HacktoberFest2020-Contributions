/*
Given an array nums of n integers, are there elements a, b, c in nums
such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Notice that the solution set must not contain duplicate triplets.

*/




#include <bits/stdc++.h>
using namespace std;

// function for calculating 3Sum
vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        if(nums.size()<3){
            return ans;
        }
        int f=0;
        for(auto it:nums){
            if(it!=0)
                f=1;
        }
        if(f==0){
            ans.push_back({0,0,0});
            return ans;
        }
        map<int,pair<int,int>>mp;
        int i=0;
        for(auto it:nums){
            mp[it].first++;
            mp[it].second=i++;
        }
        set<vector<int>>st;
        for(int i=0;i<nums.size()-2;i++){
            if(i!=0&&nums[i]==nums[i-1])
                continue;
            for(int j=i+1;j<nums.size()-1;j++){
                int x = nums[i],y=nums[j],z = -(x+y);
                if(i==j)
                    continue;
                if(mp.count(z)&&mp[z].second>j){
                    vector<int>temp={x,y,z};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                    // ans.push_back({x,y,z});
                }
            }
        }
        for(auto it=st.begin();it!=st.end();it++){
            ans.push_back(*it);
            // cout<<endl;
        }
        return ans;
    }


//Driver Code
int main() {
	// your code goes here
	int n;
	cin>>n;
	vector<int>nums(n);
	for(auto &x:nums){
		cin>>x;
	}
	vector<vector<int>> ans = threeSum(nums);
	for(int i=0;i<ans.size();i++){
		for(auto x:ans[i]){
			cout<<x<<" ";
		}
		cout<<endl;
	}
	return 0;
}