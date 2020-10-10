#include<iostream>
#include<bits/stdc++.h>

using namespace std;
int n,m;
vector<vector<int>>vis(1000,vector<int>(1000));

bool isvalid(int x,int y){



    if((x>n||x<0||y<0||y>m ) and(vis[x][y]== true)){
        return false;
    }

    return true;
}

void dfs(int x,int y){

    vis[x][y]= true;
    cout<<x<<" "<<y;
    if(isvalid(x,y))
    dfs(x-1,y);

     if(isvalid(x,y))
    dfs(x+1,y);

     if(isvalid(x,y))
    dfs(x,y-1);

     if(isvalid(x,y))
    dfs(x,y+1);
}

int main(){

cin>>n>>m;
dfs(1,1);



}