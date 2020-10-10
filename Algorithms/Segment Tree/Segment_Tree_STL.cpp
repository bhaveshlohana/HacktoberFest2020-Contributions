// Segment Tree Implementation Using STL .
// Time Complecity-> O(logN) for both update and sum of range.
// Clean Code.

#include<bits/stdc++.h>
using namespace std;

#define MAX_INT 0x3f3f3f3f 
#define acc(x) setprecision(x)
#define boost ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007


// This function handles the sum of range function.
int  query(vector<int> &st, int l, int r, int stl, int str, int i)
{
	if(str<l || stl>r)
	{
		return 0; 
	}
	else if(l<=stl && r>=str)
	{
		return st[i];
	}
	int mid = (stl+str)/2;
	int left = query(st , l, r, stl, mid, 2*i);
	int right = query(st, l, r, mid+1, str, 2*i + 1);
	return left + right;
}


// This function handles the update query.
void update(vector<int> &st, int l, int r, int stl, int str, int i, int val)
{
	if(str<l || stl>r)
	{
		return ;
	}
	else if(l<=stl && r>=str)
	{
		st[i]=val;
		return;
	}
	int mid = (stl+str)/2;
	update(st, l, r, stl, mid,2*i, val);
	update(st, l, r, mid+1, str, 2*i+1, val);
	st[i] = st[2*i] + st[2*i+1];
	return ;
}

// Function to make the Segment Tree!
void ConstructTree(vector<int> &v, vector<int> &st, int l, int r, int i)
{
	if(l==r)
	{
		st[i] = v[l];
		return ;
	}
	int mid = (l+r)/2;
	ConstructTree(v, st, l, mid, 2*i);
	ConstructTree(v, st, mid+1, r, 2*i + 1);
	st[i] = st[2*i]+st[2*i + 1];
}

int main()
{
    //boost;
	cout << "Enter number of ele in array: ";
	int n;
	cin >> n;
	vector<int> v;
	cout << "\n Enter values: ";
	for(int i=0;i<n;i++)
	{
		int k;
		cin >> k;
		v.push_back(k);
	}
	vector<int> tree(2*n, 0);
	ConstructTree(v, tree, 0, n-1, 1);
	int q;
	cout << "Enter no. of queries: ";
	cin >> q;
	while(q--)
	{
		cout << "Enter 1 for sum and 2 for update\n";
		int y;
		cin >> y;
		if(y==1)
		{
			cout << "Enter range to find sum: ";
			int l,r;
			cin >> l >> r;
			cout << query(tree, l , r, 0, n-1, 1) << "\n";
		}
		else
		{
			cout << "Enter index and val to be updated: ";
			int l, r;
			cin >> l >> r;
			update(tree, l, l, 0, n-1, 1, r);
			cout << "Ok!\n";
		}
	}
}
