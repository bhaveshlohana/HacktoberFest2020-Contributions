/* Priyanka Gupta 
   Bellman ford graph traversal algo

   input
   // 8 5
// 0 1 -1
// 0 2 4
// 1 2 3
// 3 2 5
// 4 3 -3
// 1 4 2
// 1 3 2
// 3 1 1

*/



#include<bits/stdc++.h>
using namespace std;
class Edge{
    public:
    int src;
    int dest;
    int weight;

};
class Graph{
    int e, v;
    Edge*edges;
    public:
    Graph(int e,int v){
        this->e=e;
        this->v=v;
        edges=new Edge [e];        
    }
    void addEdge(int u, int v,int w,int c){
        edges[c].src=u;
        edges[c].dest=v;
        edges[c].weight=w;
    }

    void bellmanford(int src){
        vector<int>distance(v);
        for(int i=0;i<v;i++){
            if(i==src){
                distance[i]=0;
            }
            else{
                distance[i]=INT_MAX;
            }
        }

        for(int j =0;j<(v-1);j++){
            for(int i=0;i<e;i++){
                int src =edges[i].src;
                    int dest= edges[i].dest;
                    int wt=edges[i].weight;
                    
                    if( distance[src]!=INT_MAX && distance[src]+wt<distance[dest])
                    {
                          distance[dest]=wt+distance[src];
                    }

                }
               
            }

           for(int i=0;i<e;i++){
                    int src =edges[i].src;
                    int dest= edges[i].dest;
                    int wt=edges[i].weight;
                    
                     if( distance[src]!=INT_MAX && distance[src]+wt<distance[dest]){
                          cout<<"cyclic negative loop"<<endl;
                          return;
                    }

            }

            for(int i=0;i<v;i++){
                cout<<i<<" "<<distance[i]<<endl;
            }
    }
};


int main(){
    int e,v;
    cin>>e>>v;
    Graph g(e,v);
    int src,dest,wt;
    for(int i=0;i<e;i++){
        cin>>src>>dest>>wt;
        g.addEdge(src,dest,wt,i);
    }
    g.bellmanford(0);
}

