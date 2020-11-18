// Quite hard to implement. :(

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define MAX_INT 0x3f3f3f3f 
#define acc(x) setprecision(x)
#define boost ios_base::sync_with_stdio(false); cin.tie(NULL);

#define T 2

/* 2-3 tree node */
struct node {
	int keys[3];			/* array stores at-most 3 keys in sorted fashion */
	int keys_count;			/* holds the no. of keys this node currently holds */
	struct node *p1;		/* first child from the left */
	struct node *p2;		/* second child from the left */
	struct node *p3;		/* third child from the left */
	struct node *p4;		/* right most child */
	struct node *parent;	/* parent node */
};

typedef struct node node;

node *root = NULL;

/** creates a new node */
node *create_new_node(int key) {
	node *mem = (node*)malloc(sizeof(node));
	mem->keys[0] = key;
	mem->keys[1] = mem->keys[2] = INT_MAX;
	mem->p1 = mem->p2 = mem->p3 = mem->p4 = mem->parent = NULL;
	mem->keys_count = 1;
	return mem;
}

/** check for overflows */
int is_overflow(node *y) {
	return y && y->keys_count == 2 * T - 1;
}

/** fixes the overflow*/
void insert_fixup(node *y) {

	while(is_overflow(y)) {	/* until we have a parent which does not overflow */

		printf("Overflow at [%d, %d, %d] occurred.\n", y->keys[0], y->keys[1], y->keys[2]);

		/* get median */
		int median = y->keys[1];

		/* split this node */
		node *w = create_new_node(y->keys[2]);
		w->p2 = y->p4;
		w->p1 = y->p3;

		/* fix child links for the split node */
		if(w->p2)
			w->p2->parent = w;
		if(w->p1)
			w->p1->parent = w;

		/* reset */
		y->keys[1] = y->keys[2] = INT_MAX;
		y->p3 = y->p4 = NULL;
		y->keys_count = 1;

		/* get parent for this node */
		node *p = y->parent;

		/* pull the median up to the parent */
		if(!p) {

			/* create new root node */
			root = create_new_node(median);

			/* set parent for both the splits */
			y->parent = w->parent = root;

			/* fix child links for the new root */
			root->p2 = w;
			root->p1 = y;

			break;

		} else {

			/* set parent for the new split */
			w->parent = p;

			if(y == p->p1) {		/* this is the left child */

				/* sort keys of the parent */
				p->keys[2] = p->keys[1];
				p->keys[1] = p->keys[0];
				p->keys[0] = median;

				/* increment key count */
				p->keys_count++;

				/* fix child links for the parent */
				p->p4 = p->p3;
				p->p3 = p->p2;
				p->p2 = w;

			} else if(y == p->p2) {	/* this is the middle child */

				/* sort keys of the parent */
				p->keys[2] = p->keys[1];
				p->keys[1] = median;

				/* increment key count */
				p->keys_count++;

				/* fix child links for the parent */
				p->p4 = p->p3;
				p->p3 = w;

			} else {				/* this is the right child */

				p->keys[2] = median;

				/* increment key count */
				p->keys_count++;

				/* fix child link for the new split */
				p->p4 = w;
			}

			/* we just increased the size of the parent node
			 * by 1, so it is possible that the parent node
			 * may have overflowed */

			/* move to parent */
			y = p;
		}
	}
}

/** Inserts the given key into the 2-3 tree */
void insert(int key) {

	node *y = NULL;
	node *x = root;

	/* search where to put the key */
	while(x) {
		y = x;				/* hold the parent node */
		if(key < x->keys[0])
			x = x->p1;
		else if(x->keys_count == 1)
			x = x->p2;
		else
			x = x->p3;
	}

	if(!y)
		root = create_new_node(key);

	else {
		if(key < y->keys[0]) {
			/* sort the keys */
			y->keys[2] = y->keys[1];
			y->keys[1] = y->keys[0];	/* median */
			y->keys[0] = key;

		} else if(key > y->keys[0] && key < y->keys[1]) {
			/* sort the keys */
			y->keys[2] = y->keys[1];
			y->keys[1] = key;			/* median */

		} else
			y->keys[2] = key;

		y->keys_count++;

		if(is_overflow(y))	/* violates BTree property */
			insert_fixup(y);
	}
}

/** checks if the given node underflows */
int is_underflow(node *y) {
	return y && y->keys_count < T - 1;
}

/** checks if the given node has enough keys to donate */
int has_enough_keys(node *y) {
	return y && y->keys_count > T - 1;
}

/** checks if the given node is empty */
int is_empty(node *y) {
	return y->keys_count == 0;
}

/** fixes the underflow  */
void delete_fixup(node *y) {

	while(is_underflow(y)) {		/* until we have a node which violates the BTree property */

		printf("Underflow occurred!\n");

		/* ask the parent for help */
		node *p = y->parent;

		node *x = NULL;		/* left sibling */
		node *z = NULL;		/* right sibling */

		if(y == p->p1) {	/* this is a left child */

			/* get the right sibling */
			z = p->p2;

			if (has_enough_keys(z)) {	/* z has enough ( > T-1 ) keys to donate */

				/* exchange the keys between y, p and z */
				y->keys[0] = p->keys[0];
				p->keys[0] = z->keys[0];	/* left key in z */

				/* fix links for y */
				y->p2 = z->p1;
				if(y->p2)
					y->p2->parent = y;

				/* update / reset z */
				z->keys[0] = z->keys[1];
				z->keys[1] = INT_MAX;
				z->keys_count--;

				/* fix links for z */
				z->p1 = z->p2;
				z->p2 = z->p3;
				z->p3 = NULL;

			} else {

				/**
				 * 	MERGE Operation
				 *  pull the parent key down
				 *  move z to y */

				printf("Merge Case I.\n");

				/** in this case, parent node may not have enough ( > T-1 ) keys
				 *  hence, pulling a key down to its children may leave the parent node empty. */

				/* y merged with p and z */
				y->keys[0] = p->keys[0];	/* parent key pulled down */
				y->keys[1] = z->keys[0];	/* only key of z */
				y->keys_count += 2;

				/* update parent */
				p->keys[0] = p->keys[1];
				p->keys[1] = INT_MAX;
				p->keys_count--;

				/* fix links */
				p->p2 = p->p3;
				p->p3 = NULL;
				y->p2 = z->p1;
				y->p3 = z->p2;
				if(y->p2)
					y->p2->parent = y;
				if(y->p3)
					y->p3->parent = y;

				/* clean */
				free(z);

				/* if root node has become empty
				 * y will be the new root */
				if(is_empty(root)) {
					root = y;
					y->parent = NULL;
					free(p);
					p = NULL;
				}
			}
		} else if(y == p->p2) {	/* this is a middle child */

			/* get both the siblings */
			z = p->p3;
			x = p->p1;

			if(has_enough_keys(z)) {	/* z exists, and has enough keys to donate */

				/* exchange the keys between y, p and z */
				y->keys[0] = p->keys[1];
				p->keys[1] = z->keys[0];	/* first key in z */

				/* fix links for y */
				y->p2 = z->p1;
				if(y->p2)
					y->p2->parent = y;

				/* update / reset z */
				z->keys[0] = z->keys[1];
				z->keys[1] = INT_MAX;
				z->keys_count--;

				/* fix links for z */
				z->p1 = z->p2;
				z->p2 = z->p3;
				z->p3 = NULL;

			} else if(has_enough_keys(x)) {	/* x has enough keys to donate */

				/* exchange keys between p, x and y */
				y->keys[0] = p->keys[0];
				p->keys[0] = x->keys[1];	/* last key in x */

				/* fix links for y */
				y->p1 = x->p3;
				if(y->p1)
					y->p1->parent = y;

				/* update / reset x */
				x->keys[1] = INT_MAX;
				x->p3 = NULL;
				x->keys_count--;

			} else {

				/** MERGE operation
				 *  pull the parent key down
				 *  merge with either of the sibling */

				if(z) {	/* if exists, move 'z' to 'y' */

					printf("Merge Case II.\n");

					/** In this case parent node is guaranteed to have > T-1 keys
					 * hence after a key is pulled down, the parent node does not become empty */

					y->keys[0] = p->keys[1];	/* pull parent key down */
					y->keys[1] = z->keys[0];	/* move z to y */
					y->keys_count += 2;		/* add newly added # of keys to  the y's key count */

					/* fix links for y */
					y->p1 = y->p2;
					y->p2 = z->p1;
					y->p3 = z->p2;
					if(y->p2)
						y->p2->parent = y;
					if(y->p3)
						y->p3->parent = y;

					/* update / reset parent */
					p->keys[1] = INT_MAX;
					p->p3 = NULL;
					p->keys_count--;

					/* clean */
					free(z);

				} else {	/* move 'y' to 'x' */

					printf("Merge Case III.\n");

					x->keys[1] = p->keys[0];	/* move parent node down */
					x->keys_count++;

					/* update parent */
					p->keys[0] = INT_MAX;
					p->p2 = NULL;
					p->keys_count--;

					/* fix links */
					x->p3 = y->p1;
					if(x->p3)
						x->p3->parent = x;

					/* clean */
					free(y);

					/* if root node has become empty
					 * x will be the new root */
					if(is_empty(root)) {
						root = x;
						x->parent = NULL;
						free(p);
						p = NULL;
					}
				}
			}
		} else {	/* this is a right child */

			/* get left sibling */
			x = p->p2;

			if(has_enough_keys(x)) {	/* x has enough keys to donate */

				/* exchange keys between p, x and y */
				y->keys[0] = p->keys[1];
				p->keys[1] = x->keys[1];	/* last key in x */

				/* fix links in y */
				y->p1 = x->p3;
				if(y->p1)
					y->p1->parent = y;

				/* update / reset x */
				x->keys[1] = INT_MAX;
				x->p3 = NULL;
				x->keys_count--;

			} else {

				printf("Merge Case IV.\n");

				/** In this case parent node is guaranteed to have > T-1 keys
				 * hence after a key is pulled down, the parent node does not become empty */

				x->keys[1] = p->keys[1];	/* move parent key to 'x' */
				x->keys_count++;
				p->keys_count--;

				/* fix links */
				p->p3 = NULL;
				p->keys[1] = INT_MAX;
				x->p3 = y->p1;
				if(x->p3)
					x->p3->parent = x;

				/* clean */
				free(y);
			}
		}
		/* move to the parent */
		y = p;
	}
}

/** searches the key in the 2-3 Tree and
 *  returns the node containing that key */
node *search(node *root, int key) {
	if(!root)
		return NULL;
	if(key < root->keys[0])
		return search(root->p1, key);		/* move to the left sub tree */
	if(key > root->keys[0] && key < root->keys[1])
		return search(root->p2, key);		/* move to the middle sub tree */
	if(key > root->keys[1])
		return search(root->p3, key);		/* move to the right sub tree */
	return root;	/* found */
}

node *tree_minimum(node *root) {
	if(root->p1)
		return tree_minimum(root->p1);
	return root;
}

node *tree_maximum(node *root) {
	if(root->p3)
		return tree_maximum(root->p3);
	if(root->p2)
		return tree_maximum(root->p2);
	return root;
}

/** checks if the given node is a leaf node */
int is_leaf(node *x) {
	return x->p1 == NULL && x->p2 == NULL;
}

/** checks if the given node is a root node */
int is_root(node *x) {
	return root == x;
}

void deleter(int key) {

	/* first search the node which has this key */
	node *x = search(root,key);

	if(is_leaf(x)) {

		if(key == x->keys[0]) {
			/* shift keys to the left */
			x->keys[0] = x->keys[1];
			x->keys[1] = INT_MAX;

		} else
			x->keys[1] = INT_MAX;

		x->keys_count--;	/* decrement key count */

		if(is_underflow(x)) {	/* violates BTree property */

			if(is_root(x)) {
				free(root);
				root = NULL;

			} else
				delete_fixup(x);
		}

	} else {

		/* find inorder successor for this key */
		node *y = NULL;
		if(key == x->keys[0])
			y = tree_minimum(x->p2);
		else
			y = tree_minimum(x->p3);

		/* exchange the value between x and y */
		if(key == x->keys[0])
			x->keys[0] = y->keys[0];
		else
			x->keys[1] = y->keys[0];

		/* update / reset the entries in y */
		y->keys[0] = y->keys[1];
		y->keys[1] = INT_MAX;
		y->keys_count--;

		if(is_underflow(y))	/* violates BTree property */
			delete_fixup(y);

		else {
			/* update / reset links */
			y->p1 = y->p2;
			y->p2 = y->p3;
			y->p3 = NULL;
		}
	}
}

void inorder(node *root) {
	if(root) {
		inorder(root->p1);
		printf("%d ", root->keys[0]);
		inorder(root->p2);
		if(root->keys_count == 2)
			printf("%d ", root->keys[1]);
		inorder(root->p3);
	}
}

void preorder(node *root) {
	if(root) {
		printf("%d ", root->keys[0]);
		preorder(root->p1);
		if(root->keys_count == 2)
			printf("%d ", root->keys[1]);
		preorder(root->p2);
		preorder(root->p3);
	}
}

int main() {

	while(1) {

		printf("+-------------------------+\n"
				"[1] Insert into 2-3 tree.\n"
				"[2] Delete from 2-3 tree.\n"
				"[3] Search for a key.\n"
				"[4] Display Inorder\n"
				"[5] Display Preorder\n"
				"[6] Exit\n"
				"Enter your choice: ");

		char ch;
		scanf(" %c", &ch);

		switch(ch) {
			case '1':
				printf("Enter the key : ");
				int key;
				scanf("%d", &key);
				if(search(root, key)) {	/* first check if the key already exists */
					printf("%d already exists in 2-3 tree.\n", key);
					break;
				}
				insert(key);
				if(root)
					printf("%d successfully inserted.\n", key);
				else {
					printf("Error occurred.\n");
					exit(1);
				}
				break;

			case '2':
				if(!root) {
					printf("2-3 is empty!\n");
					break;
				}
				printf("Enter the key : ");
				scanf("%d", &key);
				if(!search(root, key)) {
					printf("%d is NOT present in the 2-3.\n", key);
					break;
				}
				deleter(key);
				if(root)
					printf("%d successfully deleted.\n", key);
				else if(!root)
					printf("2-3 Tree is now empty!\n");
				else {
					printf("Error occurred.\n");
					exit(1);
				}
				break;

			case '3':
				printf("Enter the key : ");
				scanf("%d", &key);
				if(search(root, key))
					printf("%d is present in the 2-3 tree.\n", key);
				else
					printf("%d NOT FOUND in the 2-3 tree.\n", key);
				break;

			case '4':
				if(!root)
					printf("2-3 tree is empty\n");
				else {
					inorder(root);
					printf("\n");
				}
				break;

			case '5':
				if(!root)
					printf("2-3 tree is empty\n");
				else {
					preorder(root);
					printf("\n");
				}
				break;
			case '6':
				printf("Enter 'y' to exit : " );
				char ch;
				scanf(" %c", &ch);
				if(ch == 'y') {
					free(root);
					exit(1);
				}
				break;
			default:
				printf("Invalid choice! Try again...\n");
		}
	}
	return 0;
}