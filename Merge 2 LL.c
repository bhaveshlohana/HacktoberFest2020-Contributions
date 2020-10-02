#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

void create_nodeX(int);
void create_nodeY(int);
void merge_lists(int,int);
struct node {
int data;
struct node *link;
}*front,*rear,*frontx,*rearx,*fronty,*reary,*new,*ptrx,*ptry,*temp,*tempx,*tempy;

int main()
{
	frontx = fronty = rearx = reary = NULL;
	int n,m;
	printf("\nEnter the number of nodes in Linked List in X");
	scanf("%d",&n);
	for(int i=1;i<=n;i++) create_nodeX(i);
	rearx->link = frontx;
	printf("\nEnter the number of nodes in Linked List in Y");
	scanf("%d",&m);
	for(int i=1;i<=m;i++) create_nodeY(i);
	reary->link = fronty;
	merge_lists(n,m);
	return 0;
}

void create_nodeX(int i){
	int element;
	new = (struct node*)malloc(sizeof(struct node));
	printf("\nEnter x(%d)",i);
	fflush(stdin);
	scanf("%d",&element);
	if(frontx == NULL){
		new->data = element;
		new->link = NULL;
	}
	else {
		while(ptrx->link!=NULL)
			ptrx = ptrx->link;
		new->data = element;
		new->link = NULL;
		ptrx->link = new;
		rearx = new;
		}
	return;
}

void create_nodeY(int i){
	int element;
	new = (struct node*)malloc(sizeof(struct node));
	printf("\nEnter Y(%d)",i);
	scanf("%d",&element);
	if(fronty == NULL){
		new->data = element;
		new->link = NULL;
	}
	else {
		while(ptry->link!=NULL)
			ptry = ptry->link;
		new->data = element;
		new->link = NULL;
		ptry->link = new;
		reary = new;
		}
	return;
}

void merge_lists(int n,int m){
	front = frontx;
	ptrx = frontx;
	ptry = fronty;
	while((ptrx->link!=frontx)&&(ptry!=fronty)){
		tempx = ptrx->link;
		ptrx->link = ptry;
		tempy = ptry->link;
		ptry->link = tempx;
		ptrx = tempx;
		ptry =tempy; 
		}
	if(m>n){
		ptrx->link = ptry;
		rear = reary;
		}
	else if(n>m){
		tempx = ptrx->link;
		ptrx->link = ptry;
		ptry->link = tempx;
		rear = rearx;
		}
	else {
		ptrx->link = ptry;
		rear = reary;
	}
	return;
	}
