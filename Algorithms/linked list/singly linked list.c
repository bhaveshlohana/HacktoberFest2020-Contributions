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
};
typedef struct list LIST;

void init(LIST*);
void read_priority(LIST*);
void insert_at_pos(LIST*);
void insert_at_head(LIST*);
void insert_at_tail(LIST*);
void delete_priority(LIST*);
void delete_at_pos(LIST*);
void delete_head(LIST*);
void delete_tail(LIST*);
void delete_first_occurence(LIST*);
void delete_last_occurence(LIST*);
void delete_all_occurence(LIST*);
void display(LIST*);
void display_recursive(NODE*);
void find(LIST*);
int count(LIST*);
void merge(LIST*, LIST*);
void merge_sorted(LIST*, LIST*);
void union_lists(LIST*,LIST*,LIST*);
void intersection(LIST*,LIST*,LIST*);
void reverse(LIST*);
void destroy(LIST*);

int main()
{
    LIST *l = (LIST*)malloc(sizeof(LIST));
    init(l);
    int n;
    printf("Enter number of nodes for list 1 : ");
    scanf("%d",&n);
    for (int i = 0;i<n;i++)
        read_priority(l);
    display(l);
    reverse(l);
    display(l);


    //insert_at_tail(l);
    //insert_at_pos(l);
    //insert_at_head(l);
    //insert_at_tail(l);
    //delete_priority(l);
    //delete_head(l);
    //delete_tail(l);
    //delete_at_pos(l);
    //delete_first_occurence(l);
    //delete_last_occurence(l);
    //delete_all_occurence(l);
    //printf("Number of nodes = %d\n", count(l));
    //find(l);
    //display_recursive(l->head);


    #if 0
    LIST *l2 = (LIST*)malloc(sizeof(LIST));
    init(l2);
    printf("Enter number of nodes for list 2 : ");
    scanf("%d",&n);
    for (int i = 0;i<n;i++)
        read_priority(l2);
    display(l2);
    #endif

    #if 0
    LIST *l3 = (LIST*)malloc(sizeof(LIST));
    LIST *l4 = (LIST*)malloc(sizeof(LIST));
    init(l3);
    init(l4);
    union_lists(l,l2,l3);
    intersection(l,l2,l4);
    display(l3);
    display(l4);
    #endif

    destroy(l);
}
void init(LIST* l)
{
    l->head = NULL;
}
void read_priority(LIST* l)
{
    NODE* node = (NODE*)malloc(sizeof(NODE));
    node->link = NULL;
    printf("Enter value : ");
    scanf("%d", &(node->key));
    if (l->head == NULL)
    {
        l->head = node;
    }
    else
    {
        NODE *prev = NULL;
        NODE *pres = l->head;
        while (pres!=NULL  && pres->key<node->key)
        {
            prev = pres;
            pres = pres->link;
        }
        if (prev==NULL)
        {
            node->link = l->head;
            l->head = node;
        }
        else
        {
            prev->link = node;
            node->link = pres; 
        }
    } 
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
void display_recursive(NODE *node)
{
    if(node!=NULL)
    {
        printf("%d ",node->key);
        display_recursive(node->link);
    }
}
void insert_at_pos(LIST* l)
{
    //printf("Inserting at position\n");
    NODE* node = (NODE*)malloc(sizeof(NODE));
    node->link = NULL;
    printf("Enter value : ");
    scanf("%d", &(node->key));
    printf("Enter a position : ");
    int pos;
    scanf("%d", &pos);
    if(l->head==NULL)
    {
        l->head = node;
    }
    else
    {
        NODE *prev = NULL;
        NODE *pres = l->head;
        int ctr = 0;
        while(pres!=NULL && ctr<pos)
        {
            prev = pres;
            pres = pres->link;
            ctr++;
        }
        if (prev == NULL)
        {
            node->link = l->head;
            l->head = node;
        }
        else
        {
            prev->link = node;
            node->link = pres;
        }
    }
}
void insert_at_head(LIST* l)
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
void insert_at_tail(LIST *l)
{
    //printf("Inserting at tail\n");
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
        node->link = pres; //pres is null
    }
}
void delete_priority(LIST *l)
{
    if(l->head != NULL)
    {
        NODE* prev = NULL;
        NODE* pres = l->head;
        NODE* max = NULL;
        int mval = l->head->key;
        while(pres!=NULL)
        {
            if(pres->key>mval)
            {
                max = prev;
                mval = pres->key;
            }
            prev = pres;
            pres = pres->link;
        }
        if (max == NULL)
        {
            NODE *temp = l->head;
            l->head = l->head->link;
            free(temp);
        }
        else
        {
            NODE* temp = max->link;
            max->link = max->link->link;
            free(temp); 
        }
        
    }
}
void delete_at_pos(LIST* l)
{
    int pos;
    printf("Enter position to delete at : ");
    scanf("%d", &pos);
    if(l->head!=NULL)
    {
        NODE* prev = NULL;
        NODE* pres = l->head;
        int ctr = 0;
        while(pres!=NULL && ctr<pos)
        {
            prev = pres;
            pres = pres->link;
            ctr++;
        }
        if (prev==NULL)
        {
            l->head = pres->link;
            free(pres);
        }
        else
        {
            prev->link = pres->link;
            free(pres);
        }
    }
}
void delete_tail(LIST *l)
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
}
void delete_head(LIST *l)
{
    if(l->head != NULL)
    {
        NODE *temp = l->head;
        l->head = l->head->link;
        free(temp);
    }  
}
void delete_first_occurence(LIST *l)
{
    if (l->head != NULL)
    {
        printf("Enter element to delete : ");
        int val;
        scanf("%d", &val);
        NODE* prev = NULL;
        NODE* pres = l->head;
        while(pres!=NULL)
        {
            if (pres->key == val)
            {
                if (prev == NULL)
                {
                    NODE *temp = l->head;
                    l->head = l->head->link;
                    free(temp);
                }
                else
                {
                    prev->link = pres->link;
                    free(pres);
                }
                break;
            }
            prev = pres;
            pres = pres->link;
        }
    }
}
void delete_last_occurence(LIST *l)
{
    if(l->head!=NULL)
    {
        int pos = 0, ctr = 0;
        printf("Enter element to delete : ");
        int val;
        scanf("%d", &val);
        NODE* prev = NULL;
        NODE* pres = l->head;
        while(pres!=NULL)
        {
            if(pres->key == val)
                pos = ctr;
            prev = pres;
            pres = pres->link;
            ctr+=1;
        }
        prev = NULL;
        pres = l->head;
        ctr = 0;
        while(pres!=NULL && ctr<pos)
        {
            prev = pres;
            pres = pres->link;
            ctr++;
        }
        if (prev==NULL)
        {
            l->head = pres->link;
            free(pres);
        }
        else
        {
            prev->link = pres->link;
            free(pres);
        }
    }
}
void delete_all_occurence(LIST *l)
{
    if(l->head != NULL)
    {
        printf("Enter element to delete : ");
        int val;
        scanf("%d", &val);
        NODE* prev = NULL;
        NODE* pres = l->head;
        while(pres!=NULL)
        {
            if(pres->key == val)
            {
                if(prev==NULL)
			    {
				    pres=pres->link;
				    l->head = pres;
			    }
			    else
			    {
				    pres = pres->link;
				    prev->link = pres;
			    }
		    }
		    else
		    {
			    prev = pres;
			    pres = pres->link;
		    }
        }
    }
}
int count(LIST *l)
{
    int ctr = 0;
    if (l->head == NULL)
        return 0;
    else
    {
        NODE *node = l->head;
        while (node!=NULL)
        {
            ctr++;
            node = node->link;
        }
        return ctr;
    }
}
void destroy(LIST *l)
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
void find(LIST *l)
{
    printf("Enter element to find : ");
    int s;
    scanf("%d", &s);
    int pos = -1;
    if(l->head == NULL)
        printf("Index = %d\n", pos);
    else
    {
        int ctr = 0;
        NODE* prev = NULL;
        NODE* pres = l->head;
        while(pres!=NULL)
        {
            if(s==pres->key)
                pos = ctr;
            prev = pres;
            pres = pres->link;
            ctr++;
        }
        printf("Index = %d\n", pos);
    }
}
void merge(LIST *l1, LIST *l2)
{
    if(l1->head==NULL)
	{
		if(l2->head!=NULL)
		{
			l1->head=l2->head;
			l2->head=NULL;
		}
	}
	else
	{
		NODE *prev = NULL;
		NODE *pres = l1->head;
		while(pres!=NULL)
		{
			prev = pres;
			pres=pres->link;
		}
		prev->link = l2->head;
		l2->head=NULL;
	}
}
void merge_sorted(LIST *l1, LIST *l2)
{
    if (l1->head!=NULL && l2->head!=NULL)
	{
		NODE *prev = NULL;
		NODE *pres = l2->head;
		NODE *temp1 = NULL;
		NODE *temp2 = l1->head;
		while(pres!=NULL)
		{
			NODE *node = (NODE*)malloc(sizeof(NODE));
			node->key = pres->key;
			node->link = NULL;
			temp1 = NULL;
			temp2 = l1->head;
			while(temp2!=NULL && temp2->key<=node->key)
			{
				temp1 = temp2;
				temp2=temp2->link;
			}
			if (temp1==NULL)
			{
				node->link = l1->head;
				l1->head = node;
			}
			else
			{
				temp1->link = node;
				node->link = temp2;
			}
			pres = pres->link;
		}
	}
}
void insert(LIST *l, int val)
{
    NODE* node = (NODE*)malloc(sizeof(NODE));
    node->link = NULL;
    node->key = val;
    if (l->head == NULL)
    {
        l->head = node;
    }
    else
    {
        NODE *prev = NULL;
        NODE *pres = l->head;
        while (pres!=NULL  && pres->key<node->key)
        {
            prev = pres;
            pres = pres->link;
        }
        if (prev==NULL)
        {
            node->link = l->head;
            l->head = node;
        }
        else
        {
            prev->link = node;
            node->link = pres;
        }
    } 
}
void check(LIST *l1,LIST *l3)
{
    NODE *pres1 = l1->head;
    while(pres1!=NULL)
    {
        NODE *pres2 = l3->head;
        int ctr = 0;
        while(pres2!=NULL)
        {
            if (pres1->key==pres2->key)
                ctr++;
            pres2 = pres2->link;
        }
        if (ctr==0)
        {
            insert(l3,pres1->key);
        }
        pres1 = pres1->link;
    }
}
void union_lists(LIST* l1, LIST *l2, LIST *l3)
{
    check(l1,l3);
    check(l2,l3);
}
void intersection(LIST *l1, LIST *l2, LIST *l3)
{
    NODE *node1 = l1->head;
    int flag;
    while(node1!=NULL)
    {
        flag = 0;
        NODE *node2 = l2->head;
        while(node2!=NULL)
        {
            if (node2->key==node1->key)
            {
                flag = 1;
                break;
            }
            node2 = node2->link;
        }
        if (flag==1)
        {
            insert(l3,node1->key);
        }
        node1=node1->link;
    }
}
void reverse(LIST *l)
{
    NODE *pres = l->head;
    NODE *prev = NULL;
    NODE *temp = NULL;
    while(pres!=NULL)
    {
        temp = pres->link;
        pres->link = prev;
        prev = pres;
        pres = temp;
    }
    l->head = prev;
}