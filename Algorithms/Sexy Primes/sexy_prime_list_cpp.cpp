// program to take a long integer N from the user and print all the sexy prime numbers between one and the given number
// sexy primes are those pairs of prime numbers whose difference is 6 

#include<iostream>
#include<math.h>

using namespace std;

bool isPrime(long int a)
{
    int flag=1;
    for(long int i=2;i<=sqrt(a);i++)
    {
        if(a%i==0)
		{
			flag=0;
			break;
    	}
    }
    if(flag == 1)
        return(true);
    else
        return(false);
}

int main()
{
    long int N;
    cout << "to find all sexy prime number between one and a given upper bound number (less than +2,147,483,641) " << endl;
    cout << "enter the upperbound ";
    cin >> N;
    cout << "the sexy primes in the given range are:" << endl;

    for(long int i=2;i<=N;i++)
    {
        if(isPrime(i) && isPrime(i+6))
            cout << "(" << i << "," << i+6 << ")" << endl;
    }
    return 0;
}
