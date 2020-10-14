#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;


int main()
{
    //ONE APPROACH
    // int arr[6]={4,5,12,-2,8,9};
    // int l=sizeof(arr)/sizeof(arr[0]);
    // for(int i = 0;i<l;i++)
    // {
    //     for(int j=i+1;j<l;j++)
    //     {
    //         if(arr[i]+arr[j]==10)
    //         {
    //             cout<<"["<<arr[i]<<","<<arr[j]<<"]"<<endl;
    //         }
    //     }
        
    // }

    //ANOTHER APPROACH
    //v= 4 5 12 2 6 9 
    int desSum,size;
    cin>>size>>desSum;
    vector<int> v(size);
    for(int &it:v) cin>>it;
    
    vector<int> n;
   for (auto itr=v.begin();itr<v.end();itr++)
    {
        int checkVal = desSum-*itr;
        if(count(n.begin(),n.end(),checkVal))
        {
            cout<<"Values: "<<checkVal<<" and "<<*itr<<endl;
            int ind1 = (find(v.begin(), v.end(), *itr) - find(v.begin(),v.end(),v.front()));
            int ind2 = (find(v.begin(), v.end(), checkVal) - find(v.begin(),v.end(),v.front()));
            cout<<"Index: ["<<ind2<<"] and ["<<ind1<<"]"<<endl;
        }
        else
        {
            n.push_back(*itr);

        }
    }
    return 0;
}



