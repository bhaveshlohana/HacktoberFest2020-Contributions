#include<iostream>
using namespace std;
int main()
{
    int max = 0;
    int check1=-1,check2=-1;
    int arr[] = {-3,2,4,-1,2,3,-2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sumarr[n];

    //Pre-Calculations
    //Calculating the first sums in the array
    for(int i=0; i<n; i++)
        {
            sumarr[i] = arr[i] + sumarr[i-1];
        }

    //Finding the max sum using the pre-calculations part i.e.sum[]
    //Formula: sum = sum[j]-sum[i]+arr[i]
    for(int i=0; i<n; i++)
        {
            int sum = 0;
            for(int j=i; j<n; j++)
                {
                    sum = sumarr[j]-sumarr[i]+arr[i];
                    if(sum>max)
                    {
                        max = sum;
                        check1 = i;
                        check2 = j;
                    }
                }  
            
        }

        cout<<"The max sum subarray is: "<<max<<endl;
        cout<<"Index range is: "<<check1<<" - "<<check2<<endl;
    return 0;
}