#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

void createPoly();
void peval();
int power(int ,int);
struct polynode
{
int coef;
int exp;
struct polynode *next;
}*ptr,*a,*start;
typedef struct polynode *polyptr;
int x,expo,coeff,value=0;

int main()
{
	int choice;
	start = NULL;
	printf("\n Select menu\n");
	while(1) {
		printf("\n1.Create Polynomial \n2.Evaluate Polynomial\n3.Exit");
		printf("\nEnter ur choice: ");
		scanf("%d",&choice);
		switch(choice) {
			case 1: createPoly();
					break;
			case 2: peval();
					break;
			case 3: exit(0);
			default: printf("\nWrong choice.");
		}/*end of switch*/
	}/*end of while*/
	return 0;
}/*end of main*/

void createPoly()
{
	polyptr p,tmp,start=NULL;
	int ch=1;
	while(ch)
	{
		p=(polyptr)malloc(sizeof(struct polynode));
		printf("\nEnter the coefficient :");
		fflush(stdin);
		scanf("%d",&p->coef);
		printf("\nEnter the exponent : ");
		fflush(stdin);
		scanf("%d",&p->exp);
		p->next=NULL;
		//IF the polynomial is empty then add this node as the start node of the polynomial
		if(start==NULL) start=p;
		//else add this node as the last term in the polynomial lsit
		else
			{
				tmp=start;
				while(tmp->next!=NULL)
					tmp=tmp->next;
				tmp->next=p;
			}
		printf("If more Nodes are to be added then enter 1");
		scanf("%d",&ch);
	}
	return;
}			

void peval(){
	printf("\nEnter the value at which the polyomial is evaluated.");
	scanf("%d",&x);
	a = start;
	ptr = a;
	while(ptr!=NULL){
		coeff = ptr->coef;
		expo = ptr->exp;
		value = coeff*power(x,expo);
		ptr = ptr->next;
		}
	printf("\nThe value of the polynomial at %d is %d",x,value);
}

int power(int x,int expo){
	int t=x;
	for(int i=0;i<expo;i++) t=x*t;
	return t;
}
