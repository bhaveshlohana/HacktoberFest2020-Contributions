//KARDEN'S ALGORITHM SOLVS THIS PROBLEM with O(n) comlplexity
#include<iostream>
using namespace std;
int main()
{
    int arr[] = {-3,2,4,-1,2,3,-2};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    //In this only 2 variables will be used
    int currSum = 0,maxSum = INT16_MIN;
    for(int i=0; i<n; i++)
        {
            //Adding value
            currSum+=arr[i];
            
            //Setting max value
            if(currSum>maxSum)
            {
                maxSum = currSum;
            }

            //Checking current sum negative value occurance
            if(currSum<0)
            {
                currSum = 0;
            }

        }
    
    cout<<"The max sum subarray is: "<<maxSum<<endl;
    return 0;
}