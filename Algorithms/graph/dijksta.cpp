#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;

#define lp(var,start,end) for (ll var = start; var <end ; ++var)
#define rlp(var,start,end) for(ll var = start; var>=end ; var--)
#define pb push_back
#define mp make_pair
#define pf push_front
#define F first
#define S second
#define vll vector<ll>
#define pll pair<ll,ll> 
#define endl "\n"
const ll N=1e5+5;
const ll inf=1e16;
priority_queue<pll,vector<pll>, greater<pll>>pq;
ll vis[N];
int main()
{
    ios_base::sync_with_stdio(false);
    int n,e,p;
    cin >> n >> e>>p;
    vector<pll> G[100005];
	ll level[n+1];
	for (int i = 0; i < e; ++i)
	{
		int a,b,w;
		cin >> a >>b  >> w;
		G[a].pb(mp(b,w));
	    G[b].pb(mp(a,w));
	}

	ll x;
	cin >> x; //source
	for (int j = 0; j < n+1; ++j) level[j]=inf,vis[j]=0;
	pq.push(mp((ll)0,(ll)x));
	while( !pq.empty() )
	{
		ll a=pq.top().ff;
		ll prev=pq.top().ss;
		pq.pop();
		if(vis[prev]==0)
		{
			vis[prev]=1;
			level[prev]=a; //here is when we assign
			for (ll j = 0; j < G[prev].size(); ++j)
			{
				ll val=G[prev][j].ss;
				ll z=G[prev][j].ff;
				if(!vis[z])
				{
					pq.push(mp(level[prev]+val,z));
				}
			}
		}
	}
}
