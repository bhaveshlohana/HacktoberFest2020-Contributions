/*

A code for finding minimum number of platforms where timings of trains arrival and departure is given.
A good algo


*/




#include<bits/stdc++.h>
using namespace std;
bool sortcol( const vector<int>& v1, 
               const vector<int>& v2 ) { 
    if(v1[0]!=v2[0])
        return v1[0]<v2[0];
 return v1[1]<v2[1]; 
} 
int main() {
	int n;
  	cin>>n;
  	vector<vector<int>> arr(n);
  	for(int i=0;i<n;i++) {
    	int a,b;
      	cin>>a>>b;
      	arr[i]={a,b};
    }
    sort(arr.begin(),arr.end(),sortcol);
    priority_queue <int, vector<int>, greater<int>> pq;
    pq.push(arr[0][0]+arr[0][1]);
    int m=1;
    for(int i=1;i<n;i++) {
        if(pq.top()<arr[i][0]) {
            pq.pop();
        }
        else {
            m++;
        }
        pq.push(arr[i][0]+arr[i][1]);
    }
    cout<<m;
}
