#include<bits/stdc++.h>
using namespace std;

#define MAX_INT 0x3f3f3f3f 
#define acc(x) setprecision(x)
#define boost ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007

int main()
{ 
    boost;
	int n;
	cin >> n;
	vector<int> v;


	// Given Array
	for(int i=0;i<n;i++)
	{
		int k;
		cin >> k;
		v.push_back(k);
	}
	
	// Initializing the ans as zero
	int ans = 0;

	for(int i=31;i>=0;i--)
	{
		int count = 0;
		for(int j=0;j<n;j++)
		{
			if((v[j]&(ans|(1<<i))) == (ans|(1<<i)))  //if bit is set and matches with ans
			{
				count++;
			}
			if(count>=2)		// if there are 2 numbers with same set bits
			{
				ans|=(1<<i);		// updating our answer
			}
		}
	}
	cout << ans << "\n";
    return 0;
}
