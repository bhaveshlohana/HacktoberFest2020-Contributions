//C program for sorting the array using bubble sort
#include <stdio.h>
#include <stdlib.h> 

void accept(int a[], int n);
void display(int a[], int n);
void bubble(int a[], int n);

void main()
{
    int n, a[100],i;
    printf("\n Enter the no of elements");
    scanf("%d", &n);
    accept(a, n);
     bubble(a, n);
    display(a, n);
}

void display(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("\t%d", a[i]);
    }
}
void accept(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
}

void bubble(int a[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
