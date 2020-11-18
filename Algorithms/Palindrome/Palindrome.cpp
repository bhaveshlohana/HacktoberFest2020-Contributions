#include <iostream>
using namespace std;

int main()
{
     int n, num, digit, rev = 0;

     cout << "Enter a positive number: ";	//Input a number
     cin >> num;

     n = num;

     do
     {
         digit = num % 10;			//Reveresing
         rev = (rev * 10) + digit;		//the number
         num = num / 10;			
     } while (num != 0);

     cout << " The reverse of the number is: " << rev << endl;

     if (n == rev)				//Checking if the reversed number is same as the original number, ie, Palindrome
         cout << " The number is a palindrome.";
     else
         cout << " The number is not a palindrome.";

    return 0;
}
