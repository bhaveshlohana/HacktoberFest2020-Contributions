#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class graph{
public:

int V;
list<int>*adj;
    graph(int V);
    void add_edge(int u,int v);
void bfs(int s);
};

graph::graph(int V){

    this->V= V;
    adj= new list<int>[V];

}

void graph:: add_edge(int u,int v){
adj[u].push_back(v);
}

void graph:: bfs(int s){  ///bfs algorithm source gfg 

    bool *visited= new bool[V];

    for(int i=0;i<V;i++){

        visited[i]= false;   // marked all node as not visited;
    } 
list<int>q;  // declaring queue for storing the vertices

visited[s]= true;
q.push_back(s);

while(!q.empty()){

s= q.front();

cout<<s<<" ";
q.pop_front(); //pop the front element from the queue 


for(auto it= adj[s].begin();it!=adj[s].end();it++){
// insert the neighbouring element into the queue and marked them visited

    if(!visited[*it]){

        visited[*it]= true;
        q.push_back(*it);  // 10 17
                           // 0 2 1 3 1 4 1 5 2 3 2 8 2 9 3 7 3 9 4 6 4 7 5 6 5 7 5 9 6 8 7 8 7 9
    }
}
}
}

 int main(){

     graph g(4);
    //  g.add_edge(0,1);
    //  g.add_edge(1,4);
    //  g.add_edge(1,5);
    //  g.add_edge(2,4);
    //  g.add_edge(2,5);
    //  g.add_edge(1,4);
    //  g.add_edge(3,6);
    //  g.add_edge(6,5);

    //  cout<<"BFS traversal is given as \n";

    //  g.bfs(0);



     g.add_edge(0, 1); 
    g.add_edge(0, 2); 
    g.add_edge(1, 2); 
    g.add_edge(2, 0); 
    g.add_edge(2, 3); 
    g.add_edge(3, 3); 
  
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n"; 
    g.bfs(2); 
     return 0;

 }