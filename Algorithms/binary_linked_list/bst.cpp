#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int
#define REP(i,a,b) for(int i = int(a);i<=int(b);i++)
vector<int> a;
struct bstNode{
	int data;
	struct bstNode *left, *right;
};

bstNode *newNode(int val){
	bstNode *node = new struct bstNode();
	node->data = val;
	node->left = node->right = NULL;
	return node;
}

bstNode *insertNode(struct bstNode *root, int val){
	if(root == NULL)	root = newNode(val);
	else if(val <= root->data)	root->left = insertNode(root->left, val);
	else	root->right = insertNode(root->right, val);
	return root;
}

void inOrderTraversal(struct bstNode *root){
	if(root == NULL)	return;
	inOrderTraversal(root->left);
	cout<<root->data<<endl;
	inOrderTraversal(root->right);
}
void preOrderTraversal(struct bstNode *root){
	if(root == NULL)	return;
	a.push_back(root->data);
	//cout<<root->data<<" ";
	preOrderTraversal(root->left);
	preOrderTraversal(root->right);
}
void postOrderTraversal(struct bstNode *root){
	if(root == NULL)	return;
	postOrderTraversal(root->left);
	postOrderTraversal(root->right);
	a.push_back(root->data);
	cout<<root->data<<" ";
}

void solve(vector<int> &A){
	int f=0,num=1;
	struct bstNode *root = NULL;
	while(num!=0){
		cin>>num;
		root = insertNode(root, num);
	}
	preOrderTraversal(root);
	
}

int main(){
	_
	vector<int> c;
	int n,b;
	cin>>n;
	REP(i,1,n){
		cin>>b;
		c.push_back(b);
	}
	solve(c);
	return 0;
}
