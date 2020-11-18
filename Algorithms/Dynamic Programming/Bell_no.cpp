/* I this problem we are required to print the Bell number sequence using
Dynamic Programming approach 
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

// Preparing a dynamic programming solution for bell no. sequence
int bell(int n)
{
	int bell[n+1][n+1];
	bell[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		bell[i][0]=bell[i-1][i-1];
		for(int j=1;j<=n;j++)
	       bell[i][j]= bell[i-1][j-1] + bell[i][j-1];
	}
	return bell[n][0];
}

int main()
{    
	int x;
	cout<<"Enter the number of terms of the Bell number sequence you want to see: ";
	cin>>x;
	for(int n=0; n<=x; n++)
		cout<<"Bell Number "<<n<<" is"<<" "<<bell(n)<<endl;
	return 0;
}