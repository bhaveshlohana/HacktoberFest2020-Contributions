//It's basically bubble sort, but it sorts the array in descending order instead of ascending order.

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of elements: \n";
    cin >> n;
    cout << "Enter the elements into the array now: \n";
    int a[n];
    for(int i = 0; i < n; i++)  cin >> a[i];

    for(int i = n - 1; i >= 1; i--)
    {
        for(int j = i - 1; j >= 0; j--)
        {
            if(a[i] > a[j])
                swap(a[i], a[j]);
        }
    }

    cout << "After sorting in descending order: \n";
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}
