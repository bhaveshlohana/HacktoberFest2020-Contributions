#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int n,w;
    cin>>n;
    cout<<"Enter window size: ";
    cin>>w;
    vector<int> v(n),v2;
    for(int &it:v) cin>>it;
    for(auto it = v.begin();it<v.end()-(w-1);it++)
    {
        v2.push_back(max(max(*it,*(it+1)),*(it+2)));
    }
    for(auto i=v2.begin();i<v2.end();i++)
    {
        cout<<*i<<" ";
    }
    return 0;
}