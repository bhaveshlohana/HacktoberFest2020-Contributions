#include<iostream>
using namespace std;
class Linked
{
	public:
		char data;
		Linked *next;
		Linked *head;
		Linked  *current;
		void insert(char v)
		{
			Linked *temp=new Linked;
			temp->data=v;
			temp->next=NULL;
			if(head==NULL)
			{
				head=temp;
                current = head;
			}
            current->next = temp;
		    current=temp;
		}
		void check_pal()
		{
			Linked *temp=new Linked();
			temp=head;
			string s="";
			string rev="";
			while(temp!=NULL)
			{
				s=s+temp->data;
				rev=temp->data+rev;
				temp=temp->next;
			}
			if(s==rev)
			{
				cout<<"pallindrome";
			}
			else
			{
				cout<<"not pallindrome";
			}
		}
		
	
		void display()
		{
			while(head!=NULL)
			{
				cout<<head->data<<" ";
				head=head->next;
			}
		}
};
int main()
{
	Linked l1;
	l1.insert('R');
	l1.insert('c');
	l1.insert('D');
	l1.insert('A');
    l1.insert('R');
	l1.check_pal();
    
	
	
		return 0;	
}
