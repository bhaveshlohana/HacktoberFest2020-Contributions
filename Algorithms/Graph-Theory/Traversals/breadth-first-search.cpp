
/*

BFS: A very standard graph traversal algorithm. 

Can be used to find Depth and shortest path in an undirected nonweighted graph


INPUT:
7 7
0 1
0 2
0 3
1 5
2 4
2 3
3 6

OUTPUT:
0 1 2 3 5 4 6 

*/



#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> adj(n);
    vector<bool> vis(n, false);
    vector<int> depth(n, 0);

    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int root=0;
    vis[0]=true;
    queue<int> qu;

    qu.push(root);

    vector<int> bfs_order;
    while(!qu.empty()){
        int cur = qu.front();
        bfs_order.push_back(cur);
        qu.pop();
        for(auto edge: adj[cur]){
            if(!vis[edge]){
                depth[edge]=depth[cur]+1;
                vis[edge]=true;
                qu.push(edge);
            }
        }
    }
    for(auto c: bfs_order) cout<<c<<" ";
    return 0;
}