#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void printPrimeFactor(int n)
{
    vector<pair<int, int>> prime_factors;
    int i;
    for (i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            int cnt = 0;
            while (n % i == 0)
            {
                cnt++;
                n /= i;
            }
            prime_factors.push_back(make_pair(i, cnt));
        }
    }
    if (i != 1)
    {
        prime_factors.push_back(make_pair(i, 1));
    }
    for (auto x : prime_factors)
    {
        cout << x.first << "^" << x.second << " * ";
    }
    cout << 1;
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    printPrimeFactor(n);
}
