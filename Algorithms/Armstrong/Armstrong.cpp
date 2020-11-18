#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n, rem, sum = 0, power;
    cout << "Enter number";
    cin >> n;
    int temp = n;
    int count = 0;
    while (n != 0)
    {
        n = n / 10;
        count++;
    }
    n = temp;
    while (n != 0)
    {
        rem = n % 10;
        power = round(pow(rem, count));
        sum = sum + power;
        n = n / 10;
    }

    if (sum == temp)
        cout << "Armstrong number";
    else
    {
        cout << "Not a Armstrong number";
    }
}