#include<stdio.h>
#include<stdlib.h>

struct ListNode
{
	int data; // Type declaration of linked list
	struct ListNode *next;
};

/* Basic operations:
Traversing the list - Time complexity - O(n) space complexity- O(1)
Inserting an item in the list - Time complexity - O(n) space complexity - O(1)
 - before head(at the beginning)
 - after tail(at the end)
 - middle (random position)
Deleting an item from the list
 - deleting first node
 - deleting last node
 - deleting an intermediate node
 Deleting the LinkedList - Time complexiy - O(n) Space Complexity - O(1)
 */

//create a head node
struct ListNode *head;

// returns the length of the list
int ListLength() {
	struct  ListNode *current = head;
    int count = 0;

    while(current != NULL) {
    	count++;
    	current = current -> next;
    }
    return count;
}

//insertion a element at given position
void InsertInLinkedList(int data, int position) {
	int k = 0;
	struct ListNode *p, *q, *newNode; // q is to keep track f previous p is to keep track of current
	newNode = (struct ListNode *)malloc(sizeof(struct ListNode));

	if(!newNode) {
		printf("Memory Error!\n");
		return;
	}

    newNode -> data = data;

    if (head == NULL) {
    	head = newNode;
    	return;
    }


	p = head;
	//inserting at beginning
	if (position == 0) {
		newNode -> next = p;
		head = newNode;
	}
	else {
		//Traverse the list until the position is reached
		while((p != NULL) && (k < position)) {
			k++;
			q = p;
			p = p -> next;
		}
	}

	q -> next = newNode;
	newNode -> next = p;

}

//Deleting a element from the given position
void DeleteNodeFromLinkedList(int position) {
	int k = 0;
	struct ListNode *p, *q;
	if (head == NULL) {
		printf("The List is Empty!\n");
		return;
	}

	p = head;
	//removing from the beginning
	if (position == 1) {
		head = (head) -> next;
		free(p);
		return;
	}
	else {
		//Traverse the list until position is reached
		while((p!= NULL) && (k < position)) {
			k++;
			q = p;
			p = p -> next;
		}
	}
	if (p == NULL) {
		printf("Position does not exist!\n");
	}
	else {
		q -> next = p -> next;
		free(p);
	}
}

//Deleting the linkedlist
void DeleteLinkedList() {
	struct ListNode *AuxilaryNode, *iterator;
	iterator = head;

	while(iterator) {
		AuxilaryNode = iterator -> next;
		free(iterator);
		iterator = AuxilaryNode;
	}
	head = NULL; // to affect the real head back in the caller
}

//reverse the linked list
void ReverseLinkedList() {
    struct ListNode *prevNode, *currentNode, *nextNode;
    prevNode = NULL;
    currentNode = nextNode = head;
    while(nextNode != NULL) {
        nextNode = nextNode -> next;
        currentNode -> next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }
    head = prevNode;
}

// prints the linked list
void print() {

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    else {
        struct ListNode *current ;
        current = head;
        while (current -> next != NULL) {
            printf("[%d] -> ", current -> data);
            current = current -> next;
        }
        printf("[%d]\n", current -> data);
        return;
    }
}

int main() {
    // index starts from 0
	InsertInLinkedList(5,0);
	InsertInLinkedList(10,1);
	InsertInLinkedList(20,2);
	InsertInLinkedList(30,3);

    printf("Lenght of list : %d\n", ListLength()); // 4

    print(); // [5] -> [10] -> [20] -> [30]

    ReverseLinkedList();

    print(); // [30] -> [20] -> [10] -> [5]

    ReverseLinkedList();

    print(); // [5] -> [10] -> [20] -> [30]

    DeleteNodeFromLinkedList(2);

    print(); // [5] -> [10] -> [30]


    DeleteLinkedList();


    print(); // List is empty
} 
