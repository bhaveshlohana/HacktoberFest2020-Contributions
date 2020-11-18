#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> adj[10];

bool visited[10];

void dfs(int s){    // source vertex is passed as a param
visited[s]= true;
for(int i=0;i<adj[s].size();++i){

    if(visited[adj[s][i]] == false)

    dfs(adj[s][i]);
}


}

void initialize(){
for(int i=0;i<10;i++)
visited[i]= false;
}

int main(){


    int nodes,edges,u,v,connectedComponents= 0;


    cin>>nodes;  //number of nodes
    cin>>edges;  // number of edges

for(int i=0;i<edges;++i){

    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}

initialize();
// the above func marked all node as not visited;

for(int i=1;i<= nodes;++i){


    if(visited[i]== false){

       dfs(i);
        connectedComponents++;
    }
}


if(connectedComponents ==1){
cout<<"1";}
else{
    cout<<"0";
}
return 0;
}