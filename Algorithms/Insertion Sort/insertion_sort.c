//C program for sorting the array using insertion sort
#include <stdio.h>
void accept(int a[], int n);
void display(int a[], int n);
void insertion(int a[], int n);

void main()
{
    int n, a[100];
    printf("\n Enter the no of elements");
    scanf("%d", &n);
    accept(a, n);
    insertion(a, n);
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

void insertion(int a[], int n)
{
    int i, j, temp;
    for (i = 1; i < n; i++)
    {
        temp = a[i];

        for (j = i - 1; j>=0 && a[j] > temp; j--)
        {
            a[j+1]=a[j];
        
        }
        a[j +1 ] = temp;
    }
}