#include <bits/stdc++.h>
#define loop(i,n) for(int i=0;i<n;++i)
using namespace std;
int n;
int l=-1,r=-1;

vector<pair< int , int > > a;

int temp;
int main()
{
    int x;
    scanf("%d %d",&n,&x);

    loop(i,n)
    {
        scanf("%d",&temp );

        a.push_back(make_pair(temp,i));
    }
    sort(a.begin(),a.end());
    int left =0, right =n-1;
    while(left<right)
    {
        if( a[left].first + a[right].first == x)
        {
            l=a[left].second; r=a[right].second;
            break;
        }
        else if(a[left].first + a[right].first < x)
            ++left;
        else
            --right;
    }
    if(l==-1)
        printf("IMPOSSIBLE");
    else printf("%d %d",l+1,r+1);
    return 0;
}
