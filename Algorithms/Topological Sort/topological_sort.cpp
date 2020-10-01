// Kahn's Algorithm

#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

vector<set<int>> graph(N);
int visited[N];
vector<int> topsort;
vector<int> indegree(N);

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        graph[u].insert(v);
        indegree[v]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; ++i)
        if (indegree[i] == 0)
            q.push(i);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        if (visited[node])
            continue;
        visited[node] = 1;

        for (int u : graph[node])
        {
            indegree[u]--;
            if (indegree[u] == 0)
                q.push(u);
        }

        topsort.push_back(node);
    }

    for (int i = 0; i < topsort.size(); ++i)
        cout << topsort[i] << " ";
    cout << endl;
}



// Modified Depth First Search

#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
vector<set<int>> graph(N);
int visited[N];
vector<int> topsort; // stores the topsort in reverse order

void dfs(int u)
{
    if (visited[u]) return;
    visited[u] = 1;
    for (int v : graph[u])
        dfs(v);

    topsort.push_back(u);
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        graph[u].insert(v);
    }

    for (int i = 1; i <= n; ++i)
        dfs(i);

    reverse(topsort.begin(), topsort.end());
    for (int i = 0; i < topsort.size(); ++i)
        cout << topsort[i] << " ";
    cout << endl;
}