#include <stdio.h>
#include <stdlib.h>
struct heapnode
{
    int data;
    int priority;
};
typedef struct heapnode HEAP;
int n;
HEAP *h;
void bottom_up(int);
void top_down();
void display();
void heapsort(int);
void heapify(int);
HEAP max();
int main()
{
    printf("Enter n : ");
    scanf("%d",&n);
    h = (HEAP*)malloc(sizeof(HEAP)*n);
    for (int i=0;i<n;i++)
    {
        printf("Enter value and priority : ");
        scanf("%d %d",&(h[i].data),&(h[i].priority));
    }
    printf("Top Down : \n");
    top_down(n-1);
    display();
    HEAP maxh = max();
    printf("Max = %d %d \n", maxh.data, maxh.priority);
    printf("New heap : \n");
    display();
    printf("Heapsort : \n");
    heapsort(n-1);
    display();
    //bottom_up(n-1);
    //display();
}
void bottom_up(int n)
{
    int i,j; HEAP key;
    for(int k=(n-1)/2;k>=0;k--)
    {
        j = k;
        key = h[j];
        i = 2*j+1;
        while(i<=n)
        {
            if((i+1)<=n)
            {
                if(h[i+1].priority>h[i].priority) i++;
            }
            if(key.priority<h[i].priority)
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
    int i,j; HEAP key;
    for(int k=1;k<=n;k++)
    {
        i = k;
        key = h[i];
        j = (i-1)/2;
        while(i>0 && key.priority>h[j].priority)
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
        printf("%d %d\n",h[i].data,h[i].priority);
}
HEAP max()
{
    HEAP temp = h[0];
    h[0] = h[n-1];
    n--;
    heapify(n-1);
    return temp;
}
void heapify(int n)
{
    int i,j; HEAP key;
    j = 0;
    key = h[j];
    i = 2*j+1;
    while(i<=n)
    {
        if((i+1)<=n)
            if(h[i+1].priority>h[i].priority) i++;
        if(key.priority<h[i].priority)
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
        HEAP temp = h[0];
        h[0] = h[i];
        h[i] = temp;
        heapify(i-1);
    }
}