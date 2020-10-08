/*
input=
5
1 2 3 4 5

output=
9

*/


#include <bits/stdc++.h>

using namespace std;

int main()
{
    long l;
    cin>>l;
    vector<long>arr(l);
    for(long i=0;i<l;i++)
    {cin>>arr.at(i);}
    long maximum=0,temp=0;
    for(long i=0;i<l;i++)
    {   temp=0;
        long x,y;x=i;
        while(x<l && arr[x]>=arr[i])
        {
            x++;temp+=arr[i];
        }
        y=i-1;
        while(y>=0 && arr[y]>=arr[i] )
        {
            y--;temp+=arr[i];
        }
        
        maximum=max(maximum,temp);
    }
    cout<<maximum<<'\n';
    return 0;
}    
