#include<bits/stdc++.h>
using namespace std;
int getMaxArea(int hist[], int n) 
{ 
     
    stack<int> s; 
  
    int max_area = 0; // Initialize max area 
    int tp;  // To store top of stack 
    int area_with_top; 
    int i = 0; 
    while (i < n) 
    { 
        if (s.empty() || hist[s.top()] <= hist[i]) 
            s.push(i++); 
        else
        { 
            tp = s.top();  // store the top index 
            s.pop();
            area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1); 
  
            
            if (max_area < area_with_top) 
                max_area = area_with_top; 
        } 
    } 
    while (s.empty() == false) 
    { 
        tp = s.top(); 
        s.pop(); 
        area_with_top = hist[tp] * (s.empty() ? i :  
                                i - s.top() - 1); 
  
        if (max_area < area_with_top) 
            max_area = area_with_top; 
    } 
  
    return max_area; 
} 
int main()
{
	int n,a,i,x;
	
	cout<<"Enter the number of bars\n";
	cin>>n;
	int v[n];
	for(i=0;i<n;i++)
	{
		cout<<"Enter the height of "<<i+1<<" bar\n";
		cin>>v[i];
	}
	cout << "Maximum area is " << getMaxArea(v, n); 
    return 0;
	
}
