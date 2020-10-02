#include<bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define M 8000
int t[M][M];

int knapsack(int wt[],int val[], int n, int w){
	if(n==0 || w==0) return 0;
	//n and w can be memoized! As these are the only variables which are changing.
	//Thus, let's make a matrix for these, that  would be a 2D matrix

	if(t[n][w]!=-1) return t[n][w];
	if(wt[n-1]>w) return t[n][w]=knapsack(wt,val,n-1,w);
	
	return t[n][w]=max(val[n-1]+knapsack(wt,val,n-1,w-wt[n-1]), knapsack(wt,val,n-1,w));
	
}

int32_t main(){
	int wt[M],w,val[M],n;
	cout<<"Enter number of items and the capacity of Knapsack\n";
	cin>>n>>w;
	cout<<"Enter the weights\n";
	FOR(i,0,n-1) cin>>wt[i];
	cout<<"Enter the values\n";
	FOR(i,0,n-1) cin>>val[i];
	
	memset(t,-1,sizeof t);
	cout<<"Maximum possible profit is: ";
	cout<<knapsack(wt,val,n,w)<<endl; //profit from knapsack
	return 0;
}

/*
3 50
10 20 30
60 100 120
*/
