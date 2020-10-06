#include<iostream>
#include<queue>
#include<cmath>
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
q.push(NULL);

while(!q.empty()){


    struct node* n = q.front();
    q.pop();
    if(q.empty()){
    cout<<endl;
    break;
    }

    if(n==NULL&&!q.empty()){
        q.push(NULL);
        cout<<endl;
    }

    else{
    cout<<n->data<<" ";
    if(n->left!=NULL)
        q.push(n->left);
    if(n->right!=NULL)
        q.push(n->right);
        }
    }
}
void printSpaces(int spaces){
    for(int i=0;i<spaces;i++)
        cout<<" ";
return ;
}

//--------------------------------------Pretty Printing of Binaray Tree
int prettyPrint(struct node*root){

    int spaces = 2*pow(2,getMaxHeight(root)-1);

    queue<node*> q;

    q.push(root);
    q.push(NULL);

    while(!q.empty()){


    struct node* n = q.front();
    q.pop();
    if(q.empty()){
    cout<<endl;
    break;
    }

    if(n==NULL&&!q.empty()){
        spaces = spaces/2;
        q.push(NULL);
        cout<<endl;
    }

    else{

    if(n->data!=-1){
    printSpaces(spaces);
    cout<<n->data;
    printSpaces(spaces);
    }
    /*else{
    printSpaces(spaces);
    cout<<" ";
    printSpaces(spaces);
    }*/
    if(n->left!=NULL)
        q.push(n->left);
    else{
        struct node*dummy = new struct node;
        dummy->data = -1;
        dummy->left = dummy->right = NULL;
        q.push(dummy);
        }
    if(n->right!=NULL){
        q.push(n->right);
        }
    else{
        struct node*dummy = new struct node;
        dummy->data = -1;
        dummy->left = dummy->right = NULL;
        q.push(dummy);
            }
        }
    }
}
void printPreorder(struct node*root){

}

int main(){
struct node* root = NULL;
root = insert(root,5);
root=insert(root,3);
root=insert(root,2);
root=insert(root,4);
root=insert(root,7);
root=insert(root,6);
root=insert(root,8);
root=insert(root,9);
printLevelorder(root);

prettyPrint(root);
int h=0;
//cout<<"Diameter :"<<findDiameter(root,h);

return 0;
}


