//C program for linear search
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//Function for linear search
int linearsearch(int arr[],int size,int element)
 {
    //Searching through the array using for loop
  for(int i=0,i<size;i++)
  {
  if(arr[i]==element)
  return i;
  }
  //Returns -1 is element is not found.
 return -1;
 }

//Main program starts here
int main()
{
//Let n be the size of the array and k be the element to be searched.
int n,k;
cin>>n>>k;
int a[n];
//Taking the array elements as input
for(int i=0,i<n;i++)
{
cin>>a[i];
}
int ans = linearsearch(a,n,k);

cout<<ans;

return 0;
}
