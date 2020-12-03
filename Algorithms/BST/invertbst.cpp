#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node *left;
    node *right;


};
node *root= NULL;

node* getnode(int val){

node *temp= new node();
temp->val= val;
temp->left= NULL;
temp->right= NULL;
return temp;

}

class BST{
        public:
            node* insertbst(node *root, int data);

            void inorder(node *root);
            void invert(node *root);
        };

node *BST::insertbst(node *root,int data)
//function to insert
{

//insert at root node
if (root == NULL){
root= getnode(data);
return root;
}
//left node insertion
else if(data <= root->val){
    root->left= insertbst(root->left,data);

}

//right node insertion
else{
    root->right= insertbst(root->right,data);
}
return root;
}

void BST:: inorder(node *root){
if(root== NULL){
    return;
}
cout<<root->val<<" " ;
inorder(root->left);

inorder(root->right);
}

void BST:: invert(node *root){

swap(root->left,root->right);


invert(root->left);
invert(root->right);
inorder(root);


}
int main(){
                BST b;
            root= b.insertbst(root,15);
            root= b.insertbst(root,10);
            root= b.insertbst(root,20);
            root= b.insertbst(root,25);
            root= b.insertbst(root,8);
            root= b.insertbst(root,12);
            b.inorder(root);
            cout<<"\n";
            b.invert(root);


            return 0;
}
