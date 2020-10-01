#include <bits/stdc++.h> 
using namespace std; 

int linearSearch(int a[], int n, int x) 
{ 
	int i; 
	for (i = 0; i < n; i++) 
		if (a[i] == x) 
			return i; 
	return -1; 
} 

// Driver code 
int main() 
{ 
	int n;
	cout<<"ENTER SIZE OF ARRAY:- ";
	cin>>n;
	int a[n];
	cout<<"ENTER ARRAY ELEMENTS:- ";
	for(int i=0;i<n;i++)
	cin>>a[i];
	
	cout<<"ARRAY ELEMENTS ARE :- ";
	for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
	
	int x;
	cout<<"\nENTER ELEMENT TO BE SEARCHED:- ";
	cin>>x;
	int index = linearSearch(a,n,x); 
	if (index == -1) 
		cout << "ELEMENT IS NOT PRESENT IN ARRAY!\n"; 
	else
		cout << "ELEMENT IS PRESENT AT POSITION :-  " << index; 

	return 0; 
} 

