#include <bits/stdc++.h> 
using namespace std; 
  
int sum(int frequency[], int i, int j)  
{  
    int s = 0;  
    for (int k = i; k <= j; k++)  
    s += frequency[k];  
    return s;  
}  

int optCost(int frequency[], int i, int j)  
{  
    
    if (j < i) 
    {   return 0;}  
    
	if (j == i) 
       {
		return frequency[i];} 

    int fsum = sum(frequency, i, j);   
    int min = INT_MAX;  

    for (int r = i; r <= j; ++r)  
    {  
        int cost = optCost(frequency, i, r - 1) +  
                   optCost(frequency, r + 1, j);  
        if (cost < min)  
            min = cost;  
    }  

    return min + fsum;  
}  

int optimalSearchTree(int keys[],int frequency[], int n)  
{  
    return optCost(frequency, 0, n - 1);  
}  

int main()  
{  
    int n;
    cout<<"Enter the no of keys : "<<endl;
    cin>>n;
    int keys[n]; 
    int frequency[n];
    cout<<"Enter the keys along with their frequency"<<endl;
    for(int i=0;i<n;i++)
    {
		cin>>keys[i]>>frequency[i];
    }
    cout << "Cost of Optimal BST is " << optimalSearchTree(keys, frequency, n);  
    return 0;  
}  
