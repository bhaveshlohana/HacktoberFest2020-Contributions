#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>


void reverse();
void create();
int choice,i,item;
struct node {
int data;
struct node *link;
}*front,*rear,*new,*postptr,*preptr,*ptr;

int main() {
	front=rear=NULL;
	printf("\n select menu\n");
	while(1) {
		printf("\n1.Create \n2.Reverse\n3.Exit");
		printf("\nEnter ur choice: ");
		scanf("%d",&choice);
		switch(choice) {
			case 1: create();
					break;
			case 2: reverse();
					break;
			case 3: exit(0);
			default: printf("\nWrong choice.");
		}/*end of switch*/
	}/*end of while*/
	return 0;
}/*end of main*/

void create(){
	new=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter the item: ");
	scanf("%d",&item);
	new->data = item;
	if(front==NULL){
		front = new;
		}/*end of if*/
	else rear->link = new;
		rear = new;
		rear->link = front;
	printf("\nIf you want to enter more elements , press 1. Pressing anything else will be treated as you dont want to enter any more elements");
	scanf("%d",&item);
	if(item == 1) create();
	else return ;
	}/*end of create fn*/
	
void reverse(){
	
	int length=1;
	ptr = front->link;
	while(ptr->link!=front) length++;
	
	ptr = front;
	preptr = rear;
	for(i=0;i<length;i++){
	postptr = ptr->link;
	ptr->link = preptr;
	preptr = ptr;
	ptr = postptr;
		}/*End of loop*/
	ptr = front;
	front = rear;
	rear = ptr;
	}/*End of reverse fn*/
