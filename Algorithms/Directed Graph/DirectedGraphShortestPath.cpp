/* 
Algorithm Purpose: Get the length of shortest path from 1 to a certain vertex in directed graph.
For: weighted directed graph, consisting of n vertices and m edges. 

q should answer:
1. 1->v — find the length of shortest path from vertex 1 to vertex v.
2 c->l1->l2...lc — add 1 to weights of edges with indices l1, l2, ..., lc.

Input:
1. The first line contains integers n (number of vertices), m (number of edges), q (number of requests)
2. Next m lines contain the descriptions of edges: i-th of them contains description of edge with index i — three integers ai, bi, ci — the beginning and the end of edge, and its initial weight correspondingly.
3. Next q lines contain the description of edges in the format described above.

Output
the length of the shortest path from 1 to v in a separate line. ( -1, if such path does not exists.)

Example

Input
3 2 9
1 2 0
2 3 0
2 1 2
1 3
1 2
2 1 1
1 3
1 2
2 2 1 2
1 3
1 2

Output
1
0
2
1
4
2
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5+10;
const ll inf= 0x3f3f3f3f3f3f3f3f;
int n, m, aq, head[N], cnt, opt, c;
bool vis[N];

struct node
{
	int to,nxt,w;
}

e[N];
ll d[N], ad[N];
queue<int> val[N];
priority_queue<pair<ll,int> > q;
 
// adding all the vertices  
void add(int x,int y,int z) 
{
	e[++cnt].to = y, e[cnt].w = z, e[cnt].nxt = head[x], head[x] = cnt;
} 

// push the vertices in the priority queue
void dj()
{
	memset(d, 0x3f3f3f3f, sizeof(d));
	d[1] = 0, q.push(make_pair(d[1],1));
	while(!q.empty())
	{
		int x = q.top().second;
        q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(int i = head[x]; i; i = e[i].nxt)
		{
			int y = e[i].to;
			if( d[y] > d[x] + e[i].w)
			{
				d[y] = d[x] + e[i].w;
				q.push(make_pair(-d[y], y));
			}
		}
	}
}

// calculate to see where is the shortest path	
void calc()
{
	ll mx = 0;
	for(int i=0; i<=mx; i++)
		while(val[i].size())
		{
			int x = val[i].front();
            val[i].pop(); // pop after the vertex being used
			if(ad[x] < i) continue;
			for(int i = head[x]; i; i=e[i].nxt)
			{
				int y=e[i].to;
                ll z=d[x]+e[i].w-d[y];
				if( ad[y] > ad[x] + z )
				{
					ad[y] = ad[x] + z;
					if( ad[y] <= min(c, n-1))
					{
						mx = max(mx, ad[y]);
						val[ad[y]].push(y);
					}
				}
			}
		}
}
 
int main()
{
	scanf("%d%d%d", &n, &m, &aq);
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
        scanf("%d%d%d", &x, &y, &z);
		add(x,y,z);
	}
	dj();
	while(aq--) // input lines
	{
		scanf("%d%d", &opt, &c);
		if(opt==1) cout << (d[c]==inf?-1:d[c]) <<endl;
		else
		{
			for(int i=1,id;i<=c;i++) scanf("%d",&id), e[id].w++;
			memset(ad,0x3f3f3f3f,sizeof(ad));
			ad[1]=0,val[0].push(1);
			calc();
			for(int i=1;i<=n;i++) d[i]=min(inf,d[i]+ad[i]);
		}
	}
	return 0;
}



