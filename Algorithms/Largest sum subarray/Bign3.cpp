//Complexity for this solution is O(n^3)
#include<iostream>
using namespace std;
int main()
    {
        int max = 0;
        int arr[] = {-3,2,4,-1,2,3,-2};
        int n = sizeof(arr)/sizeof(arr[0]);
        for(int i=0; i<n; i++)
            {
                for(int j=i; j<n; j++)
                    {
                        //Calculating sum here
                        int sum = 0;
                        for(int k=i; k<j; k++)
                            {
                                 sum+=arr[k];   
                            }
                        //Checking max value here
                        if(sum>max)
                        {
                            max = sum;
                        }        
                    }
            }
        cout<<max<<endl;
        return 0;
    }