#include<bits/stdc++.h>
using namespace std;

bool solve(int a[],int b[],int n){
	for(int i=0;i<n;i++){
		if(a[i]!=b[i] && __gcd(a[i],a[b[i]-1])!=b[i]) return false;
	}
	return true;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int a[n],b[n];
		for(int i=0;i<n;i++) {
			scanf("%d",&b[i]);
			a[i]=i+1;
		}
		if(solve(a,b,n)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}