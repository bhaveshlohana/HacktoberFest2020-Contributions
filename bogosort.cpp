#include <bits/stdc++.h>

using namespace std;

int isSorted(int a[], int n)
{
    while (--n > 1)
        if (a[n] < a[n - 1])
            return 0;
    return 1;
}

void shuffle(int a[], int n)
{
    for (int i = 0; i < n; i++)
        swap(a[i], a[rand() % n]);
}

void bogosort(int a[], int n)
{
    while (!isSorted(a, n))
        shuffle(a, n);
}

int main()
{
    int a[] = {2, 5, 6, 3, 10, 8, 7};
    int n = sizeof(a) / sizeof(a[0]);
    bogosort(a, n);
    printf("Sorted array :\n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}