#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pb push_back
#define ff first
#define ss second
#define mod 1000000007
#define FOR(i,a,b) for(int i=a;i<=b;i++)

vi ar[100001];
int vis[100001];

void dfs(int i){
	vis[i]=1;
	for(int c : ar[i]){
		if(!vis[c])
			dfs(c);
	}
}

int main(){
	
	int v,e,a,b;	
	cout<<"Enter the number of vertices and edges: ";
	cin>>v>>e;
	cout<<"Enter the edge pairs: \n";
	cout<<"eg. if vertex 2 and 3 are connected by an edge, enter : 2 3\n";
	FOR(i,1,e)	cin>>a>>b, ar[a].pb(b), ar[b].pb(a);
	int connected=0;

	FOR(i,1,v){
		if(!vis[i])
		{
		connected++;
		dfs(i); 
		}
	}
	cout<<"The number of connected components are: ";
	cout<<connected<<endl;
	return 0;
}
