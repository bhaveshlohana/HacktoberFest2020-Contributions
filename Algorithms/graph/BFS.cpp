#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph
{
    int numV;
    vector<int> *adjList;

public:
    Graph(int);
    void addEdge(int, int);
    void display();
    void printBFS(int);
};

void Graph::printBFS(int startVertex)
{
    queue<int> q;
    q.push(startVertex);

    bool visited[this->numV] = {false};
    visited[startVertex] = true;
    while (!q.empty())
    {
        int currentNode = q.front();
        q.pop();
        cout << currentNode << " ";
        for (auto x : adjList[currentNode])
        {
            if (!visited[x])
            {
                visited[x] = true;
                q.push(x);
            }
        }
    }
}

Graph::Graph(int V)
{
    this->numV = V;
    this->adjList = new vector<int>[V];
}

void Graph::addEdge(int u, int v)
{
    this->adjList[u].push_back(v);
    this->adjList[v].push_back(u);
}

void Graph::display()
{
    for (int i = 0; i < this->numV; i++)
    {
        cout << endl
             << i << " -> ";
        for (auto x : adjList[i])
        {
            cout << x << " ";
        }
    }
}

int main()
{
    Graph gg(6);

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
    gg.printBFS(0);
    cout << endl;
}
