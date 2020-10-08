#include<iostream>
#include<queue>
using namespace std;

struct Node{
int data;
Node **children;
int childcount;
};

//------------------------------------------------------Build Tree using Level Order Traversal
Node *buildTree(){
Node *root = new Node;
cout<<"Enter data for root node"<<endl;
cin>>root->data;
// Level Order Building of Tree , So Use A Queue
queue<Node *> Q;

Q.push(root);

while(!Q.empty()){
    Node *temp = Q.front();
    Q.pop();
    cout<<" Enter child count of node with data as "<<temp->data<<endl;
    cin>>temp->childcount;
    temp->children = new Node*[temp->childcount];

    for(int i=0;i<temp->childcount;i++){
    temp->children[i] = new Node;
    cout<<"Enter data for child "<<i;
    cin>>temp->children[i]->data;
    Q.push(temp->children[i]);
        }

    }
return root;
}
//-------------------------------------------------------Build Recursively
void buildRecursively(struct Node**root){

    if(*root == NULL){
        cout<<"Enter Node's data ";
        *root = new Node;
        cin>>(*root)->data;
        cout<<"Enter Number of Children of Node with data as "<<(*root)->data<<" : ";
        cin>>(*root)->childcount;

        if((*root)->childcount==0)
                return;
        (*root)->children = new Node*[(*root)->childcount];
        for(int i=0;i<(*root)->childcount;i++){
            (*root)->children[i]=NULL;
            buildRecursively(&(*root)->children[i]);
            }

    }

}
//------------------------------------------------------Print Tree Preorder
//Inorder traversal is not possible , if there fixed no of nodes say 4 . Then we can print 2 left and 2 right
void printTreePreorder(Node *root)
{
    if(root==NULL){
    return;
    }
    cout<<root->data;
    for(int i=0;i<root->childcount;i++){
        printTreePreorder(root->children[i]);
    }
    cout<<endl;
}
//---------------------------------------------------Print Tree Post Order
void printTreePostOrder(Node*root){
    if(root==NULL)
    {
    return ;
    }
    for(int i=0;i<root->childcount;i++){
        printTreePostOrder(root->children[i]);
    }
    cout<<root->data<<" ";
}
//--------------------------------------Find Max in Tree
Node* findMax(Node *root){
    if(root==NULL){
        return NULL;
    }

    Node*largest = root;

    for(int i=0;i<root->childcount;i++){
    Node*temp=findMax(root->children[i]);
        if(temp->data > largest->data)
        {
        largest = temp;
        }
    }
return largest;
}
//------------------------------------------Find Depth in Tree
int findDepth(Node *root){

if(root==NULL){
    return 0;
}

int depth = -1;
for(int i=0;i<root->childcount;i++){
depth = max(depth,findDepth(root->children[i]));
}
return depth+1;
}
//-----------------------------------------Print Level Order
void printLevelOrder(Node*root){

queue<Node*> q;
q.push(root);
q.push(NULL);

while(!q.empty()){
    Node*temp = q.front();
    q.pop();

    if(q.empty())
        {
        cout<<endl;
        break;
        }

    else if(temp==NULL)
    {
        q.push(NULL);
        cout<<endl;
    }
    else{
        cout<<temp->data<<", ";
        for(int i=0;i<temp->childcount;i++){
            q.push(temp->children[i]);
            }
        }
    }
}
//-----------------------------------------------Main
int main(){
struct Node*root = buildTree();
/*Decomment to build Recursively */
//struct Node*root = NULL;
//buildRecursively(&root);
printLevelOrder(root);

cout<<"Max Element :"<<findMax(root)->data<<endl;
cout<<"Depth : "<<findDepth(root);
return 0;
}
