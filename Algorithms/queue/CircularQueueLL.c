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
    int top;
};
typedef struct list LIST;
void init(LIST*);
void read(LIST*);
void display(LIST*);
void delete(LIST*);
int peek(LIST*);
void destroy(LIST*);
int main()
{
	LIST *l = (LIST*)malloc(sizeof(LIST));
	init(l);
	for(int i = 1;i<=5;i++)
		read(l);
	display(l);
    delete(l);
    display(l);
    read(l);
    read(l);
    display(l);
    delete(l);
    delete(l);
    delete(l);
    display(l);
    //destroy(l);
}
void init(LIST *l)
{
    l->head = NULL;
    l->top = -1;
}
void read(LIST *l)
{
    printf("Enter element : ");
    NODE *node = (NODE*)malloc(sizeof(NODE));
    scanf("%d", &(node->key));
    node->link = NULL;
    NODE *pres = l->head;
    if(l->head==NULL)
    {
        l->head = node;
        node->link = node;
    }
    else
    {
        while(pres->link!=l->head)
        {
            pres = pres->link;
        }
        pres->link = node;
        node->link = l->head;
        l->head = node;
    }
}
void delete(LIST *l)
{
    if(l->head==NULL);
    else
    {
        NODE *pres = l->head;
        while(pres->link!=l->head)
        {
            pres = pres->link;
        }
        pres->link = pres->link->link;
        l->head = pres->link;
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
int peek(LIST *l)
{
    return l->head->key;
}