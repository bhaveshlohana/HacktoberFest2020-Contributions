#include<iostream>
#include<bits/stdc++.h>
#include<string.h>
#define test int testcase; cin>>testcase; while(testcase--)
#define ll long long int
#define FOR(n) for(int i=1;i<=n;i++)
using namespace std;

int main()
{
		int t=0;
   test
   {
   	t++;
   	int n,x;
        cin>>n>>x;
        ll arr[n];
        queue<pair<int, int>> que;
        vector<int> ans;
        
        //int count=0,top;
        FOR(n)
        {
        	cin>>arr[i];
        	que.push(make_pair(arr[i],i));
		}
	
	    pair<int, int> top = que.front();
		while(!que.empty())
		{
			
			
			if(top.first <= x)
			{
				ans.push_back(top.second);
				que.pop();
				top = que.front();
				
			}
			else
			{
				top.first = top.first - x;
				que.pop();
				que.push(top);
				top = que.front();
				
			}
			
			
		}
		
        cout<<"Case #"<<t<<": ";
        for(int i=0;i<n;i++)
        {
        	cout<<ans[i]<<" ";
		}
		
	
		cout<<endl;
       
}
return 0;	
	
}
