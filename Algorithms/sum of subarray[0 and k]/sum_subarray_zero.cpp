#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<set>
#include<cmath>
#include<numeric>
#define LL long long
using namespace std;

int main()
{
    int sum=0,index_from,index_to;
    string found = "false";
    vector<int> v={8,1,4,3,-7,-6,2},v2;
    for(auto i:v)
    {
        v2.push_back(sum);
        sum+=i;
        if(count(v2.begin(),v2.end(),sum))
        {
            index_from = (find(v2.begin(), v2.end(), sum) - find(v2.begin(),v2.end(),v2.front()));
            index_to = (find(v.begin(), v.end(), i) - find(v.begin(),v.end(),v.front()));
            found = "true";
            break;
        }
    }
    cout<<found<<endl<<"Index value range is: "<<index_from<<" - "<<index_to;
    return 0;
}