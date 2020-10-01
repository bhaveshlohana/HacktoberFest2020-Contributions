#include<iostream>
using namespace std;

void swap(int *a,int*b)
{
    int t=*a;
    *a=*b;
    *b=t;
}

void max_heapify(int a[],int n,int i)
{
    int l = 2*i+1;
    int r = 2*i+2;
    int largest;

    if(l<n && a[l]>a[i])
        largest=l;
    else
        largest=i;

    if(r<n && a[r]>a[largest])
        largest=r;

    if(largest!=i)
    {
        swap(&a[i],&a[largest]);
        max_heapify(a,n,largest);
    }
}

void build_max_heap(int a[],int n)
{
    for(int i=n/2 -1;i>0;i--)
        max_heapify(a,n,i);
}

void heapsort(int a[], int n)
{
    build_max_heap(a,n);
    for(int i=n-1;i>0;i--)
    {
        swap(&a[0],&a[i]);
        max_heapify(a,i,0);
    }
}

int main()
{
    int n,arr[50];
    printf("Enter size of array: ");
    scanf("%d",&n);
    printf("Enter elements: ");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    heapsort(arr, n);

    printf("Sorted elements: ");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
}
