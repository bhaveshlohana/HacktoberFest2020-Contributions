#include <bits/stdc++.h>
using namespace std;

int findWater(int a[], int m)
{

    int left[m];
    int right[m];
    int water = 0;

    left[0] = a[0];
    for (int i = 1; i < m; i++)
        left[i] = max(left[i - 1], a[i]);

    right[m - 1] = a[m - 1];
    for (int i = m - 2; i >= 0; i--)
        right[i] = max(right[i + 1], a[i]);

    for (int i = 0; i < m; i++)
        water += min(left[i], right[i]) - a[i];

    return water;
}

int main()
{
    // Input Format
    // n = size of array
    // arr = height of bar at ith position in an array

    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "ANSWER" << findWater(arr, n);
    return 0;
}
