/*
House Robber II
https://leetcode.com/problems/house-robber-ii/
*/

int func(vector<int> a,int l,int r)
{
    int n=a.size();
    int x=a[l];
    int y=max(a[l],a[l+1]);
    int z;
    for(int j=l+2;j<=r;j++)
    {
        z=max(x+a[j],y);
        x=y;
        y=z;
    }
    return z;
}
int rob(vector<int>& a) {
    int n=a.size();
    if (n == 0)
    return 0;
    if (n == 1)
    return a[0];
    if (n == 2)
    return max(a[0], a[1]);
    if (n == 3)
    return max(a[0], max(a[1],a[2]));
    return max(func(a,1,n-1),func(a,0,n-2));
}