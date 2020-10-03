// Basic Queue Operations 
// Author @AmitManna99

#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

typedef struct queue
{
    int front,rear;
    int arr[SIZE];
} queue;

int isFull(queue *);
int isEmpty(queue *);

void insert(queue *, int);
int del(queue *);

void display(queue *);

int main()
{
    int ch, n, data;
    char c;
    queue Q = {-1,-1};
    do
    {
        printf("\n\n------MENU------\n");
        printf("1. INSERT\n");
        printf("2. DELETE\n");
        printf("3. DISPLAY\n");
        printf("Enter Choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter the element to insert : ");
            scanf("%d", &data);
            insert(&Q, data);
            break;

        case 2:
            data = del(&Q);
            if (data == -9999)
                break;
            printf("\n%d Deleted.", data);
            break;

        case 3:
            display(&Q);
            break;

        default:
            printf("\nInvalid option");
            break;

        }

        printf("\nDo you want to continue? (y/n) : ");
        c = getche();

    } while (c == 'y' || c == 'Y');

    return 0;
}

int isFull(queue *qp)
{
    if (qp->rear == SIZE - 1)
        return 1;
    return 0;
}

int isEmpty(queue *qp)
{
    if (qp->rear == qp->front)
        return 1;
    return 0;
}

void insert(queue *qp, int item)
{
    if (isFull(qp))
        printf("\nQueue is Full");
    else
    {
        qp->rear++;
        qp->arr[qp->rear] = item;
    }
}

int del(queue *qp)
{
    if (isEmpty(qp))
    {
        printf("\nQueue is Empty");
        return -9999;
    }
    else
    {
        qp->front++;
        return qp->arr[qp->front];
    }
}

void display(queue *qp)
{
    for (int i = qp->front + 1; i <= qp->rear; i++)
        printf("(%d) -", qp->arr[i]);
}