#include<queue>
using namespace std;

void printBFS(int** edges, int n,int sv, bool *visited)
{
    queue<int> q;
    q.push(sv);
    //visited[0] = true;
    while(q.size() != 0)
    {
        visited[q.front()] = true;
        for(int i = 0 ; i < n; i++)
        {
            if(i == q.front())
            {
                continue;
            }
            if(edges[q.front()][i] == 1)
            {
                if(visited[i] == true)
                {
                    continue;
                }
                q.push(i);
                 visited[i] = true;
            }
        }
        cout << q.front() <<" ";
        q.pop();
    }
    for(int i = 0; i < n; i++)
    {
        if(visited[i] == false)
        {
            printBFS(edges,n,i,visited);
        }
    }
}

int main() {
    int V, E;
    cin >> V >> E;
    int** edges = new int*[V];
    for(int i = 0; i < V; i++)
    {
        edges[i] = new int [V];
        for(int j = 0; j < V; j++)
        {
            edges[i][j] = 0;
        }
    }
    for(int i = 0; i < E; i++)
    {
        int a,b;
        cin >> a >> b;
        edges[a][b] = 1;
        edges[b][a] = 1;
    }
    bool visited[V] = {false};
    printBFS(edges,V,0,visited);
  return 0;
}
