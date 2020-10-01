#include<bits/stdc++.h>
using namespace std;
// Link list Node 
struct Node {
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
}; 

void printList(Node *node){
    while(node!= NULL){
        cout<<node->data<<" ";
        node=node->next;
    }
    cout<<"\n";
}

/* Should return data of middle node. If linked list is empty, then  -1*/
int getMiddle(Node *head)
{
   Node *p=head;
   Node *q=head;
   int count=0;
   int x;
   while(p!=NULL){
       p=p->next;
       count++;
   }
   if(count%2==0){x=(count/2)+1;}
   else{x=(count+1)/2;}
   int y=0;
   while(y<x-1){
       q=q->next;
       y++;
   }
   return q->data;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int data;
        cin>>data;
        struct Node *head=new Node(data);
        struct Node *tail=head;
        for(int i=0;i<n-1;i++){
            cin>>data;
            tail->next=new Node(data);
            tail=tail->next;
        }
        cout<<getMiddle(head)<<endl;
    }
    return 0;
}
