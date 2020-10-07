#include<bits/stdc++.h>
using namespace std;
void solver(){
  int find;
  cout<<"Enter the element to search : ";
  cin>>find;
  int n;
  cout<<"Enter the size of the array :";
  cin>>n;
  int arr[n];
  cout<<"Enter the elements of array : ";
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  int flag=0;
  for(int i=0;i<n;i++){
    if(arr[i]==find){
      cout<<"Found at : "<<i<<"\n";
      flag=1;
    }
  }
  if(flag==0){
    cout<<"NOT FOUND!!!";
  }
}
int main(){
  solver();
  return 0;
}
