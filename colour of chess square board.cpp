#include<iostream>
#include<cctype>
using namespace std;

int main()
{
	char string[10], x;
	cout << "Enter the coordinates of the square, \
	\nthe first coordinate A to H and second coordinate 1 to 8: ";
	cin.getline(string, 10);
	x = string[0];
	x = tolower(x);
	string[0] = x;
	if (string[0] == 'a' || string[0] == 'c' || string[0] == 'e' || string[0] == 'g')
	{
		if (string[1] == '1' || string[1] == '3' || string[1] == '5' || string[1] == '7')
			cout << "Black square";
		else
			cout << "White square";
	}
	else
	{
		if (string[1] == '1' || string[1] == '3' || string[1] == '5' || string[1] == '7')
			cout << "white square";
		else
			cout << "Black square";
	}

	return 0;
}
