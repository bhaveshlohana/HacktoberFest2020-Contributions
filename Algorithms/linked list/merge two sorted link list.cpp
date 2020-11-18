  
#include<bits/stdc++.h>
using namespace std;
struct Node{
  int data;
  Node* next;
  Node(int data){
  this->data=data;
  next=NULL;
  }
};

Node* merge(Node* l1, Node* l2){
        Node* fhead=NULL;
        Node* ftail=NULL;
        
        while(l1 && l2){
            
            if(fhead==NULL){
              if(l1->data<=l2->data){
                  Node* temp= new Node(l1->data);
                  fhead=temp;
                  ftail= temp;
                  l1=l1->next;
              }   
              else{
                  Node* temp= new Node(l2->data);
                  fhead=temp;
                  ftail= temp;
                  l2=l2->next;
                }
            }
            else{
                 if(l1->data<=l2->data){
                  Node* temp= new Node(l1->data);
                  l1=l1->next;
                  ftail->next=temp;
                  ftail= temp;
              }   
              else{
                  Node* temp= new Node(l2->data);
                  l2=l2->next;
                  ftail->next=temp;
                  ftail= temp;
                }
                
            }
        }
        
        if(l1){
            ftail->next= l1;
        }
        
        if(l2){
            ftail->next= l2;
        }
        
        return fhead;
    }
    
 Node* mergelist(Node* l1, Node* l2) {
      if(!l1){
          return l2;
      }
      if(!l2){
          return l1;
      }
      if(!l1&&!l2){
          return NULL;
      }
        return merge(l1, l2);
 }
  
int main(){
int n1, n2; //length of the link list
cin>>n1>>n2;

Node* head=NULL;
Node* tail= NULL;

//linklist 1
for(int i=0;i<n1;i++){
    int node; //nodes of link list
    cin>>node;
    Node* newnode= new Node(node);
    if(head==NULL){
    head= newnode;
    tail= newnode;
    }
    else{
    tail->next= newnode;
    tail= newnode;
    }
}

Node* head2=NULL;
Node* tail2= NULL;

//linklist2
for(int i=0;i<n2;i++){
    int node; //nodes of link list
    cin>>node;
    Node* newnode= new Node(node);
    if(head2==NULL){
    head2= newnode;
    tail2= newnode;
    }
    else{
    tail2->next= newnode;
    tail2= newnode;
    }
}

Node* fhead= mergelist(head1, head2); //returns the head of the merged linklist
if(fhead==NULL){
cout<<"Empty Link List";
}
while(!fhead){
  cout<<fhead->data<<" ";
  fhead= fhead->next;
}

return 0;
}
