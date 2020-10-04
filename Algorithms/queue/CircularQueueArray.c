#include <stdio.h>
#include <stdlib.h>
int *q,n,top=-1,rear=-1;
void enqueue(int);
void dequeue();
void display();
int main()
{
    printf("Enter n : ");
    scanf("%d",&n);
    q = (int*)malloc(sizeof(int)*n);
    for (int i=1;i<=5;i++)
        enqueue(i);
    display();
    dequeue();
    display();
    dequeue();
    display();
    dequeue();
    display();
    dequeue();
    display();
    dequeue();
    display();
}
void enqueue(int x)
{
    if((rear+1)%n == top) return;
    rear++;
    q[rear] = x;
    if(top==-1) top++;
}
void dequeue()
{
    if (top==-1 && rear==-1) return;
    if (top==rear)
    {
        top = -1;
        rear = -1;
    }
    else
        top++;
}
void display()
{
    if(top!=-1)
    {
        for (int i=top;i<=rear;i++)
            printf("%d ",q[i]);
        printf("\n");
    }
}