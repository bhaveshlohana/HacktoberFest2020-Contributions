#include<iostream>

using namespace std;

class Tree {
	private:
		int data;
		Tree *left;
		Tree *right;
	public:
		Tree() {
			data = 0;
			left = NULL;
			right = NULL;
		}

		Tree(int value) {
			data = value;
			left = NULL;
			right = NULL;
		}

		Tree* insert(Tree *root, int data) {
			if(!root) {
                		return new Tree(data);
      			}
        		if(root -> data < data) {
                		(root -> right) = insert(root -> right, data);
        		}
        		else if(root -> data > data) {
                		(root -> left) = insert(root -> left, data);
        		}
        		return root;

		}
		void inorder(Tree *root) {
			if(!root) {
                		return;
        		}
        		inorder(root -> left);
        		cout<<(root -> data)<<endl;
        		inorder(root -> right);
		}
};


int main() {
	Tree *root = NULL;
	Tree b;
	root = b.insert(root, 50);
	b.insert(root, 70);
	b.insert(root, 20);
	b.insert(root, 10);
	b.insert(root, 90);
	b.insert(root, 35);
	b.insert(root, 55);	
	b.inorder(root);

	return 0;
}
