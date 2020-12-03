
bool isPalindrome(string s,int i,int j){
	string temp="";
	for(int x=i;x<=j;x++)
	temp+=s[x];
	string rev_temp=temp;
	reverse(rev_temp.begin(),rev_temp.end());
	return rev_temp==temp;
}

//initialise i and j in main() as i=0 and j=s.length()-1
int solve(string s,int i,int j){
	if(i>=j)
	return 0;
	if(isPalindrome(s,i,j))
	return 0;
	int mn=INT_MAX;
	for(int k=i;k<j;k++){
		int temp_ans=solve(s,i,k)+solve(s,k+1,j)+1;
		mn=min(mn,temp_ans);
	}
	return mn;
}
