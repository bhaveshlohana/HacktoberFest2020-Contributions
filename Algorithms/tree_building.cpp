//Roshan kumar sahu
//119CS0159
//26/08/20
//Linux command flag:-g++ -std=c++14 260820119CS0159Q1.cpp

#include<iostream>
using namespace std;

struct treeNode{
  int data;
  treeNode* left;
  treeNode* right;
};

void Input(int arr1[],int arr2[],int n);
void Inorder(treeNode *Root);
void Preorder(treeNode *Root);
void Postorder(treeNode *Root);
treeNode* PreorderInorder(int preorder[],int inorder[],int preStartIndex,int preEndIndex,int inStartIndex,int inEndIndex);
treeNode* PostorderInorder(int postorder[],int inorder[],int postStartIndex,int postEndIndex,int inStartIndex,int inEndIndex);
treeNode* PreorderPostorder(int preorder[],int postorder[],int preStartIndex,int preEndIndex,int postStartIndex,int postEndIndex);

int main(){
  int n;
  cout<<"Enter the no. of inputs"<<endl;
  cin>>n;
  int choice;
  cout<<"\nEnter\n1: Preorder-Inorder to Postorder\n2: Postorder-Inorder to Preorder\n3: Preorder-Postorder to Inorder\n";
  cin>>choice;
  switch(choice){
    case 1:{
      int preorder[n];
      cout<<"Enter Preorder List & Inorder List\n";
      int inorder[n];
      Input(preorder,inorder,n);
      treeNode* Root=PreorderInorder(preorder,inorder,0,n,0,n);
      Postorder(Root);
      cout<<'\n';
      break;
    }
    case 2:{
      cout<<"Enter Postorder List & preorder List\n";
      int postorder[n];
      int inorder[n];
      Input(postorder,inorder,n);
      treeNode*Root=PostorderInorder(postorder,inorder,0,n,0,n);
      Preorder(Root);
      cout<<'\n';
      break;
    }
    case 3:{
      cout<<"Enter Preorder List & postorder List\n";
      int preorder[n];
      int postorder[n];
      Input(preorder,postorder,n);
      treeNode* Root=PreorderPostorder(preorder,postorder,0,n,0,n);
      Inorder(Root);
      break;
    }
    default:{
      cout<<"Invalid Input\n";
      break;
    }
  }

}

void Input(int arr1[],int arr2[],int n){
  cout<<"Enter the first list of "<<n<<" inputs separated by space\n";
  for(int i=0;i<n;i++){
    cin>>arr1[i];
  }
  cout<<"Enter the secont list of "<<n<<" inputs separated by space\n";
  for(int i=0;i<n;i++){
    cin>>arr2[i];
  }

}

void Inorder(treeNode *Root){
  treeNode* node=Root;
  if(node==NULL)
  return;
  Inorder(node->left);
  cout<<node->data<<' ';
  Inorder(node->right);
}

void Preorder(treeNode *Root){
  treeNode* node=Root;
  if(node==NULL)
  return;
  cout<<node->data<<' ';
  Preorder(node->left);
  Preorder(node->right);
}

void Postorder(treeNode *Root){
  treeNode* node=Root;
  if(node==NULL)
  return;
  Postorder(node->left);
  Postorder(node->right);
  cout<<node->data<<' ';
}

treeNode* PreorderInorder(int preorder[],int inorder[],int preStartIndex,int preEndIndex,int inStartIndex,int inEndIndex){
  if(preStartIndex>=preEndIndex)
  return NULL;
  treeNode* Root=new treeNode;
  Root->data=preorder[preStartIndex];
  int rootIndex;
  int lengthLeft=0;
  for(int i=inStartIndex;i<inEndIndex;i++){
    lengthLeft++;
    if(inorder[i]==preorder[preStartIndex]){
      rootIndex=i;
      break;
    }
  }
  Root->left=PreorderInorder(preorder,inorder,preStartIndex+1,preStartIndex+lengthLeft,inStartIndex,rootIndex);
  Root->right=PreorderInorder(preorder,inorder,preStartIndex+lengthLeft,preEndIndex,rootIndex+1,inEndIndex);
  return Root;
}

treeNode* PostorderInorder(int postorder[],int inorder[],int postStartIndex,int postEndIndex,int inStartIndex,int inEndIndex){
  if(postStartIndex>=postEndIndex)
  return NULL;

  treeNode* Root=new treeNode;
  Root->data=postorder[postEndIndex-1];
  int rootIndex;
  int lengthLeft=0;
  for(int i=inStartIndex;i<inEndIndex;i++){
    if(inorder[i]==postorder[postEndIndex-1]){
      rootIndex=i;
      break;
    }
    lengthLeft++;
  }
  Root->left=PostorderInorder(postorder,inorder,postStartIndex,postStartIndex+lengthLeft,inStartIndex,rootIndex);
  Root->right=PostorderInorder(postorder,inorder,postStartIndex+lengthLeft,postEndIndex-1,rootIndex+1,inEndIndex);

  return Root;
}

treeNode* PreorderPostorder(int preorder[],int postorder[],int preStartIndex,int preEndIndex,int postStartIndex,int postEndIndex){
  if(preStartIndex>=preEndIndex)
  return NULL;

  treeNode* Root=new treeNode;
  Root->data=preorder[preStartIndex];
  int rightRootIndex;
  int lengthLeft=0;
  for(int i=preStartIndex;i<preEndIndex;i++){
    if(preorder[i]==postorder[postEndIndex-2]){
      rightRootIndex=i;
      break;
    }
    lengthLeft++;
  }
  Root->left=PreorderPostorder(preorder,postorder,preStartIndex+1,preStartIndex+lengthLeft,postStartIndex,postStartIndex+lengthLeft-1);
  Root->right=PreorderPostorder(preorder,postorder,preStartIndex+lengthLeft,preEndIndex,postStartIndex+lengthLeft-1,postEndIndex-1);

  return Root;
}
