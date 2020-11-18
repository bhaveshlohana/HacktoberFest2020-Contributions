#include<iostream>  
using namespace std;  
int main ()  
{    
	int n;
	cout << "Enter number of elements: ";
	cin >> n;
    int **arr = new int *[n];
    for(int i = 0; i < n; i++)
    	arr[i] = new int [n];
     int **tr = new int *[n];
    for(int i = 0; i < n; i++)
    	tr[i] = new int [n];
    cout<<"\nEnter "<< n*n <<" elements\n";
    for(int i = 0; i < n; i++)
    {
    	for(int j = 0; j < n; j++)
    		cin >> arr[i][j];
    }
    cout<<"\nOriginal Matrix\n";
    for(int i = 0; i < n; i++)
    {
    	for(int j = 0; j < n; j++)
    		cout << arr[i][j] << "\t";
    	cout << endl;
    }
    for(int i = 0; i < n; i++)
    {
    	for(int j = 0; j < n; j++)
    		tr[i][j] = arr[j][i];
    }
    cout<<"\nTranspose Matrix\n";
    for(int i = 0; i < n; i++)
    {
    	for(int j = 0; j < n; j++)
    		cout << tr[i][j] << "\t";
    	cout << endl;
    }
}  