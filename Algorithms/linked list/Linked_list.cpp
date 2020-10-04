#include <iostream>
using namespace std;
class Node{
	public:
		int no;
		Node *next;
};
class List{
	public:
		Node *head,*temp;
		void creat();
		void display();
};

void List::creat(){
	int n,i;
	cout<<"Enter number of nodes: ";
	cin>>n;
	head = new Node;
	temp=head;
	cout<<"Enter data value: "<<endl;
	cin>>head->no;
	for(i=0;i<n-1;i++){
		head->next=new Node;
		head = head->next;
		cout<<"\nEnter data value: "<<endl;
		cin>>head->no;
	}
	head->next=NULL;
}

void List::display(){
	head=temp;
	cout<<"\nThe linked list is: "<<endl;
	while(head->next!=NULL){
		cout<<head->no<<"\t";
		head=head->next;
	}
	cout<<head->no;
}
int main(){
	List l;
	l.creat();
	l.display();
	return 0;
}
