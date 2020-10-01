// Tower of Hanoi is a classical problem in Computer Science you can read more about it here:-
// https://en.wikipedia.org/wiki/Tower_of_Hanoi
// And here you can try on your own solving TOH problem
// https://www.mathsisfun.com/games/towerofhanoi.html

//The code below provides steps to solve the problem in optimal way

// CHANGE THE VALUE OF N in the main() function to change the number of disks

#include <iostream>

using namespace std;

void toh(int n, char initial, char intermediate, char final)
{
    if (n <= 1)
    {
        cout << "Move top from " << initial << " to " << final << endl;
    }
    else
    {
        toh(n - 1, initial, final, intermediate);
        cout << "Move top from " << initial << " to " << final << endl;
        toh(n - 1, intermediate, initial, final);
    }
}

int main()
{
    int n = 3;
    toh(n, 'A', 'B', 'C');
    return 0;
}