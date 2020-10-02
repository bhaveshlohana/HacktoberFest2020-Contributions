#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*head=NULL,*q,*t;
 
void Create()
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
 
void insert_beg()
{
    int num;
    t=(struct node*)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d",&num);
    t->data=num;
 
    if(head==NULL)
	{
        t->next=NULL;
        head=t;
    }//If list is empty
    else
    {
        t->next=head;
        head=t;
    }
}
 
void insert_end()
{
    int num;
    t=(struct node*)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d",&num);
    t->data=num;
    t->next=NULL;
 
    if(head==NULL)        
    {
        head=t;
    }
    else
    {
        q=head;
        while(q->next!=NULL)
        q=q->next;
        q->next=t;
    }
}
 
int insert_pos()
{
    int pos,i,num;
    if(head==NULL)
    {
        printf("List is empty!!");
        return 0;
    }
 
    t=(struct node*)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d",&num);
    printf("Enter position to insert:");
    scanf("%d",&pos);
    t->data=num;
 
    q=head;
    for(i=1;i<pos-1;i++)
    {
        if(q->next==NULL)
        {
            printf("There are less elements!!");
            return 0;
        }
 
        q=q->next;
    }
 
    t->next=q->next;
    q->next=t;
    return 0;
}
 
void display()
{
    if(head==NULL)
    {
        printf("List is empty!!");
    }
    else
    {
        q=head;
        printf("The linked list is:\n");
        while(q!=NULL)
        {
            printf("%d->",q->data);
            q=q->next;
        }
    }
}
 
void delete_beg()
{
    if(head==NULL)
    {
        printf("The list is empty!!");
    }
    else
    {
        q=head;
        head=head->next;
        printf("Deleted element is %d",q->data);
        free(q);
    }
}
 
void delete_end()
{
    if(head==NULL)
    {
        printf("The list is empty!!");
    }
    else
    {
        q=head;
        while(q->next->next!=NULL)
        q=q->next;
 
        t=q->next;
        q->next=NULL;
        printf("Deleted element is %d",t->data);
        free(t);
    }
}
 
int delete_pos()
{
    int pos,i;
 
    if(head==NULL)
    {
        printf("List is empty!!");
        return 0;
    }
 
    printf("Enter position to delete:");
    scanf("%d",&pos);
 
    q=head;
    for(i=1;i<pos-1;i++)
    {
        if(q->next==NULL)
        {
            printf("There are less elements!!");
            return 0;
        }
        q=q->next;
    }
 
    t=q->next;
    q->next=t->next;
    printf("Deleted element is %d",t->data);
    free(t);
 
    return 0;
}


 
int main()
{

    while(1)
    {
        printf("\n\n---- Singly Linked List(SLL) Menu ----");
        printf("MENU\n1.Create\n2.Insert\n3.Delete\n4.Display\n5.Exit\n");
        printf("Enter your choice(1-5):");
        scanf("%d",&ch);
 
        switch(ch)
        {
			case 1:
                Create();
                break;
            case 2:
                    printf("\n---- Insert Menu ----");
                    printf("\n1.Insert at beginning\n2.Insert at end\n3.Insert at specified position\n4.Exit");
                    printf("\n\nEnter your choice(1-4):");
                    scanf("%d",&ch);
 
                    switch(ch)
                    {
                        case 1: insert_begin();
                                break;
                        case 2: insert_end();
                                break;
                        case 3: insert_pos();
                                break;
                        case 4: exit(0);
                        default: printf("Wrong Choice!!");
                    }
                    break;
 
            
 
            case 3: printf("\n---- Delete Menu ----");
                    printf("\n1.Delete from beginning\n2.Delete from end\n3.Delete from specified position\n4.Exit");
                    printf("\n\nEnter your choice(1-4):");
                    scanf("%d",&ch);
 
                    switch(ch)
                    {
                        case 1: delete_begin();
                                break;
                        case 2: delete_end();
                                break;
                        case 3: delete_pos();
                                break;
                        case 4: exit(0);
                        default: printf("Wrong Choice!!");
                    }
                    break;
            case 4: display();
                    break;
            case 5: exit(0);
					break;
            default: printf("Wrong Choice!!");
        }
    }
    return 0;
}
}
