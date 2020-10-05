#include<bits/stdc++.h>
using namespace std;
 
int main(){
     long long int i,t,n[100],a,b,c,d,f;
     cin>>t;
     for(i=0;i<t;i++)
     {
          cin>>n[i];
     }
     sort(n,n+t);
     if(n[0]==n[t-1])
     {
          cout<<"NO";
     }
     else
     {
          for(i=0;i<t;i++)
          {
               if(n[i]!=n[0])
               {
                    cout<<n[i];
                    break;
               }
          }
     }
     return 0;
}
