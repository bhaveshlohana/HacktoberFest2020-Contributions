#include<bits/stdc++.h>
using namespace std;
vector<int> adj[11];
int vis[11];
void topo(int src,stack<int> &s)
{
	vis[src]=1;
	for(int a:adj[src])
	{
		if(vis[a]==0)
			topo(a,s);
	}
	s.push(src);
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<=n;i++)
		adj[i].clear();
	memset(vis,0,sizeof(vis));
	int a,b;
	for(int i=0;i<m;i++)
	{
		cin>>a>>b;
		adj[a].push_back(b);
	}
	stack<int> s;
	for(int i=1;i<=n;i++)
		sort(adj[i].rbegin(),adj[i].rend());
	for(int i=n;i>=1;i--)
	{
		if(vis[i]==0)
			topo(i,s);
	}
	while(!s.empty())
	{
		cout<<s.top()<<" ";
		s.pop();
	}
}
