/*

PROBLEM STATEMENT: Given an array of n integers, you need to find the maximum subarray sum, considering the fact that the array if circular. 
In other words of if the array if arr[]  then next value for the i-th index is i+1 if i <n else if i==n then next index i 0

SAMPLE TEST CASES:

INPUT
[-3, 3, 5, -2, 10, -30]
OUTPUT
16
EXPLANATION {3+5-2+10} = 16, no other subarray will give better result


INPUT
[10, -3, -2, 4, -1]
OUTPUT
13
EXPLANATION {4-1+10}=13  here 4, -1, 10 is considered. P.S remember the array is circular. 

*/


// SOLUTION:


// Implementation of kadane's algo 

#include<bits/stdc++.h>
using namespace std;

int maxSubSum(vector<int>&a){
    int sumSF=0, res=0, mini=a[0];
    for(int i=0; i<(int)a.size(); i++){
        mini=min(mini, a[i]);
        sumSF = max(0, sumSF+a[i]);
        res = max(res, sumSF);
    }
    return res;
}
int maxSubarraySumCircular(vector<int>& A) {
    int n=A.size();
    if(n==0) return 0;
    int maxi=A[0];
    for(int i=0; i<n; i++) maxi=max(maxi, A[i]);
    if(maxi<=0) return maxi;
    int val1 = maxSubSum(A);
    int totalSum=0;
    for(int i=0; i<n; i++){
        totalSum += A[i];
        A[i]=-1*A[i];
    }
    
    int val2 = totalSum + maxSubSum(A);
    return max(val1, val2);
}
int main(){
    vector<int> test1={-3, 3, 5, -2, 10, -30};
    cout<<maxSubarraySumCircular(test1);
    return 0;
}

/*
Solution Explanation:

First learn about Kadane's Algo, https://en.wikipedia.org/wiki/Maximum_subarray_problem#Kadane's_algorithm 
We will be modifying the Kadane's Algo to find the maximum circular subarray sum. (mcss)

Now there are two cases:
1. The optimal subarray will be simply present in the array, without the requirement of wrapping around the ends. Example Sample test case 1


- - - - [- - - - - - - - -] - - - - -
        |<-optimal array->|

2. Now the optimal subarray will be wrapper around the edges. 
|- - - - - ]- - - - - - - [- - - - - - |
|left seg->|              |<- right seg|

That is there will be two segments one from left another from right. 


For the first case we will simply do Kadane. And store the result in val1,

For the second case if we look closely we will notice this relation
totalArray = leftSeg + MidLeftOutSeg + rightSeg

we need to find the leftSeg + rightSeg

or, leftSeg + rightSeg  = totalArray - MidLeftOutSeg


So basically we need to minimize the absolute value of MidLeftOutSeg. Do we need to write another function for finding the minimum value of MidLeftOutSeg ? NO!! we will simply invert the values of the array and then again apply Kadane's Algo to get the max "inverted" sum, which is nothing but the minimum sum. 

And then we will add( why add ? because we once inverted the signs and minus of minus makes plus. ) So we will val2. 

Now finally we will return the max value of val1 and val2

*/ 

