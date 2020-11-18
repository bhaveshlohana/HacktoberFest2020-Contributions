#include <stdio.h>
#include <stdlib.h>
struct node
{
    int key;
    struct node* link;
};
typedef struct node NODE;
struct stack
{
    NODE *head;
};
typedef struct stack STACK;
void init(STACK*);
void read(STACK*);
void display(STACK*);
void delete(STACK*);
void destroy(STACK*);
int peek(STACK*);
int main()
{
    STACK *l = (STACK*)malloc(sizeof(STACK));
    init(l);
    int n;
    printf("Enter number of nodes : ");
    scanf("%d",&n);
    for (int i = 0;i<n;i++)
        read(l);
    display(l);
    delete(l);
    display(l);
    printf("%d\n",peek(l));
    display(l);
    destroy(l);
}
void init(STACK* l)
{
    l->head = NULL;
}
void read(STACK* l)
{
    //printf("Inserting at head\n");
    NODE *node = (NODE*)malloc(sizeof(NODE));
    node->link = NULL;
    printf("Enter value : ");
    scanf("%d", &(node->key));
    if(l->head == NULL)
        l->head = node;
    else
    {
        node->link = l->head;
        l->head = node;
    }
}
void delete(STACK *l)
{
    if(l->head != NULL)
    {
        NODE *temp = l->head;
        l->head = l->head->link;
        free(temp);
    }  
}
void display(STACK* l)
{
    NODE* node = l->head;
    while(node!=NULL)
    {
        printf("%d ",node->key);
        node = node->link;
    }
    printf("\n");
}
void destroy(STACK *l)
{
    NODE *prev = NULL;
    NODE *pres = l->head;
    while(pres!=NULL)
    {
        prev = pres;
        pres = pres->link;
        free(prev);
    }
}
int peek(STACK *l)
{
    return l->head->key;
}