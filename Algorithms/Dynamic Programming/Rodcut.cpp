#include<bits/stdc++.h>
using namespace std;

int rodcut(int pri[],int n)
{
    int opti[n+1];
    opti[0]=0;
    for(int i=1;i<=n;i++)
     {
          int q=INT_MIN;
          for(int j=1;j<=i;j++)
          {
              q=max(q,pri[j]+opti[i-j]);
          }
          opti[i]=q;
     }
     return opti[n];
}
int main()
{
    int n;
    cout<<"Enter size";
    cin>>n;
    int b[n+1];
    b[0]=0;
    cout<<"Enter the cut prices";
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
    }

       cout<<rodcut(b,n);

   return 0;

}

