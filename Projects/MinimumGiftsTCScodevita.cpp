#include<bits/stdc++.h>
using namespace std;
long long arr[100010];
long long brr[100010];
int main()
{
  int test_case;
  cin >> test_case;
  for(int i = 1; i <= test_case; i++)
  {
    int n;
    long long gift = 0, temp = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
      cin >> arr[i];
    }
    brr[0] = 1;
    for(int i = 1; i < n; i++)
    {
      if(arr[i] > arr[i-1])
      {
        brr[i] = brr[i-1] + 1;
      }
      else
      {
        brr[i] = 1;
      }
    }
    gift = brr[n-1];
    for(int i = n-2; i >= 0; i--)
    {
      if(arr[i] > arr[i+1])
      {
        temp = brr[i+1] + 1;
      }
      else
        temp = 1;
      gift = gift + max(temp, brr[i]);
      brr[i] = temp;
    }
    cout << gift << endl;
  }
  return 0 ;
}
