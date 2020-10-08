/* Priyanka Gupta 
   Prims graph traversal algo
*/


//Input
// 7
// 8
// 0 3 4
// 0 1 6
// 1 2 5
// 3 2 7
// 3 4 2
// 4 5 4
// 5 6 1
// 4 6 3

#include<bits/stdc++.h>
using namespace std;
class Graph{
    int v;
    list<pair<int,int>>*l;
    public:
    
    Graph(int v){
        this->v=v;
        l= new list<pair<int,int>>[v];
    }
    void addEdge(int u,int v,int w){
        l[u].push_back({v,w});
        l[v].push_back({u,w});

    }


    int min_index(vector<bool> &visited,vector<int> &weight){
        int minIndex=-1;
        for(int i=0;i<v;i++){
            if(!visited[i]&&(minIndex==-1||weight[i]<weight[minIndex])){
                minIndex=i;
            }
        }
        return minIndex;
    }

    void prims(){  
        // first is vertice and second is weight 

        vector<bool>visited(v);
        vector<int>parent(v);
        vector<int>weight(v);
        for(int i=0;i<v;i++){
            weight[i]=INT_MAX;
            visited[i]=false;
        }
        parent[0]=-1;
        weight[0]=0;

        for(int i=0;i<v;i++)
        {   
            int minIndex=min_index(visited,weight);  //minIndex starting node
            
            for(auto x:l[minIndex]){
                
                if(!visited[x.first]){
                    if(x.second<weight[x.first]){
                        weight[x.first]=x.second;
                        parent[x.first]=minIndex;
                    }
                }
            
            visited[minIndex]=true;

            }
        }    

        for(int i=1;i<v;i++){
            cout<<i<<"---"<<parent[i]<<"<--"<<weight[i]<<endl;
        }
    }
};
int main(){
     
     int n,e;
     cin>>n>>e;
     Graph g(n);

     for(int i=0;i<e;i++){
         int x,y,w;
         cin>>x>>y>>w;
         g.addEdge(x,y,w);
     }
     
     g.prims();
}

