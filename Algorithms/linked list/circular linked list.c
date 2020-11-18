#include <stdio.h>
#include <stdlib.h>
struct node
{
	int key;
	struct node *link;
};
typedef struct node NODE;
struct list
{
	NODE *head;
};
typedef struct list LIST;
void insert_head(LIST*);
void insert_tail(LIST*);
void insert(LIST*); //NOT WORKING
void display(LIST*);
void delete_position(LIST*);
void delete_tail(LIST*);
void delete_head(LIST*);
void destroy(LIST*);
int main()
{
	LIST *l = (LIST*)malloc(sizeof(LIST));
	l->head = NULL;
	for(int i = 1;i<=5;i++)
		insert_head(l);
	display(l);
    delete_tail(l);
    delete_tail(l);
    delete_tail(l);
    display(l);

}
void insert_tail(LIST *l)
{
    NODE *node = (NODE*)malloc(sizeof(NODE));
    printf("Enter value : ");
    scanf("%d", &(node->key));
    if(l->head==NULL)
    {
        l->head = node;
        node->link = node;
    }
    else
    {
        NODE *pres = l->head;
        NODE *prev;
        while(pres->link!=l->head)
        {
            prev = pres;
            pres = pres->link;
        }
        pres->link = node;
        node->link = l->head;
    }
}
void insert(LIST *l)
{
    NODE *node = (NODE*)malloc(sizeof(NODE));
    printf("Enter value : ");
    scanf("%d", &(node->key));
    if(l->head==NULL)
    {
        l->head = node;
        node->link = node;
    }
    else
    {
        NODE *pres = l->head;
        NODE *prev = NULL;
        while(pres->link!=l->head && pres->key<node->key)
        {
            prev = pres;
            pres = pres->link;
        }
        if(prev==NULL)
        {
            l->head->link = node;
            node->link = l->head;
        }
        else if(pres==l->head)
        {
            prev->link = node;
            node->link = l->head;
        }
        else
        {
            prev->link = node;
            node->link = l->head;
        }

    }
}
void insert_head(LIST *l)
{
    NODE *node = (NODE*)malloc(sizeof(NODE));
    printf("Enter value : ");
    scanf("%d", &(node->key));
    if(l->head==NULL)
    {
        l->head = node;
        node->link = node;
    }
    else
    {
        NODE *pres = l->head;
        NODE *prev;
        while(pres->link!=l->head)
        {
            prev = pres;
            pres = pres->link;
        }
        pres->link = node;
        node->link = l->head;
        l->head = node;
    }
}
void display(LIST *l)
{
    NODE *node = l->head;
	while(node->link!=l->head)
	{
		printf("%d ", node->key);
		node = node->link;
	}
	printf("%d\n",node->key);
}
void destroy(LIST *l)
{
	NODE *node = l->head;
	NODE*temp;
	while(node->link!=l->head)
	{
		temp = node;
		node = node->link;
		free(temp);
	}
}
void delete_head(LIST *l)
{
    if(l->head->link==l->head)
    {
        l->head = NULL;
        return;
    }
    NODE *pres = l->head;
    NODE *prev = NULL;
    while(pres->link!=l->head)
    {
        prev = pres;
        pres = pres->link;
    }
    pres->link = pres->link->link;
    l->head = pres->link;
}
void delete_tail(LIST *l)
{
    if(l->head->link==l->head)
    {
        l->head = NULL;
        return;
    }
    NODE *pres = l->head;
    NODE *prev = NULL;
    while(pres->link!=l->head)
    {
        prev = pres;
        pres = pres->link;
    }
    prev->link = l->head;
}