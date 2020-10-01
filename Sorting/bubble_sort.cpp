#include<bits/stdc++.h>

using namespace std;

int main()
{
    int i, n;
    cin >> n;
    int a[n];
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }
    while (1) { //taking infinite ehile loop
        bool check = false;
        for (i = 0; i <= n - 2; i++) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]); // swaping if earlier ith element is greater then i+1
                check = true;//making check true so loop doesn't terminate 
            }
        }
        if (check == false) {
            break; // breaking loop here 
        }
    }
    for (i = 0; i < n; i++) {
        cout << a[i] << " "; //input array elements
    }
}
