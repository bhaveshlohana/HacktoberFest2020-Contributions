#include <stdio.h>
#include <stdlib.h>

int min(int *, int, int);

void main()
{
    int i, j, n, loc, temp;
    int *arr;

    /* Input Block */
    printf("Enter how many numbers you want to sort: ");
    scanf("%d", &n);

    arr = (int *)malloc(n*sizeof(int));

    srand(time(0));
    printf("\nTaking Numbers fron Random Function");
    for (i = 0; i < n; i++)
        *(arr + i) = rand() % 100;

    printf("\nThe numbers before sorting :");
    for (i = 0; i < n; i++)
        printf("  %d", *(arr + i));

    /* End of Input Block */

    for (i = 0; i < n - 1; i++)
    {
        loc = min(arr, i, n);
        if (i != loc)
        {
            temp = *(arr + i);
            *(arr + i) = *(arr + loc);
            *(arr + loc) = temp;
        }
    }

    printf("\nThe numbers in sorting order is:");
    for (i = 0; i < n; i++)
        printf("  %d", *(arr + i));
}

int min(int *arr, int i, int n)
{
    int j, loc, min;
    min = *(arr + i);
    loc = i;
    for (j = i + 1; j < n; j++)
    {
        if (min > *(arr + j))
        {
            min = *(arr + j);
            loc = j;
        }
    }
    return (loc);
}


/*
================ OUTPUT ================
******* All the inputs are taking by Random Function *******

Enter how many numbers you want to sort: 8

Taking Numbers fron Random Function
The numbers before sorting :  0  90  40  42  62  85  86  91
The numbers in sorting order is:  0  40  42  62  85  86  90  91
*/