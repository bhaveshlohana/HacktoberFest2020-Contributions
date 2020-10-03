#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
/*standard declarations*/
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<pair<ll,ll> > vllp; 
#define fr(i,a,b) for(ll i=a;i<b;i++)
#define frr(i,a,b) for(ll i=a;i>=b;i--)
#define forn(i, n) for (ll i = 0; i < ll(n); i++)
#define err() cout<<"=================================="<<endl;
#define errA(A) for(auto i:A)   cout<<i<<" ";cout<<endl;
#define all(A)  A.begin(),A.end()
#define allr(A)    A.rbegin(),A.rend()
#define ft first
#define sd second
#define pb push_back
 
/*global variables here*/
ll TESTTEST;
#define mxn 2000001
#define PI 3.14159265	
#define mod 1000000007	
ll dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
ll n,k;
/*global functions here*/
void KMPsearch(string pat,string txt){
    ll n=txt.length();  // the data-string we have
    ll m=pat.length();  // the pattern-string we want to search
    ll lps[m];
    ll len=0;
    ll i=1;
    lps[0]=0;
    while(i<m){ // creating prefix functio for pattern we want to search 
            if(pat[i]==pat[len]){
            lps[i]=len+1;
            len++;
            i++;
        }
        else{
            if(len!=0){   // optimisation consider this case   abcabx-----abcabc here abcabc!=abcabx so we should not make len=0 
                len=lps[len-1]; // instead we can still see for abc and abc can still make len=3; rest u can think !
            }
            else{
                lps[i]=0;
                i++;
            }
        }
    }
    //for(ll x:lps)cout<<x<<" ";
    //cout<<"\n";
    ll j=0;
    i=0;
    while(i<n){     // we are here matching the pattern and strings 
        if(txt[i]==pat[j]){     // if both the corresponding indexes match , move forward 
            i++,j++;
        }
        else{
            if(j!=0){      // corner case where lps[-1] cant be used hence as the first letter also dont match 
                j=lps[j-1];
            }
            else{
                i++;
            }
        }
        if(j==m){
            // strings matched process answer here
            cout<<i<<" ";
            j=lps[j-1]; // still looking for optimised matching
        }
    }
}
/*main function here*/							
void solve(){
    string pat,txt;
    cin>>pat>>txt;
    cout<<"beforefunctioncalled:\n";
    KMPsearch(pat,txt);
    cout<<"afterfunctioncalled:\n";
}					
	
int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll zzz=1;
	//cin>>zzz;
	for(TESTTEST=1;TESTTEST<(zzz+1);TESTTEST++){
		solve();
	}
	return 0;
}
