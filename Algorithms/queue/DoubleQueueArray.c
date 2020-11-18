#include <stdio.h>
#include <stdlib.h>
int n;
int top;
void enqueue_front(int*,int);
void dequeue_front(int*);
void enqueue_back(int*,int);
void dequeue_back(int*);
void display(int*);
int peek(int*);
int main()
{
    printf("Enter size of double ended queue : ");
    scanf("%d", &n);
    top = -1;
    int *q = (int*)malloc(sizeof(int)*n);
    enqueue_front(q,1);
    enqueue_front(q,2);
    enqueue_front(q,3);
    enqueue_back(q,4);
    enqueue_back(q,5);
    enqueue_back(q,6);
    display(q);
    printf("%d\n",peek(q));
    dequeue_front(q);
    dequeue_back(q);
    display(q);
    free(q);
}
void enqueue_front(int *q, int val)
{
    if(top==n-1)
    {
        printf("Queue Full!\n");
    }
    else
    {
        top+=1;
        for (int i = top;i>0;i--)
        {
            q[i] = q[i-1];
        }
        q[0] = val;
    }
}
void enqueue_back(int *q, int val)
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
void dequeue_front(int *q)
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
void dequeue_back(int *q)
{
    if (top==-1)
        printf("Queue Empty!\n");
    else
        top--;
}
void display(int *q)
{
    for (int i = 0;i<=top;i++)
    {
        printf("%d ", q[i]);
    }
    printf("\n");
}
int peek(int *q)
{
    return q[0];
}