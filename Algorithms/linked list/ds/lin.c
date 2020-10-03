#include <stdio.h>
#include <stdlib.h>
int lin(int *, int, int);
int c = 0;
void main()
{
    int n, i, l;
    printf("Enter the no of Elements are there :\t ");
    scanf("%d", &n);
    int arr[n];
    printf("\nEnter the elements one by one......o_O\n ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Do you want to go with recusion(press 0) or non-recusion(press 1) ");
    scanf("%d", &i);
    printf("Enter the key element");
    scanf("%d", &l);
    if (i == 0)
    {
        lin(arr, l, n);
    }
    else
    {
        for (i = 0; i < n; i++)
        {
            if (arr[i] == l)
            {
                printf("Element is found at position %d", i + 1);
            }
        }
    }
}
int lin(int *arr, int l, int n)
{
    {
        if (*arr == l)
        {
            printf("Element is found at position %d", c);
            return 0;
        }
        else
        {
            c += 1;
            return lin(arr + 1, l, n);
        }
    }
}