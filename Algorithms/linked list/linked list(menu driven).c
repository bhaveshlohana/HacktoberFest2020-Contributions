#include<stdio.h>
#include<stdlib.h>

struct node{
	int info;
	struct node *next;
};

void createList(struct node *ptr)
{
	char ch;
	int i=1;
	printf("\nEnter the value of %d node: ",i);
	scanf("%d",&ptr->info);
	ptr->next = NULL;
	i++;
	printf("\nPress 'n' to quit, anyother key to continue: ");
	ch = getchar();
	ch = getchar();
	while(ch!='n')
	{
		ptr->next = (struct node *)malloc(sizeof(struct node));
		if(ptr->next==NULL)
		{
			printf("\nOut of memory Space");
			exit(0);
		}
		ptr = ptr->next;
		printf("\nEnter the value of %d node: ",i);
		scanf("%d",&ptr->info);
		ptr->next = NULL;
		i++;
		printf("\nPress 'n' to quit, anyother key to continue: ");
		ch = getchar();
		ch = getchar();
	}
}

void display(struct node *start)
{
	struct node *curr;
	curr = start;
	printf("\nValues in the list: ");
	while(curr!=NULL) {
		printf("\t%d",curr->info);
		curr = curr->next;
	}
	printf("\n");
}

void insert(struct node *start)
{
	struct node *nnode;
	nnode = (struct node *)malloc(sizeof(struct node));
	if(nnode==NULL)
	{
		printf("Out of memory space");
		exit(0);
	}
	nnode->next = start;
	printf("\nInput the new node value: ");
	scanf("%d", &nnode->info);
	start = nnode;
	display(start);
}

void insertend(struct node *start)
{
	struct node *enode, *tmp;
    enode = (struct node*)malloc(sizeof(struct node));
    if(enode == NULL)
    {
        printf("Out of memory space");
		exit(0);
    }
    printf("\nInput the new node value: ");
	scanf("%d", &enode->info);
    enode->next = NULL;
    tmp = start;
    while(tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = enode;
    display(start);
}

void inserta(struct node *start)
{
	struct node *nnode, *curr;
	nnode = (struct node*)malloc(sizeof(struct node));
	if(nnode == NULL)
    {
        printf("Out of memory space");
		exit(0);
    }
    printf("\nInput the new node value: ");
	scanf("%d", &nnode->info);
	nnode->next = NULL;
	int loc;
	printf("\nEnter location: ");
	scanf("%d", &loc);
	loc = loc-1;
	if(loc == 0)
	{
		insert(start);
	}
	curr = start;
	int i =1;
	while(i<loc && curr != NULL)
	{
		curr = curr->next;
		i = i+1;
	}
	if(curr == NULL)
	{
		printf("\nLocation not found");
		exit(0);
	}
	nnode->next = curr->next;
	curr->next = nnode;
	display(start);
}

void firstdelete(struct node *start)
{
	struct node *temp;
	temp = start;
	if(start == NULL) {
		printf("Underflow");
		exit(0);
	}
	start = start->next;
	free(temp);
	display(start);
}

void lastdelete(struct node *start)
{
	struct node *curr,*prev;
	curr = start;
	if(curr->next == NULL)
	{
		free(curr);
		start=NULL;
		return;
	}
	while(curr->next != NULL)
	{
		prev = curr;
		curr = curr->next;
	}
	prev->next = NULL;
	free(curr);
	display(start);
}

void delete(struct node *start)
{
	struct node *curr,*prev;
	curr = start;
	int loc;
	printf("\nEnter location: ");
	scanf("%d", &loc);
	int i=1;
	while(i<loc && curr != NULL)
	{
		prev = curr;
		curr = curr->next;
		i = i+1;
	}
	if(curr == NULL)
	{
		printf("\nLocation not found");
		exit(0);
	}
	prev->next = curr -> next;
	free(curr);
	display(start);
}

void length(struct node *start)
{
	int length=0;
	struct node *curr;
	curr = start;
	if(curr == NULL)
	{
		printf("\nUnderflow");
		exit(0);
	}
	while(curr->next!=NULL)
	{
		length++;
		curr = curr->next;
	}
	printf("\nLength: %d", length+1);
}

void findValue(struct node *start)
{
	struct node *curr;
	curr = start;
	if(curr == NULL)
	{
		printf("\nUnderflow");
		exit(0);
	}
	int v,i=0,k=0;
	printf("\nEnter value: ");
	scanf("%d", &v);
	while(curr->next!=NULL)
	{
		if(curr->info == v)
		{
			printf("\n%d at node %d", v,i);
			i++;
			curr = curr->next;
			k=1;
			break;
		}
	}
	if(curr->next == NULL)
	{
		if(curr->info == v)
		{
			printf("\n%d at node %d", v,i);
			k=1;
		}
	}
	if(k==0)
	{
		printf("\n%d is not in our linked list",v);
	}
}

func(struct node* start){
	if(start==NULL)
		return;
	func(start->next);
	printf("%d", start->info);
	func(start->next);
}

void main()
{
	struct node *ptr;
	ptr = (struct node *)malloc(sizeof(struct node));
	if(ptr==NULL)
	{
		printf("\nOut of memory Space");
		exit(0);
	}
	int l;
	while(l!=11)
	{
		printf("\nPress:\n1: creation\t2: display\n3: insertion at beginning\t4: insertion at end\t5: insert anywhere\n6: Deletion at first node\t7: Deletion at end\t8: Deletion\n9:Find Length\n10:Find Node of the given value\n11: End\n");
		printf("\nEnter: ");
		scanf("%d",&l);
		switch (l)
		{
			case 1: {
				createList(ptr);
				break;
			}
			case 2: {
				display(ptr);
				break;
			}
			case 3: {
				func(ptr);
				break;
			}
			case 4: {
				insertend(ptr);
				break;
			}
			case 5: {
				inserta(ptr);
				break;
			}
			case 6: {
				firstdelete(ptr);
				break;
			}
			case 7: {
				lastdelete(ptr);
				break;
			}
			case 8: {
				delete(ptr);
				break;
			}
			case 9: {
				length(ptr);
				break;
			}
			case 10: {
				findValue(ptr);
				break;
			}
			case 11: {
				printf("Thank you\n");
				break;
			}
		}	
	}
}
