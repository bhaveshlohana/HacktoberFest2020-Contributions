#include<iostream>
#include<queue>
using namespace std;

struct node{
int data;
struct node*left;
struct node*right;
};
//------------------------------------------------New Node
struct node*newNode(int data){
struct node* node = new struct node;
node->data = data;
node->left = NULL;
node->right = NULL;
return node;
}
//--------------------------------------------------Insertion
struct node* insert(struct node*node,int data){
if(node == NULL){
  return newNode(data);
}

else{
    if(data <node->data){
    node->left = insert(node->left,data);
    }
    else{
    node->right = insert(node->right,data);
    }

    return node;
    }
}
//------------------------------------------------------Print Inorder
void printInorder(struct node*node){
if(node==NULL)
    return;
printInorder(node->left);
cout<<node->data<<" ";
printInorder(node->right);

}
//-----------------------------------------------Count Nodes
int getCount(struct node*node){
if(node==NULL)
    return 0;
else
    return getCount(node->left)+getCount(node->right)+1;
}
//----------------------------------------------------getMaxHeight
int getMaxHeight(struct node*root){
if(root==NULL)
    return 0;

int leftHeight = getMaxHeight(root->left);
int rightHeight = getMaxHeight(root->right);

return max(leftHeight,rightHeight)+1;
}

//-------------------------------------------------Print Level Order
void printLevelorder(struct node*root){
queue<node*> q;

q.push(root);

while(!q.empty()){


    struct node* n = q.front();


    cout<<n->data<<" ";
    q.pop();

    if(n->left!=NULL)
        q.push(n->left);
    if(n->right!=NULL)
        q.push(n->right);

    }

}

int main(){
struct node* root = NULL;
root = insert(root,5);
root=insert(root,6);
root=insert(root,7);
root=insert(root,3);
root=insert(root,2);
root=insert(root,4);
root=insert(root,8);
printInorder(root);
printLevelorder(root);
cout<<getCount(root);
cout<<getMaxHeight(root);
return 0;
}
