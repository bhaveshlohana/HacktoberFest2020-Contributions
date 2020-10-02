#include<iostream>
using namespace std;
int main(int args,char** argv)
{
    int number,i,j;
    cout<<"Enter the Number";
    cin>>number;
    for( i=1;i<=number;i++)
    {
        for( j=1;j<=number;j++)
        {
            
            if(i==j || i + j == number+1 )
            {
                cout<<"*";
            }
            else
            {
                cout<<" ";
            }
            
        }
        cout<<endl;
    }
    return 0;
}