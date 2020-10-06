#include<iostream>
#include<queue>
using namespace std;

struct node{
int data;
struct node*left;
struct node*right;
};

void printLevelOrder(node*root){

queue<node*> q;
q.push(root);
q.push(NULL);

while(!q.empty()){
    node*temp = q.front();
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
        cout<<temp->data<<" ";
        if(temp->left!=NULL){
            q.push(temp->left);
        }
        if(temp->right!=NULL){
            q.push(temp->right);
        }
    }
}
}


//-------------------------------------------------------------Create BST
struct node*createBST(int *a,int low,int high){


 if(low<=high){
    struct node*root = new node;
    int mid = (low+high)/2;
    root->data = a[mid];
    root->left = createBST(a,low,mid-1);
    root->right = createBST(a,mid+1,high);

    return root;
    }
else
    return NULL;
}
//-------------------------------------------------------PRINT MIRROR OF TREE
struct node* createMirror(struct node*root){
    if(root==NULL){
        return NULL;
    }
    struct node*temp = createMirror(root->left);
    root->left = createMirror(root->right);
    root->right = temp;

    return root;
}

int main(){
int a[8]={1,2,3,4,5,6,7,8};
struct node*root = NULL;
root = createBST(a,0,7);
printLevelOrder(root);
createMirror(root);
cout<<"Mirror : "<<endl;
printLevelOrder(root);
return 0;
}
