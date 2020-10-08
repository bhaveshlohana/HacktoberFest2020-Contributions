#include<bits/stdc++.h>
using namespace std;
struct G
{
	int a;
	int b;
	int c;
};
G ary[100];
int tree[100];
int size[100];

void intialize(int n)
{
	for (int i = 0; i < n; ++i)
	{
		tree[i]=i;
		size[i]=1;
	}
}

int root(int i)
{
	while(tree[i]!=i)
	{
		tree[i]=tree[tree[i]];
		i=tree[i];
	}
	return i;
}
int un(int i,int j)
{
	int rA=root(i);
	int rB=root(j);
	if(size[rA]>size[rB])
	{
		tree[rB]=rA;
		size[rA]+=size[rB];
	}
	else
	{
		tree[rA]=rB;
		size[rB]+=size[rA];
	}
}

bool cmp(G i,G j)
{
	return (i.c<j.c);
}


int main()
{
	int n;
	int e;
	cin >> n >> e;
	int x,y,cost;
	for (int i = 0; i < e;++i)
	{
		cin >> x >> y >>  cost;
		ary[i].a=x;
		ary[i].b=y;
		ary[i].c=cost;
	}
	intialize(n);
	sort(ary,ary+e,cmp);
	int flag=0;
	int sum=0;
	for (int i = 0; i < e&&flag<=n-1; ++i)
	{
		if( root(ary[i].a) != root(ary[i].b) )
		{
			un (ary[i].a,ary[i].b);
			flag ++;
			sum+=ary[i].c;
		}
	}
	cout << sum << endl;
}
