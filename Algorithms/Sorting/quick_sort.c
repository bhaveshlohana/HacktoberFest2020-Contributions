#include <stdio.h>
#include <stdlib.h>

void swap(int *, int *);
int partition(int *, int, int);
void quickSort(int *, int, int);

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

    quickSort(arr, 0, n - 1);

    printf("\nThe numbers in sorting order is:");
    for (i = 0; i < n; i++)
        printf("  %d", *(arr + i));

    return 0;
}
//low: starting index, high: ending index
void quickSort(int *arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
//Seperately sorting elements before partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int partition(int *arr, int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1); //Index of smaller element

    for (int j = low; j <= high - 1; j++)
    {
//If current element is smaller than the pivot,increment index of smaller element
        if (*(arr + j) <= pivot)
        {
            i++;
            swap((arr + i), (arr + j));
        }
    }
    swap((arr + i + 1), (arr + high));
    return (i + 1);
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}


/*
================ OUTPUT ================
******* All the inputs are taking by Random Function *******

Enter how many numbers you want to sort: 12

Taking Numbers fron Random Function
The numbers before sorting :  68  29  16  24  55  63  16  9  77  30  20  61
The numbers in sorting order is:  9  16  16  20  24  29  30  55  61  63  68  77
*/
