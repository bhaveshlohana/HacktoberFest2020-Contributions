#include <stdio.h>
#include <stdlib.h>
int *h,n;
void bottom_up(int);
void top_down();
void display();
void heapsort(int);
void heapify(int);
int max();
int main()
{
    printf("Enter n : ");
    scanf("%d",&n);
    h = (int*)malloc(sizeof(int)*n);
    printf("Enter values : ");
    for (int i=0;i<n;i++)
        scanf("%d",&h[i]);
    top_down(n-1);
    display();
    printf("Max = %d\n", max());
    display();
    heapsort(n-1);
    display();
    bottom_up(n-1);
    display();
}
void bottom_up(int n)
{
    int i,j,key;
    for(int k=(n-1)/2;k>=0;k--)
    {
        j = k;
        key = h[j];
        i = 2*j+1;
        while(i<=n)
        {
            if((i+1)<=n)
            {
                if(h[i+1]>h[i]) i++;
            }
            if(key<h[i])
            {
                h[j] = h[i];
                j = i;
                i = 2*j+1;
            }
            else break;
        }
        h[j] = key;
    }
}
void top_down(int n)
{
    int i,j,key;
    for(int k=1;k<=n;k++)
    {
        i = k;
        key = h[i];
        j = (i-1)/2;
        while(i>0 && key>h[j])
        {
            h[i] = h[j];
            i = j;
            j = (i-1)/2;
        }
        h[i] = key;
    }
}
void display()
{
    for(int i=0;i<n;i++)
        printf("%d ",h[i]);
    printf("\n");
}
int max()
{
    int temp = h[0];
    h[0] = h[n-1];
    n--;
    heapify(n-1);
    return temp;
}
void heapify(int n)
{
    int i,j,key;
    j = 0;
    key = h[j];
    i = 2*j+1;
    while(i<=n)
    {
        if((i+1)<=n)
            if(h[i+1]>h[i]) i++;
        if(key<h[i])
        {
            h[j] = h[i];
            j = i;
            i = 2*j+1;
        }
        else break;
    }
    h[j] = key;
}
void heapsort(int n)
{
    bottom_up(n-1);
    for(int i=n;i>=0;i--)
    {
        int temp = h[0];
        h[0] = h[i];
        h[i] = temp;
        heapify(i-1);
    }
}