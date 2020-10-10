#include<iostream>
#include<bits/stdc++.h>
using namespace std;
            struct node{
            int data;
            node *left;
            node *right;
            };

node *root = NULL;

node *getnode(int data){
node *temp= new node();
temp->data= data;
temp->left=NULL;
temp->right= NULL;
return temp;

}
        class BST{
        public:
            node* insertbst(node *root, int data);
            bool searchbst(node *root,int data);
            void preorder(node *root);
            void inorder(node *root);
            void postorder(node *root);
            int findheight(node *root);
        };

//function to insert
node* BST:: insertbst(node *root,int data){

//insert at root node
if (root == NULL){
root= getnode(data);
return root;
}
//left node insertion
else if(data <= root->data){
    root->left= insertbst(root->left,data);

}

//right node insertion
else{
    root->right= insertbst(root->right,data);
}
return root;
}
            //searching in tree

            bool BST:: searchbst(node *root,int data){
            if (root== NULL){
                return false;
            }
            else if(root->data ==data){
                return true;
            }
            else if(data<= root->data){
                return searchbst(root->left,data);
            }
            else{
                return searchbst(root->right,data);
            }
            }
//print left
void BST ::preorder(node *root){
if(root == NULL)
{
    return;
}
else{
        cout<<root->data<<" ";
    preorder(root->left);
preorder(root->right);
}
cout<<endl;
}
        //print Inorder
        void BST :: inorder(node *root)
        {
         if(root == NULL)
        {
            return;
        }
        else{

            inorder(root->left);
            cout<<root->data<<" ";
            inorder(root->right);
        }
cout<<endl;
        }
//print Postorder
void BST :: postorder(node *root){
if (root == NULL){
    return ;
}
else {
    postorder(root->right);
    postorder(root->left);
    cout<<root->data<<" ";
}

}
/*
int BST :: findheight(node *root){
if(root == NULL)
    return -1;

    int f= max(findheight(root->left),findheight(root->right))+1;
cout<<&f;
}*/

//main function

            int main(){
                BST b;
            root= b.insertbst(root,15);
            root= b.insertbst(root,10);
            root= b.insertbst(root,20);
            root= b.insertbst(root,25);
            root= b.insertbst(root,8);
            root= b.insertbst(root,12);
            cout<<"Preorder Traversal"<<endl;
            b.preorder(root);
            cout<<"Inorder Traversal"<<endl;
            b.inorder(root);
            cout<<"Postorder Traversal"<<endl;
            b.postorder(root);
            cout<<endl;
cout<<"Height of tree"<<endl;
//            b.findheight(root);

            int n;
            cout<<"Enter Number";
            cin>>n;
            if(b.searchbst(root,n)== true){
                cout<<"found\n";

            }
            else cout<<"Not found\n";

            return 0;
            }
