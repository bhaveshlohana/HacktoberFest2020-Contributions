//PRINTING A TREE USING DFS (PreOrder,PostOrder, Inorder)
#include<bits/stdc++.h>
using namespace std;
struct bstnode{
	int data;
	bstnode *left;
	bstnode *right;
};
bstnode *root = NULL;
bstnode *getnode (int data)
{
	bstnode *p= new bstnode();
	p->data=data;
	p->left = p->right = NULL;
	return p;
}
bstnode *Insert(bstnode *root, int data)
{
	if(root == NULL)
	{
		root = getnode(data);
	}
	else if(data<=root->data)
	{
		root->left = Insert(root->left,data);
	}
	else if(data>root->data)
	{
		root->right = Insert(root->right, data);
	}
	return root;
}
//Depth order printing of the data in the node of the tree
//Inorder
void Inorder(bstnode *root) 
{
	if(root == NULL)
	{
		return;
	}
	Inorder(root->left); 
	cout<<root->data<<" "; 
	Inorder(root->right); 
}
//Preorder
void Preorder(bstnode *root) 
{
	if(root == NULL)
	{
		return;
	}
	cout<<root->data <<" "; 
	Preorder(root->left); 
	Preorder(root->right); 
}
//Postorder
void Postorder(bstnode *root) 
{
	if(root == NULL)
	{
		return;
	}
	Postorder(root->left); 
	Postorder(root->right); 
	cout<<root->data<<" "; 
	
}

int main()
{
	root = Insert(root, 10);
	Insert (root, 11);
	Insert(root, 9);
	Insert(root, 3);
	cout<<"Printing the tree in INORDER\n";
	Inorder(root);
	cout<<"\n";
	cout<<"Printing the tree in POSTORDER\n";
	Postorder(root);
	cout<<"\n";
	cout<<"Printing the tree in PREORDER\n";
	Preorder(root);	
}
