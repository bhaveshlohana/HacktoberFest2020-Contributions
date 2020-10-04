#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, m;
	//number of nodes and number of edges
	cin >> n >> m;

	vector<int> adj[n + 1];
	bool vist[n + 1];

	while (m--)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	queue<int> q;
	//push any node to start with
	q.push(1);
	vist[1] = true;
	while (!q.empty())
	{
		int f = q.front();
		cout << f << " ";
		q.pop();

		for (auto child : adj[f])
			if (!vist[child])
			{
				vist[child] = 1;
				q.push(child);
			}
	}
	return 0;
}