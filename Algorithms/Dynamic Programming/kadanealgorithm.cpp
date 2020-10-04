/*Implementing Kadane's algorithm -finding the largest sum of a subarray in an array*/

#include <iostream>
using namespace std;

int main() {
  int n;//to store array size
  int s=0;//storing sum of a subarray
  int max=-2147483648;//storing maximum sum of a subarray
  cin>>n; //Entering array size
  int a[n+1];
  for(int i=0;i<n;i++)//Enterinh elements of array
  {cin>>a[i];}

  for(int i=0;i<n;i++)
  {s=s+a[i];
   if(s<a[i])
   {s=a[i];}
   if(s>max)
   max=s;
  }
  cout<<max<<endl;
  
  
	
	return 0;
}
