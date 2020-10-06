/*QUEUE USING ARRAY*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int q[MAX];
int front=-1;
int rear=-1;

void enqueue(int item)
{
	if(rear==MAX-1)
		printf("OVERFLOW\n");
	else
	{
		rear=rear+1;
		q[rear]=item;
		if(front==-1)
			front=0;
	}
}

void dequeue()
{
	if(front==-1)
		printf("QUEUE IS EMPTY\n");
	else
	{
		if(front==rear)
			front=rear=-1;
		else
			front+=1;
	}
}

void display()
{
	for(int i=front;i<=rear;i++)
		printf("%d\t",q[i]);
	printf("\n");
}

void main()
{
	int c,i,item;
	while(1)
	{
		printf("1.ENTER QUEUE\t2.DELETE QUEUE\t3.DISPLAY\t4.EXIT\n");
		printf("ENTER YOUR CHOICE:\t");
		scanf("%d",&c);
		switch(c)
		{
			case 1 : printf("ENTER THE ELEMENT:\t");
				 scanf("%d",&item);
				 enqueue(item);printf("\n");break;
			case 2 : dequeue();printf("\n");break;
			case 3 : display();printf("\n");break;
			case 4 :exit(0);break;
			default :printf("\nINVALID CHOICE\n");
		}
	}
}

/*OUTPUT

    1.ENTER QUEUE	2.DELETE QUEUE	3.DISPLAY	4.EXIT
    ENTER YOUR CHOICE:	1
    ENTER THE ELEMENT:	1

    1.ENTER QUEUE	2.DELETE QUEUE	3.DISPLAY	4.EXIT
    ENTER YOUR CHOICE:	1
    ENTER THE ELEMENT:	2

    1.ENTER QUEUE	2.DELETE QUEUE	3.DISPLAY	4.EXIT
    ENTER YOUR CHOICE:	1
    ENTER THE ELEMENT:	3

    1.ENTER QUEUE	2.DELETE QUEUE	3.DISPLAY	4.EXIT
    ENTER YOUR CHOICE:	1
    ENTER THE ELEMENT:	4

    1.ENTER QUEUE	2.DELETE QUEUE	3.DISPLAY	4.EXIT
    ENTER YOUR CHOICE:	3
    1	2	3	4	

    1.ENTER QUEUE	2.DELETE QUEUE	3.DISPLAY	4.EXIT
    ENTER YOUR CHOICE:	2

    1.ENTER QUEUE	2.DELETE QUEUE	3.DISPLAY	4.EXIT
    ENTER YOUR CHOICE:	3
    2	3	4	

    1.ENTER QUEUE	2.DELETE QUEUE	3.DISPLAY	4.EXIT
    ENTER YOUR CHOICE:	2

    1.ENTER QUEUE	2.DELETE QUEUE	3.DISPLAY	4.EXIT
    ENTER YOUR CHOICE:	3
    3	4	

    1.ENTER QUEUE	2.DELETE QUEUE	3.DISPLAY	4.EXIT
    ENTER YOUR CHOICE:	4
*/