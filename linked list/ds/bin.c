#include <stdio.h>
#include <stdlib.h>
int bin(int *, int, int,int);
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
    int mid=n/2;
    if (i == 0)
    {
        bin(arr, l, n,mid);
    }
    else
    {
        for (i = 0; i < n; i++)
        {
            if (arr[mid] == l)
            {
                printf("Element is found at position %d", mid + 1);
                break;
            }
            else if(arr[mid]<l){
                    mid=mid+1;
            }
            else
            {
                mid=mid-1;
            }
            
        }
    }
}
int bin(int *arr, int l, int n,int mid)
{
    {
        if (*arr == l)
        {
            printf("Element is found at position %d", mid);
            return 0;
        }
        else if (*arr<l)
        {
            return bin(arr, l, n,mid-1);
        }
        else{
            return bin(arr, l, n,mid+1);
            
        }
    }
}