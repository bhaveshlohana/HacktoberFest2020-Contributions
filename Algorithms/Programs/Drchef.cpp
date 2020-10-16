#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define speedup ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){
	speedup
    int t;
	cin>>t;
    while(t--){
    	ll n,x;
    	cin>>n>>x;
    	vector<ll> arr(n);
    	for(int i=0;i<n;i++)
        	cin>>arr[i];
    	sort(arr.begin(),arr.end());
    	vector<ll>::iterator it=lower_bound(arr.begin(),arr.end(),x);
    	ll min=it-arr.begin();
		ll day=0;
		for(int i=min;i<n;i++)
    	{
            while(x<arr[i]){
                x*=2;
                day++;
            }
            day++;
        	x=arr[i]*2;
    	}
    	ll t_day=min+day;
    	if(min==0)
        	cout<<t_day<<endl;
        else
    	{
        	day=0;
        	min--;
        	for(int i=min;i<n;i++)
        	{
            		while(x<arr[i])
            		{
            			x*=2;
            			day++;
					}
					day++;
            	x=arr[i]*2;
        	}
        	if(day+min>=t_day)
            	cout<<t_day<<endl;
        	else
            	cout<<day+min<<endl;
    	}
	}
    return 0;
}
