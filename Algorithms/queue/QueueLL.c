#include <stdlib.h>
#include <stdio.h>
struct node
{
    int key;
    struct node *link;
};
typedef struct node NODE;
struct list
{
    NODE *head;
    int length;
    int N;
};
typedef struct list LIST;
void init(LIST*);
void enqueue(LIST *, int);
void dequeue(LIST *);
int peek(LIST*);
int length(LIST*);
void display(LIST*);
int main()
{
    LIST *l = (LIST*)malloc(sizeof(LIST));
    init(l);
    printf("Enter size of queue : ");
    scanf("%d", &(l->N));
    enqueue(l,3);
    enqueue(l,4);
    enqueue(l,5);
    display(l);
    dequeue(l);
    display(l);
    peek(l);
    //destroy(l);
}
void init(LIST *l)
{
    l->head = NULL;
    l->length = 0;
}
void enqueue (LIST *l, int data)
{
    NODE *node = (NODE*)malloc(sizeof(NODE));
    node->key = data;
    node->link = NULL;
    if (l->N==l->length)
    {
        printf("Queue Full!\n");
    }
    else if(l->head == NULL)
    {
        l->head = node;
        l->length+=1;
    }
    else
    {
        NODE *prev = NULL;
        NODE *pres = l->head;
        while(pres!=NULL)
        {
            prev = pres;
            pres = pres->link;
        }
        prev->link = node;
        l->length+=1;
    }
}
void display(LIST *l)
{
    NODE *node = l->head;
    while(node!=NULL)
    {
        printf("%d ", node->key);
        node = node->link;
    }
    printf("\n");
}
void dequeue(LIST *l)
{
    if(l->head == NULL)
    {
        printf("Queue Empty!");
    }
    else
    {
        l->head = l->head->link;
        l->length-=1;
    }
}
int peek(LIST *l)
{
    return l->head->key;
}