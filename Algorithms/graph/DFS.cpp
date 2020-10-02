#include <iostream>
#include <vector>
using namespace std;
class Graph
{
    int numV;
    vector<int> *adjList;

public:
    Graph(int);
    void addEdge(int, int);
    void display();
    void dfs(int, bool[]);
};

Graph::Graph(int numV)
{
    this->numV = numV;
    this->adjList = new vector<int>[numV];
}

void Graph::addEdge(int u, int v)
{
    this->adjList[u].push_back(v);
    this->adjList[v].push_back(u);
}
void Graph::display()
{
    for (int i = 0; i < numV; i++)
    {
        cout << i << " -> ";
        for (auto x : adjList[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void Graph::dfs(int startVertex, bool *visited)
{
    if (visited[startVertex] == true)
        return;
    cout << startVertex << " ";
    visited[startVertex] = true;
    for (auto x : adjList[startVertex])
    {
        dfs(x, visited);
    }
}
int main()
{

    Graph gg(7);

    gg.addEdge(0, 1);
    gg.addEdge(0, 2);
    gg.addEdge(1, 3);
    gg.addEdge(1, 4);
    gg.addEdge(2, 4);
    gg.addEdge(3, 4);
    gg.addEdge(3, 5);
    gg.addEdge(4, 5);
    gg.display();
    cout << endl;

    bool visited[6] = {false};
    gg.dfs(0, visited);
    cout << endl;
}
