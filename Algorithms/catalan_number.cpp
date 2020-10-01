/*
Catalan numbers are a sequence of natural numbers that occurs in many interesting counting problems like following.
1) Count the number of expressions containing n pairs of parentheses which are correctly matched. For n = 3, possible expressions are ((())), ()(()), ()()(), (())(), (()()).
2) Count the number of possible Binary Search Trees with n keys (See this)
3) Count the number of full binary trees (A rooted binary tree is full if every vertex has either two children or no children) with n+1 leaves.
4) Given a number n, return the number of ways you can draw n chords in a circle with 2 x n points such that no 2 chords intersect.
*/

#include<iostream>
using namespace std;

unsigned long int catalan(unsigned int n)
{
	if (n <= 1) return 1;

	// catalan(n) is sum of catalan(i)*catalan(n-i-1)
	unsigned long int res = 0;
	for (int i=0; i<n; i++)
		res += catalan(i)*catalan(n-i-1);

	return res;
}

// Driver program to get the first 50 Catalan Numbers
int main()
{
	for (int i=0; i<50; i++)
		cout << catalan(i) << " ";
	return 0;
}
