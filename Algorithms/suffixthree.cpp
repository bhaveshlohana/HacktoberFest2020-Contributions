#include<bits/stdc++.h>
using namespace std;
 
int main(){
     long long int i,t,n;
     string f;
     cin>>t;
     for(i=0;i<t;i++)
     {
          cin>>f;
          n=f.size();
          if(f[n-1]=='o' && f[n-2]=='p')
          {
               cout<<"FILIPINO\n";
          }
          else if(f[n-1]=='u' && f[n-2]=='s' && f[n-3]=='e' && f[n-4]=='d')
          {
               cout<<"JAPANESE\n";
          }
          else if(f[n-1]=='u' && f[n-2]=='s' && f[n-3]=='a' && f[n-4]=='m')
          {
               cout<<"JAPANESE\n";
          }
          else 
          {
               cout<<"KOREAN\n";
          }
     }
     return 0;
}
