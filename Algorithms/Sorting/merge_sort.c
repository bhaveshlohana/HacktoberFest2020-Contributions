#include <stdio.h>
#include <stdlib.h>

void Merge(int *, int, int, int);
void MergeSort(int *, int, int);

int main()
{
    int *arr;
    int n, i;

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

    MergeSort(arr, 0, n - 1);

    printf("\nThe numbers in sorting order is:");
    for (i = 0; i < n; i++)
        printf("  %d", *(arr + i));

    return 0;
}

void MergeSort(int *arr, int low, int high)
{
    int mid;
    if (low >= high)
        return;

    mid = (low + high) / 2;

    MergeSort(arr, low, mid);
    MergeSort(arr, mid + 1, high);

    Merge(arr, low, mid, high);
}

void Merge(int *arr, int low, int mid, int high)
{
    int temp[high], p, q, r, k;
    p = low;
    q = mid + 1;
    r = low;

    while (p <= mid && q <= high)
        if (*(arr + p) < *(arr + q))
            temp[r++] = arr[p++];
        else
            temp[r++] = arr[q++];

    while (p <= mid)
        temp[r++] = arr[p++];
    while (q <= high)
        temp[r++] = arr[q++];

    for (k = low; k <= high; k++)
        arr[k] = temp[k];
}


/*
================ OUTPUT ================
******* All the inputs are taking by Random Function *******

Enter how many numbers you want to sort: 9

Taking Numbers fron Random Function
The numbers before sorting :  73  92  40  15  75  81  57  61  22
The numbers in sorting order is:  15  22  40  57  61  73  75  81  92
*/
