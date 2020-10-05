#include <bits/stdc++.h>
using namespace std;

int max(int a, int b)
{
	return (a > b) ? a : b;
}

// Function to get minimum
// number of trials needed in worst
// case with n eggs and k floors
int eggDrop(int n, int k)
{
	// If there are no floors,
	// then no trials needed.
	// OR if there is one floor,
	// one trial needed.
	if (k == 1 || k == 0)
		return k;

	// We need k trials for one
	// egg and k floors
	if (n == 1)
		return k;

	int min = INT_MAX, x, res;

	// Consider all droppings from
	// 1st floor to kth floor and
	// return the minimum of these
	// values plus 1.
	for (x = 1; x <= k; x++) {
		res = max(eggDrop(n - 1, x - 1),eggDrop(n, k - x));
		if (res < min)
			min = res;
	}

	return min + 1;
}

int main()
{
	int n; //Number of eggs
	int k; //Number of floors;
	cin>>n>>k;
	cout << "Minimum number of trials in worst case with "
		<< n << " eggs and " << k
		<< " floors is "
		<< eggDrop(n, k) << endl;
	return 0;
}

