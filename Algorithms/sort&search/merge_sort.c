//C program for merge_sortinggit 
#include <stdio.h>
void accept(int a[], int n);
void display(int a[], int n);
void merge(int a[], int low, int mid, int high);
void mergesort(int a[], int low, int high);

void main()
{
    int n, a[100];
    printf("\n Enter the no of elements");
    scanf("%d", &n);
    accept(a, n);
    mergesort(a, 0, n - 1);
    display(a, n);
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
        printf("\t%d", a[i]);
    }
}

void mergesort(int a[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

void merge(int a[], int low, int mid, int high)
{
    int i, j, k, b[100];
    i = low;
    j = mid + 1;
    k = 0;

    while ((i <= mid) && (j <= high))
    {
        if (a[i] <= a[j])
        {
            b[k++] = a[i++];
        }
        else
        {
            b[k++] = a[j++];
        }
    }
    while (i <= mid)
    {
        b[k++] = a[i++];
    }
    while (j <= high)
    {
        b[k++] = a[j++];
    }

    //copy merged element from b to a
    for (j = low, k = 0; j <= high; j++, k++)
    {

        a[j] = b[k];
    }
}