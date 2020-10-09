#include<iostream>
#include <cstdlib>
using namespace std;

struct node
{
    int data;
    struct node*link;
};
struct node *head=NULL;
struct node *temp=NULL;


void create(int element)
{
    
    node*newnode=new node();
    newnode->data=element;
    newnode->link=NULL;
    //cout<<newnode->data;
    if(head==NULL)
    {
        temp=newnode;
        head=newnode;
        
    }
    
    else
    {
        temp->link=newnode;
        temp=newnode;
    }
    
}

void insert_at_head(int element)
{
	//temp=head->link;
	node*newhead=new node();
	newhead->data=element;
	newhead->link=NULL;
	if(head==NULL)
	{
		temp=newhead;
		head=newhead;
	}
	else//For a normal case
	{
	newhead->link=head;
	head=newhead;
	}
}

void insert_at_mid(int element,int position)
{
	node*newmid=new node();//Initial declarations
	newmid->data=element;
	newmid->link=NULL;
	temp=head;
	int count=0;
	
	if(head==NULL)
	{
		head=newmid;
		temp=newmid;
	}
	
	else
	{
		while(temp!=NULL)
		{
			if(count==position-2)//Pos-1-1,one for the indexing starting at 1,other to get in before 1 ele itself to insert,,compare with if(element==temp->data) when needed,apo count not needed.
			{
				newmid->link=temp->link;//DRAW box diagrams to understand
				temp->link=newmid;
				
				temp=temp->link;
				count++;
			}
			else
			{
				count++;
				temp=temp->link;
			}
		}
		

		
	}
}


void insert_at_end(int element)
{
	node*newend=new node();
	newend->data=element;
	newend->link=NULL;
	temp=head;
	
	if(head==NULL)
	{
		head=newend;
		temp=newend;
	}
	
	else
	{
		/*int count=0;
		while(temp!=NULL)
		{
			if(temp->link==NULL and count==0)
			{
				temp->link=newend;
				count++;
			}
			
			else
			{
				temp=temp->link;
			}
		}*/
		
		while(temp->link!=NULL)//till last-1 ele it runs so at the end it is at the tail with link as null 
		{
			temp=temp->link;//this logic avoids the use of count
		}
		temp->link=newend;
		
	}
}

void delete_at_head()
{
	node*dele=new node();
	if(head==NULL)
	{
		cout<<"Linked List empty";
	}
	dele=head;
	cout<<"The deleted first ele is:"<<head->data<<endl;
	head=head->link;
	free(dele);
}

void delete_at_mid(int element)
{
	node*delemid=new node();
	node*prev=new node();
	temp=head;
	if(head==NULL)
	{
		cout<<"Linked List empty";
	}
	else
	{
		while(temp!=NULL)//deleting wrt the element runs till that
	{
		
		if(temp->data==element)
		{
		delemid=temp;
		cout<<"The element deleted is:"<<temp->data<<endl;
		prev->link=temp->link;
		temp=prev->link;// or temp=temp->link;
		free(delemid);	
		}
		
		else{
		
		prev=temp;
		temp=temp->link;}
	}
	}
	
}

void delete_at_tail()
{
	node*deletetail=new node();
	node*back=new node();
	temp=head;
	if(head==NULL)
	{
		cout<<"Linked List empty";
	}
	else
	{
		while(temp->link!=NULL)//till last-1 ele it runs so at the end it is at the tail with link as null 
		{

			back=temp;
			temp=temp->link;//this logic avoids the use of count	
		}
		deletetail=temp;
		back->link=NULL;
		free(deletetail);
	}
}
void display()
{
    temp=head;
    while(temp!=NULL)//DONT USE temp->link!=NULL AS last element wont be displayed.
    {
        cout<<temp->data<<" ";
        temp=temp->link;
    }
}
int main()
{
    int n,a,i;
    cout<<"Enter the no of initial elements in the LL (n):";
    cin>>n;
    cout<<"Enter the elements:";
    for(i=0;i<n;i++)
    {cin>>a;
    create(a);
    }
    insert_at_head(404);
    cout<<"The final ll after inserting at head:";
    display();
    cout<<endl;
    
    insert_at_mid(420,3);
    cout<<"The final ll after inserting at mid:";
    display();
    cout<<endl;
    
    insert_at_end(104);
    cout<<"The final ll after inserting at end:";
    display();
	
	delete_at_head();    
    cout<<"The final ll after deleting at head:";
    display();  
	cout<<endl;
	
	delete_at_mid(420);
    cout<<"The final ll after deleting 420 at mid:";
    display();  
	cout<<endl;
		
	delete_at_tail();
	cout<<"The final ll after deleting at tail:";
    display();
}
