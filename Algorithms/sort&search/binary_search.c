// C Program for Binary_search
#include <stdio.h>
void accept(int a[], int n);
void display(int a[], int n);
void binary(int a[], int low, int high, int x);

void main()
{
    int n, a[100], low, high, x;
    printf("\n Enter no of element in array");
    scanf("%d", &n);
    accept(a, n);
    display(a, n);
    printf("\n Element to be searched");
    scanf("%d", &x);
    binary(a, 0, n-1, x);
}
void accept(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
}
void display(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d", a[i]);
    }
}
void binary(int a[], int low, int high, int x)
{
    int i, mid;
    if (low <= high)
    {
        mid = (low + high) / 2;
        if (x == a[mid])
        {
            printf("\n element is at %d", mid + 1);
        }
        else if (x < a[mid])
        {
            binary(a, 0, mid - 1, x);
        }
        else if (x > a[mid])
        {
            binary(a, mid + 1, high, x);
        }
    }
    if (low>high)
    {
        printf("\n element not found");
        
    }
    
}
