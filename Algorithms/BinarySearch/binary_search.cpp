#include<bits/stdc++.h>
#include<cstring>
#define f(i,n) for( i = 0; i < n; i++)
using namespace std;

int binary_search(int a[],int  n ,int key){
	int s = 0;
	int e = n-1;
	
	while(s<=e){
		int mid = (s+e)/2;
		if(a[mid]==key){
			return mid;
		}
		else if(a[mid]>key){
			e= mid-1;
		}
		else{
			s=s+1;
		}
		return -1;
	}
	
	
}




int main(){
    int i ,n;
    int a[100];
	cin>>n;
	f(i,n) {
		cin>>a[i];
	}
	int key;
	cin>>key;
	
	cout<<binary_search(a,n,key);
	




return 0 ;
}
