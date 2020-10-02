
#include <bits/stdc++.h> 
using namespace std; 
  
void countingSort(vector<int> arr, int n) 
{ 
  
    map<int, int> countmp; 
    for (auto i = arr.begin(); i != arr.end(); i++) { 
        countmp[*i]++; 
    } 
  
    int i = 0; 
    for (auto it : countmp) { 
        int val = it.first; 
        int count = it.second; 
        for (int j = 0; j < count; j++) 
            arr[i++] = val; 
    } 
  
    cout<<"Sorted array is: "<<endl;
    for (auto i = arr.begin(); i != arr.end(); i++) { 
        cout << *i << " "; 
    } 
} 
  
int main() 
{ 
    int n;
    cin>>n;
    vector<int> v(n);
    for(int &it:v) cin>>it;
    countingSort(v, n); 
    return 0; 
} 
