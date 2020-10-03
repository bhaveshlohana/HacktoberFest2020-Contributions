#include <stdio.h>
#include <stdlib.h>
int top = -1;
int n;
void enqueue(int*, int);
int dequeue(int*);
void peek(int*);
void display(int*);
int main()
{
    printf("Enter number of elements : ");
    scanf("%d", &n);
    int *q = (int*)malloc(n*sizeof(int));
    int val;
    for (int i = 0;i<n;i++)
    {
        printf("Enter element : ");
        scanf("%d", &val);
        enqueue(q,val);
    }
    display(q);
    dequeue(q);
    display(q);
    peek(q);
    free(q);
}
void enqueue(int *q, int val)
{
    if(top==n-1)
    {
        printf("Queue Full!\n");
    }
    else
    {
        top+=1;
        q[top] = val;
    }
}
int dequeue(int *q)
{
    if (top==-1)
        printf("Queue Empty!\n");
    else
    {
        for(int i = 0;i<top;i++)
        {
            q[i] = q[i+1];
        }
        top--;
    } 
}
void display(int *q)
{
    for(int i = 0; i<=top;i++)
    {
        printf("%d ", q[i]);
    }
    printf("\n");
}
void peek(int *q)
{
    printf("%d\n",q[0]);
}