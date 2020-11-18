#include <stdio.h>
#include <stdlib.h>

struct Node {
	int Data;
	struct Node *next;
};

void insertNode(struct Node **head, int data, int pos) {
	int k = 1;
	struct Node *new, *p = *head, *q;
	new		  = (struct Node *)malloc(sizeof(struct Node));
	new->Data = data;
	if (*head == NULL && pos > 1) {
		printf("Please create atleast a few elements\n");
		return;
	} else if (pos == 1) {
		new->next = p;
		*head	  = new;
		return;
	} else {
		while (p != NULL && k < pos) {
			q = p;
			p = p->next;
			k++;
		}
		q->next	  = new;
		new->next = q; // cange link for cycle detection
	}
}

void deleteNode(struct Node **head, int pos) {
	struct Node *p = *head, *q;
	int k		   = 1;
	if (*head == NULL) {
		printf("Nothing to delete\n");
		return;
	} else if (pos == 1) {
		(*head) = (*head)->next;
	} else {
		while (p != NULL && k < pos) {
			q = p;
			p = p->next;
			k++;
		}
		if (p == NULL) {
			printf("Invalid Position\n");
			return;
		} else {
			q->next = p->next;
			free(p);
			return;
		}
	}
}

void printList(struct Node *head) {
	while (head != NULL) {
		printf("%2d -->", head->Data);
		head = head->next;
	}
	printf("NULL\n");
}

void cycleDetection(struct Node **head) {
	struct Node *fst = *head, *slw = *head;
	while (fst->next->next && slw->next) {
		fst = fst->next->next;
		slw = slw->next;
		if (fst == slw) {
			printf("Cycle Detected\n");
			exit(0);
		}
	}
}

int main() {
	struct Node *head = NULL;
	insertNode(&head, 5, 1);
	insertNode(&head, 4, 2);
	cycleDetection(&head);
	printList(head);
	return 0;
}
