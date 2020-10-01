	 #include<bits/stdc++.h>
	 using namespace std;
    vector<int> merge(vector<int> left,vector<int> right)
    {
        int l=0,r=0;
        vector<int> ans;
        while(l<left.size() && r<right.size())
        {
            if(left[l]<right[r])
            {ans.push_back(left[l]);
            l++;}
            else
            if(left[l]>right[r])
                {ans.push_back(right[r]);
                r++;}
            else
            if(left[l]==right[r])
                {ans.push_back(left[l]);
                ans.push_back(left[l]);
                r++;l++;}
        }
                   
        
                   while(l<left.size())
                   {
                       ans.push_back(left[l]);
                       l++;
                   }
                   while(r<right.size())
                   {
                       ans.push_back(right[r]);
                       r++;
                   }
                   return ans;
    }
    vector<int> mergesort(vector<int> nums)
    {
        if(nums.size()==1)
            return nums;
        
        int m=nums.size()/2;
        
        vector<int> left;
        for(int i=0;i<m;i++)
            left.push_back(nums[i]);
        
        left=mergesort(left);
        
        vector<int> right;
        for(int i=m;i<nums.size();i++)
            right.push_back(nums[i]);
        
        right=mergesort(right);
        
        return merge(left,right);
    }
 
    
    int main()
    {
     int n;
     cin>>n;
     vector<int> nums(n);
     for (int i = 0; i < n; ++i)
     cin>>nums[i];
    
      vector<int> res=mergesort(nums); 
      for (int i = 0; i < n; ++i)
      cout<<res[i]<<" ";

      return 0; 
    }