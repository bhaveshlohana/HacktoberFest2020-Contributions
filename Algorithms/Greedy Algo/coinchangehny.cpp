#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int getcoins(vector<int>& a, int n){

int c=0;


for(int i=0;n>0;i++){


    c+=n/a[i];

    n= n%a[i];
}

return c;


}

int main(){
int t;
cin>>t;

while(t-->0){ int n;
    cin>>n;
vector<int>a= {10,5,1};

    cout<<getcoins(a,n)<<"\n";
    }

}
