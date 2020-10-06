#include<iostream>
using namespace std ;


#include<iostream>
#include<queue>
using namespace std;

struct node{
int data;
struct node*left;
struct node*right;
};

//---------------------------------------Build Level Order
struct node*build(){
struct node*root = new node;
cout<<"Enter Root's Data";
cin>>root->data;

queue<node*> q;
q.push(root);

while(!q.empty()){

    struct node*temp = q.front();
    q.pop();
    cout<<"Enter the children (or -1) for node with data as "<<temp->data<<" : ";
    int data1;
    int data2;
    cin>>data1>>data2;

    if(data1!=-1){
          temp->left  = new node;
          temp->left->data = data1;
         q.push(temp->left);
    }
    else{
    temp->left = NULL;
    }

    if(data2!=-1){
        temp->right = new node;
        temp->right->data = data2;
        q.push(temp->right);
    }
    else{
    temp->right = NULL;
    }
  }
return root;
}
//--------------------------------------------------Print Level Order
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

//---------------------------------------------------Print Inorder
void printInorder(struct node*node){
if(node==NULL)
    return;
printInorder(node->left);
cout<<node->data<<" ";
printInorder(node->right);

}
//--------------------------------------------------Print Vertical Order
int getLeft(struct node*root){
if(root==NULL)
    return 0;

int count=0;
count += getLeft(root->left)+1;
return count;
}

int getRight(struct node*root){
if(root==NULL)
    return 0;

int count=0;
count += getRight(root->right)+1;
return count;
}





void printVerticalHelper(struct node*root,vector<vector<int> > &v,int colNo){

if(root==NULL){
    return;
    }
v[colNo].push_back(root->data);
printVerticalHelper(root->left,v,colNo-1);
printVerticalHelper(root->right,v,colNo+1);

}

void printVertical(struct node*root){

int left = getLeft(root);
int right = getRight(root);

vector<vector<int> > v;
v.reserve(left+right+1);
printVerticalHelper(root,v,left);

for(int i=0;i<=left+right;i++){
    for(int j=0;j<v[i].size();j++){
        cout<<v[i][j]<<" ";
    }
    cout<<endl;
}

return;
}


int main(){
struct node*root = build();
cout<<"Level Order :"<<endl;
printLevelOrder(root);
cout<<"Inorder : "<<endl;
printInorder(root);
cout<<endl<<"Vertical Order : "<<endl;
printVertical(root);
return 0;
}



