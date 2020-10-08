
    int dp[1501][1501];
    bool isPalindrome(string s,int i,int j){
	if(i>=j)
        return 1;
    while(i<j){
        if(s[i]!=s[j])
            return 0;
        i++;
        j--;
    }
        return true;
}
    int solve(string s,int i,int j){
        if(i>=j)
            return 0;
        if(isPalindrome(s,i,j))
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans=INT_MAX;
        for(int k=i;k<j;k++){
            int left,right;
            if(dp[i][k]!=-1)
                left=dp[i][k];
            else{
                left=solve(s,i,k);
                dp[i][k]=left;
            }
            if(dp[k+1][j]!=-1)
                right=dp[k+1][j];
            else{
                right=solve(s,k+1,j);
                dp[k+1][j]=right;
            }
            int temp_ans=left+right+1;
            if(temp_ans<ans)
                ans=temp_ans;
        }
        return dp[i][j]=ans;
    }
