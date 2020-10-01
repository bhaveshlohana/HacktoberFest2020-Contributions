//This code returns the index at which element to be searched is present.


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int linearsearch(arr[],size,element)
 {
  for(int i=0,i<size;i++)
  {
  if(arr[i]==element)
  return i;
 
  }
 return -1;
 }
//Let n is the size of the array and k is the elment to be searched.
int main()
{
int n,k;
cin>>n>>k;
int a[n];
for(int i=0,i<n;i++)
{
cin>>a[i];
}
int ans = linearsearch(a,n,k);

cout<<ans;

return 0;
}

