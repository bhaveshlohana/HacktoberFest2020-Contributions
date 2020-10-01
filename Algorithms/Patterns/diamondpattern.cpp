#include<iostream>
using namespace std;
int main(int args,char** argv)
{
    int number,nst,nsp,cst,csp;
    cout<<"Enter the Number";
    cin>>number;
    nsp = number -1;
    nst = 1;
    for(int i=1;i<=number;i++)
    
    {
        for(csp=1;csp<=nsp;csp++)
        {
          cout<<" ";
        }
        for(cst=1;cst<=nst;cst++)
        {
          cout<<"*";
        }
        cout<<endl;
        if(i<=number/2)
        {
          nsp--;
          nst+=2;
        }
        else
        {
          nsp++;
          nst-=2;
        }
        
    }
}