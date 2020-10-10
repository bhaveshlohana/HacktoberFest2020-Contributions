#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int n;
int m;
vector<vector<int>>dis(n,vector<int>(m));

vector<vector<int>>vis(1001,vector<int>(1001));


bool isvalid(int sx,int sy){

if(sx<0||sx>=n||sy<0||sx>=m){

    return false;
}

if(vis[sx][sy]==1){

    return false;
}
return true;

}

void bfs(int sx,int sy){
if(sx<0||sx>=n||sy<0||sx>=m){

    return;
}

if(vis[sx][sy]==1){

    return;
}

queue<pair<int,int>> q;


q.push({sx,sy});
dis[sx][sy]=0;
vis[sx][sy]=1;

vector<int>dir={-1,0,1,0};
vector<int>diry= {0,1,0,-1};
while(!q.empty()){



    int cx= q.front().first;
    int cy= q.front().second;

for(int i=0;i<4;i++)

    if(isvalid(sx+dir[i],sy+diry[i])){



int nx= sx+dir[i];
int ny= sy+diry[i];

dis[nx][ny]= dis[cx][cy]+1;
vis[nx][ny]=1;
q.push({nx,ny});


    }


}




}



int main(){
int x, y;
    cin>>n>>m;
    cin>>x>>y;
    bfs(x,y);

    for(int i=0;i<dis.size();i++){
    for(int j=0;j<dis[0].size();j++){

cout<<dis[i][j]<<" ";
    }
    cout<<"\n";
}
}