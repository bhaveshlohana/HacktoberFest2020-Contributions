#include<vector>
#include<iostream>

using namespace std;
typedef long long int lld;

vector < lld > ans;
lld ind = 0;

lld dfs(vector < vector < lld > > &adj, vector < lld > &vis, lld node, lld gno)
{
	if(vis[node] == gno)
		return 0;

	else if(vis[node] != -1)
		return 1;
	
	vis[node] = gno;

	for(lld i = 0; i < adj[node].size(); ++i)
	{
		if(!dfs(adj, vis, adj[node][i], gno))
			return 0;
	}

	ans.push_back(node);

	return 1;
}

int main()
{
	lld t, i;

	cin >> t;

	for(i = 0; i < t; ++i)
	{
		lld v, e, j, x, y;

		cin >> v >> e;

		vector < vector < lld > > adj(v);
		vector < lld > vis(v, -1);


		for(j = 0; j < e; ++j)
		{
			cin >> x >> y;

			adj[x].push_back(y);
		}

		for(j = 0; j < v; ++j)
		{
			if(vis[j] == -1)
			{
				if(!dfs(adj, vis, j, j))
					break;
			}
		}

		if(j != v)
		{
			cout << "Cycle present! Top sort not possible." << endl;
			continue;
		}

		for(j = ans.size() - 1; j >= 0; --j)
			cout << ans[j] << " ";

		cout << endl;
	}

	return 0;
}
