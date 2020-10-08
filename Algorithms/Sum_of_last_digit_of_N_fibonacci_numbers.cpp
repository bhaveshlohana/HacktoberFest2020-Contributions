#include <iostream>
int get_fibonacci_mod_small(int n, int m)
{
    if (n == 0)
    {
        return 0;
    }
    int fib[n + 1];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        fib[i] = (fib[i - 1] + fib[i - 2]) % m;
    }

    return fib[n];
}

int get_pisano_period_length(int m)
{
    if (m == 1)
    {
        return 0;
    }
    int first = -1;
    int second = -1;
    int i = 2;
    while (1)
    {
        second = get_fibonacci_mod_small(i, m);
        if (second == 1 && first == 0)
        {
            return i - 1;
        }
        first = second;
        i += 1;
    }
}

long long get_fibonacci_huge_fast(long long n, long long m)
{
    int pisano_length = get_pisano_period_length(m);
    long long rem;
    do
    {
        rem = n % pisano_length;
        n = rem;
    } while (rem >= pisano_length);

    return get_fibonacci_mod_small(n, m);
}

int fibonacci_sum_fast(long long n, long sum = 0)
{
    return (get_fibonacci_huge_fast(n + 2, 10) - 1) % 10;
}

int main()
{
    long long n;
    std::cin >> n;
    int sum = fibonacci_sum_fast(n);
    int value = sum < 0 ? (sum + 10) : sum;
    std::cout << value;
}
