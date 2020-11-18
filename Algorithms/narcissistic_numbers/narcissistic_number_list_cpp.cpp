// program to take a long integer N from the user and print all the narcissistic number between one and the given number
//narcissistic numbers are those whose sum of individual digits each raised to the power of the number of digits gives the orignal number

#include<iostream>
#include<math.h>

using namespace std;

int digitcount(long int p)
{
    int b=log10(p)+1;
    return(b);
}

bool isNstc(long int a)
{
    if(a<=9 && a>0)
        return(true);
    int q=0;
    int num_digits = digitcount(a);
    for(int i=0;i<num_digits;i++)
    {
        int digit = a/pow(10,i);
        digit = digit % 10;
        q+=pow (digit,num_digits);
    }
    if(q==a)
    {
        return(true);
    }
    else
    {
        return(false);
    }
    
}

int main()
{
    long int N;
    cout << "to find all narcissistic number between one and a given upper bound number (less than +2,147,483,647) " << endl;
    cout << "enter the upperbound ";
    cin >> N;
    cout << "the narcissistic numbers in the given range are:" << endl;
    for(long int i=1;i<=N;i++)
    {
        if(isNstc(i))
            cout << i << endl;
    }
    return 0;
}