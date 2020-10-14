#include<bits/stdc++.h>
#define int long long int
using namespace std;


int const mod = 1e9+7;
int power(int a, int b)
{
    int res = 1;
    while(b)
    {
        if(b&1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return res;
}

int inverse(int x){
    return power(x,mod-2,mod);
}

int const N = 1e6+55;
int fact[N], ifact[N];

void precompute()
{
    fact[0] = 1;
    for(int i=1; i<N; i++)
        fact[i] = (fact[i-1] * i) % mod;
    
    ifact[N-1] = inverse(fact[N-1]);
    for(int i=N-2; i>=0; i--)
        ifact[i] = ((i+1) * ifact[i+1]) % mod;
}

int ncr(int n, int r)
{
    if(r<0 or r>n) return 0;
    if(n == r) return 1;

    int res = (fact[n] * ifact[n-r]) % mod;
    res = (res * ifact[r]) % mod;
    return res;
}
