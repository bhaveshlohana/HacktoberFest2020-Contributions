#include <stdio.h>
#include <stdlib.h>
struct Queue
{
    //int key;
    int n, top;
    int *p;
};
typedef struct Queue QUEUE;
void enqueue(QUEUE* , int);
int dequeue (QUEUE*);
void display(QUEUE*);
void peek(QUEUE*);
int main()
{
    QUEUE *q = (QUEUE*)malloc(sizeof(QUEUE));
    printf("Enter number of elements : ");
    scanf("%d", q->n);
    q->top = -1;
    q->p = (int*)malloc(sizeof(int)*(q->n));
    enqueue(q,5);
    enqueue(q,1);
    enqueue(q,8);
    display(q);
    dequeue(q);
    display(q);
}
void enqueue(QUEUE* q, int val)
{
    if (q->top != q->n-1)
    {
        (q->top)+=1;
        q->p[q->top] = val;
    }
    else
    {
        printf("Queue Full!\n");
    }
}
int dequeue(QUEUE *q)
{
    if(q->top==-1)
    {
        printf("Queue Empty!\n");
    }
    else
    {
        int temp = q->p[0];
        for(int i=0; i<q->top; i++)
        {
            (q->p[i]) = (q->p[i+1]);
        }
        q->top-=1;
        return temp;
    }
}
void display(QUEUE *q)
{
    for (int i = 0; i<=q->top;i++)
    {
        printf("%d ", q->p[i]);
    }
    printf("\n");
}
void peek(QUEUE *q)
{
    printf("%d\n", q->p[0]);
}