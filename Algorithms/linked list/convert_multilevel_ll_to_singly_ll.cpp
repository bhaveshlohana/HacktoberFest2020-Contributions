#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Data Structure to store a linked list node
struct Node
{
	int data;
	Node *next, *child;
};

// Helper function to create a new node with the given data and
// pushes it onto the front of the list
void push(Node* &headRef, int data)
{
	Node* newNode = new Node;

	newNode->data = data;
	newNode->next = headRef;
	newNode->child = nullptr;
	headRef = newNode;
}

// Helper function to create a linked list with elements of given vector
Node* createHorizontalList(vector<int> const &input)
{
	Node* head = nullptr;
	for (int i = input.size() - 1; i >= 0; i--)
		push(head, input[i]);

	return head;
}

// Function to convert a multilevel linked list to a singly linked list
void convertList(Node* const head)
{
	Node* curr = head;
	queue<Node*> q;

	// process all nodes
	while (curr)
	{
		// last node is reached
		if (curr->next == nullptr)
		{
			// pop a node from queue and set it as next node of current node
			curr->next = q.front();
			q.pop();
		}

		// if current node has a child
		if (curr->child)
		{
			q.push(curr->child);
		}

		// advance the current node
		curr = curr->next;
	}
}

// Helper function to print given linked list
void printList(Node* const head)
{
	Node* ptr = head;
	while (ptr)
	{
		cout << ptr->data << " -> ";
		ptr = ptr->next;
	}

	cout << "nullptr" << endl;
}

int main()
{
	// create a multilevel linked list
	Node* head = createHorizontalList({1, 2, 3, 4, 5});
	head->child = createHorizontalList({6, 7});
	head->next->next->child = createHorizontalList({8, 9});
	head->child->next->child = createHorizontalList({10, 11});
	head->child->next->child->child = createHorizontalList({12});

	convertList(head);
	printList(head);

	return 0;
}
