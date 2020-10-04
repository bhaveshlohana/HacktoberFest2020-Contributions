#include <stdio.h>
#include <stdlib.h>
struct node
{
    int key;
    struct node* link;
};
typedef struct node NODE;
struct list
{
    NODE *head;
    int top,n;
};
typedef struct list LIST;
void init(LIST*);
void insert_at_head(LIST*);
void insert_at_tail(LIST*);
void delete_head(LIST*);
void delete_tail(LIST*);
void display(LIST*);
void destroy(LIST*);
int main()
{
    LIST *l = (LIST*)malloc(sizeof(LIST));
    init(l);
    printf("Enter number of nodes : ");
    scanf("%d", &(l->n));
    insert_at_head(l);
    insert_at_head(l);
    insert_at_head(l);
    display(l);
    insert_at_tail(l);
    insert_at_tail(l);
    insert_at_tail(l);
    display(l);
    delete_head(l);
    delete_tail(l);
    display(l);
}
void init(LIST*l)
{
    l->head = NULL;
    l->top = -1;
}
void display(LIST* l)
{
    NODE* node = l->head;
    while(node!=NULL)
    {
        printf("%d ",node->key);
        node = node->link;
    }
    printf("\n");
}
void insert_at_head(LIST* l)
{
    if(l->top!=(l->n)-1)
    {
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
        l->top+=1;
    }
    else
    {
        printf("QUEUE FULL\n");
    }
}
void insert_at_tail(LIST *l)
{
    if(l->top!=(l->n)-1)
    {
        NODE *node = (NODE*)malloc(sizeof(NODE));
        node->link = NULL;
        printf("Enter value : ");
        scanf("%d", &(node->key));
        if(l->head == NULL)
            l->head = node;
        else
        {
            NODE *prev = NULL;
            NODE *pres = l->head;
            while (pres!=NULL)
            {
                prev = pres;
                pres = pres->link;
            }
            prev->link = node;
            node->link = pres;
        }
        l->top+=1;
    }
    else
    {
        printf("QUEUE FULL\n");
    }
}
void delete_head(LIST *l)
{
    if(l->top != -1)
    {
        NODE *temp = l->head;
        l->head = l->head->link;
        free(temp);
        l->top-=1;
    }  
    else
    {
        printf("QUEUE EMPTY\n");
    }
    
}
void delete_tail(LIST *l)
{
    if(l->top==-1)
        printf("QUEUE EMPTY\n");
    else
    {
        NODE *prev = NULL;
        NODE *pres = l->head;
        if (pres == NULL)
            printf("EMPTY\n");
        else
        {
            while (pres->link!=NULL)
            {
                prev = pres;
                pres = pres->link;
            }
            if(prev==NULL)
                l->head = NULL;
            else
                prev->link = NULL;
            free(pres);
        }
        l->top-=1;
    }
    
}