#include<iostream>
using namespace std;
int main(int args,char** argv)
{
    int number;
    cout<<"Enter the number"<<endl;
    cin>>number;
    for(int i=0;i<=number;i++)
    {
        int val =1;
        for(int j=0;j<=i;j++)
        {
            cout<<val<<" ";
            val =(i-j) * val /(j+1); // val = ((n-r)*val) / (r+1) 
            // it can be solved combination, row and column problem.here row = j and column = i.
        }
        cout<<endl;                                                                     
    }

}