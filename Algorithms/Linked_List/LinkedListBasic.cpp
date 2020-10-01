// author: hrahul2605
#include <bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	struct Node* next;
};

// inserting node at the starting;

void push(Node** head,int value){
	
	Node* newNode = new Node();
	
	newNode->data = value;
	newNode->next = *head;
	
	*head = newNode;
	
	cout<<"NODE ADDED AT THE BEGINNING.\n";
	
	return;
} 

// inserting node at the end of the list;

void insertNode(Node** head, int value){	

	Node* newNode = new Node();

	newNode->data = value;
	newNode->next = NULL;

	if(*head==NULL){
		*head = newNode;
		return ;
	}

	Node* temp = *head;

	while(temp->next!=NULL)
		temp = temp->next;
	
	temp->next = newNode;
	cout<<"NODE ADDED AT THE END OF LIST\n";
	return;
}

// printing linked list

void printList(Node* head){
	while(head!=NULL){
		cout<<head->data<<" ";
		head = head->next;
	}

	cout<<"\nLIST PRINTED\n";

	return ;
}

// node deleted based on the value provided.

void deleteNode(Node** head, int data){
	Node* temp = *head, *prev;
	if(temp==NULL){
		cout<<"NO NODE TO DELETE.\n";
		return;
	}
	else if(temp->data==data){
		*head = temp->next;
		delete temp;
		cout<<"NODE DELETED.\n";
		return;
	}

	while(temp!=NULL){
		if(temp->data==data){
			prev->next = temp->next;
			delete temp;
			cout<<"NODE DELETED.\n";
			return;
		}
		prev = temp;
		temp = temp->next;
	}

	cout<<"ELEMENT DOES NOT EXIST IN THE LIST.\n";
	return;
}

int32_t main(){

	Node* head = NULL;

	int key = 0;
	cout<<"PRESS 1 to print the list.\nPRESS 2 to add node at the end of list.\nPRESS 3 to delete node with given value\nPRESS 4 to add node at the beginnig of list.\nPRESS 5 to exit.\n";

	cin>>key;
	while(key!=5){
		if(key==1){
			printList(head);
		}
		else if(key==2){
			int data;
			cout<<"Enter value: ";
			cin>>data;
			insertNode(&head,data);
		}

		else if(key==3){
			int data;
			cout<<"Enter value: ";
			cin>>data;
			deleteNode(&head,data);
		}

		else if(key==4){
			int data;
			cout<<"Enter value: ";
			cin>>data;
			push(&head,data);
		}

		cout<<"PRESS 1 to print the list.\nPRESS 2 to add node at the end of list.\nPRESS 3 to delete node with given value\nPRESS 4 to add node at the beginnig of list.\nPRESS 5 to exit.\n";
		cin>>key;
	}

} 