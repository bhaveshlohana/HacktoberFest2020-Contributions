#include<bits/stdc++.h>

using namespace std;

string checkpair(int ar[],int n, int search ) 
{ 

    int first = 0; // first pointer
  

    int last = n - 1; // second pointer
    
  
    while (first < last) { 
  
    
        if (ar[first] + ar[last] == search) 
            return "YES"; // since element is found
  
        else if (ar[first] + ar[last] < search) 
            first++;  
  
        
        else
            last--; 
    } 
    return "NO"; // search value not found
} 

int main()
{
    int n ;
    cin>>n;

    int i,ar[n];
    for (i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    
    int value; 
    cin>>value; // value of pairsum to check
    
    cout<<checkpair(ar,n,value); // calling function
    
   return 0;   
}
    