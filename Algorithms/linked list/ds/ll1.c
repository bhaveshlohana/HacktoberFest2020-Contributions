#include <stdio.h>
#include<stdlib.h>
void create();
void insert(struct node* head,int value);
void delete();
void display();

struct node *getnode(int data);
struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;
int main(void) {
    int c;
    do{
        printf("MENU\n1.create\n2.insert\n3.delete\n4.display\n5.exit\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
                create();
                break;
            case 2:
                insert(int);
                break;
            case 3:
                delete();
                break;
            case 4:
                display();
                break;
            
        }
    }while(c!=5);
}    
struct node *getnode(int data)
{
        struct node *newnode;
        newnode=(struct node*) malloc(sizeof(struct node));
        newnode->data=data;
        newnode->next=NULL;
        return newnode;
}
void create()
{
    struct node*newnode,*tail;
    int n,ch;
    do{
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data : " );
        scanf("%d",&n);
        newnode->data=n;
        newnode->next=NULL;
        if (head==NULL)
        {
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        printf("Do you want to contiune press (Type 0)  : ");
        scanf("%d",&ch);
    }while(ch==1);

       
}
void delete()
{
     // write your code here
}

void insert(int x, List l, Position p)
{
    Position TmpCell;
    TmpCell = (struct Node*) malloc(sizeof(struct Node));
    if(TmpCell == NULL)
        printf("Memory out of space\n");
    else
    {
        TmpCell->e = x;
        TmpCell->next = p->next;
        p->next = TmpCell;
    }
}
void display()
{   int count=0;
        while (head != NULL)
    {
        printf("%d \t", head->data);
        head = head->next;
        count++;
    }
    printf("\nThere are %d numbers \n",count);
    printf("\n");
}


