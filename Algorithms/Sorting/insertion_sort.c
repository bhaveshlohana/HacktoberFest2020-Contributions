#include <stdio.h>
#include<stdlib.h>
#include <math.h>

void insertionSort(int *, int);

int main()
{
    int n, i;
    int *arr;

    /* Input Block */
    printf("Enter how many numbers you want to sort: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));

    srand(time(0));
    printf("\nTaking Numbers fron Random Function");
    for (i = 0; i < n; i++)
        *(arr + i) = rand() % 100;

    printf("\nThe numbers before sorting :");
    for (i = 0; i < n; i++)
        printf("  %d", *(arr + i));

    /* End of Input Block */

    insertionSort(arr, n);

    printf("\nThe numbers in sorting order is:");
    for (i = 0; i < n; i++)
        printf("  %d", *(arr + i));

    return 0;
}

void insertionSort(int *arr, int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = *(arr + i);
        j = i - 1;
        while (j >= 0 && *(arr + j) > key)
        {
            *(arr + j + 1) = *(arr + j);
            j = j - 1;
        }
        *(arr + j + 1) = key;
    }
}


/*
================ OUTPUT ================
******* All the inputs are taking by Random Function *******

Enter how many numbers you want to sort: 7

Taking Numbers fron Random Function
The numbers before sorting :  61  94  82  63  28  44  38
The numbers in sorting order is:  28  38  44  61  63  82  94
*/