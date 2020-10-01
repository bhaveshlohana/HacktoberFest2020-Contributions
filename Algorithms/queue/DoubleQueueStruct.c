#include <stdio.h>
#include <stdlib.h>
typedef struct queue
{
    int *p;
    int n, top;
} QUEUE;
void enqueue_front(QUEUE*, int);
void dequeue_front(QUEUE*);
void enqueue_back(QUEUE*, int);
void dequeue_back(QUEUE*);
void display(QUEUE*);
int main()
{
    QUEUE *q = (QUEUE*)malloc(sizeof(QUEUE));
    printf("Enter size of queue : ");
    scanf("%d", &(q->n));
    q->top = -1;
    q->p = (int*)malloc(sizeof(int)*(q->n));
    enqueue_front(q,1);
    enqueue_front(q,2);
    enqueue_front(q,3);
    enqueue_back(q,4);
    enqueue_back(q,5);
    enqueue_back(q,6);
    display(q);
    dequeue_front(q);
    display(q);
    dequeue_back(q);
    display(q);
    free(q);
}
void enqueue_front(QUEUE *q, int data)
{
    if (q->top==((q->n)-1))
    {
        printf("Queue Full!\n");
    }
    else
    {
        q->top+=1;
        for(int i = q->top;i>=1;i--)
        {
            q->p[i] = q->p[i-1];
        }
        q->p[0] = data;
    }
}
void enqueue_back(QUEUE *q, int data)
{
    if (q->top==((q->n)-1))
    {
        printf("Queue Full!\n");
    }
    else
    {
        q->top+=1;
        q->p[q->top] = data;
    }
}
void dequeue_front(QUEUE *q)
{
    if (q->top!=-1)
    {
        for(int i = 0; i<q->top;i++)
        {
            q->p[i] = q->p[i+1];
        }
        q->top-=1;
    }
    else
    {
        printf("QUEUE EMPTY\n");
    }
    
}
void dequeue_back(QUEUE *q)
{
    if (q->top!=-1)
    {
        q->top-=1;
    }
    else
    {
        printf("QUEUE EMPTY\n");
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
