//KARDEN'S ALGORITHM SOLVS THIS PROBLEM with O(n) comlplexity
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n]={};
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    //In this only 2 variables will be used
    int currSum = 0,maxSum = INT_MIN;
    for(int i=0; i<n; i++){
        currSum+=arr[i];
        if(currSum>maxSum){
            maxSum = currSum;
        }
        
        if(currSum<0){
            currSum = 0;
        }
    }
    cout<<"The max sum subarray is: "<<maxSum<<endl;
    return 0;
}
