#include <bits/stdc++.h>
using namespace std;
/*
--------------------------------------------------------------------------

                    Snakes and Ladder Problem
                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

-> This program is for a 5x6 board with 30 as the final destination.

-> We start at 1 as the source.

-> We create an adjacency matrix for the board by treating it as a graph.

-> Each cell can be thought of as a node, which has a directed edge 
    to all of the nodes it can reach in the next die roll.

-> If we come across a ladder or snake within our next move from 
    current state, then in our directed edge is shifted from the start
    cell (bottom of the ladder/ mouth if the snake) to the end cell
    (top of the ladder/ tail of the snake).

-> Once the adjacency matrix is created, we perform BFS search on the 
    graph. BFS gives the shortest path in an unweigthed graph as - 

        "... the first time a node is visited is the shortest path 
            to that node from the source node."

-> We maintain a distance matrix to keep track of shortest distances
    of nodes from source to them. The result is the distance of the
    30th cell.

--------------------------------------------------------------------------
*/


void BFS(vector<vector <int>> &adj)
{
    queue <int> children;
    bool visited[adj[0].size()];
    memset(visited,0,sizeof(visited));
    vector <int> dists(31,INT_MAX);

    children.push(1);
    
    dists[1] = 0;
    int row_index=0,isend=0;

    while(!isend)
    {
        row_index = children.front();
        children.pop();
        
        visited[row_index] = true;

        for(int i=row_index+1; i<31; i++)
            {
                // cout<<i<<endl;
                if( !visited[i] && adj[row_index][i] == 1 )
                {
                    dists[i] = dists[row_index] + 1;
                    if(i==30)
                        isend=1;
                    visited[i] = true;
                    children.push(i);
                }
            }
    }
   
    cout<<dists[30]<<endl;
   
}


int main() {
	
		
	int t;
	cin>>t;
	while(t--)
	{
	    int n=0,start,end;
	    cin>>n;
	    vector <vector<int>> adj;
	    adj.push_back(vector<int> (31,0));
	    
	    for(int i= 1; i<30; i++)
	    {
	        vector <int> directed(31,0);
	        for(int j=i+1; j<i+7; j++)
	        {
	            if(j > 30)
	                continue;
	            directed[j] = 1;
	        }
	        adj.push_back(directed);
	    }
	
	    for(int i=0 ; i<n; i++)
	    {
	        cin>>start;
	        cin>>end;

            for(int i = start - 6; i<start;i++)
            {
                if(i<1)
                    continue;
                adj[i][start] = 0;
                adj[i][end] = 1;
            }
	        
	    }
	   
	   BFS(adj);
	     
	}
	 
	return 0;
}
