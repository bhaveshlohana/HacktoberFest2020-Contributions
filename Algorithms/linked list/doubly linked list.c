#include <stdlib.h>
#include <stdio.h>
struct node
{
	int key;
	struct node *prev;
	struct node *next;
};
typedef struct node NODE;
struct list
{
	NODE *head;
};
typedef struct list LIST;
void init(LIST*);
void read(LIST*);
void display(LIST*);
void delete_position(LIST*);
void destroy(LIST*);
int main()
{
	LIST *l = (LIST*)malloc(sizeof(LIST));
	init(l);
	for(int i = 1;i<=5;i++)
		read(l);
	display(l);
	delete_position(l);
	display(l);
	delete_position(l);
	display(l);
	delete_position(l);
	display(l);
	destroy(l);
}
void init(LIST *l)
{
	l->head=NULL;
}
void read(LIST *l)
{
	NODE *node = (NODE*)malloc(sizeof(NODE));
	printf("Enter value : ");
	scanf("%d", &(node->key));
	node->next = NULL;
	node->prev = NULL;
	if(l->head==NULL)
	{
		l->head = node;
	}
	else
	{
		NODE *pres1 = l->head;
		NODE *prev1 = NULL;
		while(pres1!=NULL)
		{
			prev1 = pres1;
			pres1 = pres1->next;
		}
		if(prev1==NULL)
		{
			node->next = l->head;
			l->head->prev = node;
			l->head = node;
		}
		else if(pres1==NULL)
		{
			prev1->next = node;
			node->prev = prev1;
			node->next = NULL;
		}
		else
		{
			node->next = pres1;
			node->prev = prev1;
			prev1->next = node;
			pres1->prev = node;
		}
	}
}
void display(LIST *l)
{
	NODE *node = l->head;
	while(node!=NULL)
	{
		printf("%d ", node->key);
		node = node->next;
	}
	printf("\n");
}
void delete_position(LIST *l)
{
	int s;
	printf("Enter position : ");
	scanf("%d", &s);
	int ctr = 0;
	if(l->head==NULL);
	else
	{
		NODE *pres1 = l->head;
		NODE *prev1 = NULL;
		while(pres1!=NULL && ctr!=s)
		{
			prev1 = pres1;
			pres1 = pres1->next;
			ctr+=1;
		}
		if(prev1 == NULL)
		{
			l->head = l->head->next;
			l->head->prev = NULL;
		}
		else if (pres1->next==NULL)
		{
			pres1->prev->next = NULL;
		}
		else if (pres1==NULL && prev1 == NULL)
			l->head = NULL;
		else
		{
			prev1->next = pres1->next;
			pres1->next->prev = prev1;
		}
	}
}
void destroy(LIST *l)
{
	NODE *node = l->head;
	NODE*temp;
	while(node!=NULL)
	{
		temp = node;
		node = node->next;
		free(temp);
	}
}