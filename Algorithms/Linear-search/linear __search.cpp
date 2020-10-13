/*Program to find if number exists in any array */
#include <bits/stdc++.h>
using namespace std;

int LinearSearch(int arr[], int n, int num){
    for (int i = 0; i < n; ++i) {
        if(arr[i] == num) {
            return 1;
        }
    }
    return 0;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int number;
    cin >> number;
    if(LinearSearch(arr, n, number)) {
        cout << "Number is present in the given array";
    }
    else {
        cout << "Number is not present in the given array";
    }
    return 0;
}
