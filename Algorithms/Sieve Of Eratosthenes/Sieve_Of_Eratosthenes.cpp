#include <iostream>
#include<vector>
using namespace std;

int main() {

	int n;
	cin >> n;
	bool totalprimes[n + 1];
	for (int i = 2 ; i <= n ; i++)
		totalprimes[i] = true;

	/* there is no point in checking for values of i
	where i*i > n because inner loop condition will
	not satisfy */
	for (int i = 2 ; i * i <= n ; i++)
	{
		if (totalprimes[i] == true)
		{
			// j+=i to get multiples of i
			// initially j = i*i as explained above
			for (int j = i * i ; j <= n ; j += i)
			{
				totalprimes[j] = false ;
			}
		}
	}
	vector<int> ans ;
	for (int i = 2; i <= n; i++)
	{
		if (totalprimes[i] == true )
			ans.push_back(i);
	}
	for (int i = 0 ; i < ans.size() ; i++)
		cout << ans[i] << " ";
	return 0;
}