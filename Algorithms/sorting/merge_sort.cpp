#include<iostream>
#include<vector>

using namespace std;

void Merge(int arr[],int l,int u){
  int n=u-l;
  int m=l+n/2;

  int p=m-l;
  int q=u-m;

  int result[n];

  while(p>=0 && q>=0){
    int a=arr[l+p-1];
    int b=arr[m+q-1];

    if(b>=a){
      result[p+q-1]=b;
      q--;
    }
    else{
      result[p+q-1]=a;
      p--;
    }
  }

  if(p>q)
  for(int i=0;i<p;i++)
  result[i]=arr[l+i];
  else
  for(size_t i=0;i<q;i++)
  result[i]=arr[m+i];

  for (size_t i = 0; i < n; i++)
    arr[l+i]=result[i];
}

void MergeSort(int arr[],int l,int u){
  if(l+1>=u)
  return;
  int m=l+(u-l)/2;
  MergeSort(arr,l,m);
  MergeSort(arr,m,u);
  Merge(arr,l,u);
}
int main()
{
cout<<"Enter the size of vector \n";
int n;
cin>>n;

cout<<"Enter the values to be sorted \n";
int arr[n];
for(size_t i=0;i<n;i++)
cin>>arr[i];

MergeSort(arr,0,n);

for(size_t i=0;i<n;i++)
cout<<arr[i]<<" ";

cout<<endl;
}
