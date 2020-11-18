/* 
C++ implementation to find greatest common divisor
Created By - miraajkadam
*/
#include <iostream>

using namespace std;

unsigned long long gcd (unsigned long long a, unsigned long long b) {
    if (b == 0)
        return a;
    return gcd (b, a % b);
}

int main () {
    ios_base::sync_with_stdio (false);

    unsigned long long int a, b;
    cin >> a >> b;

    cout << gcd (a, b);
}
