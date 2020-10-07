#include<iostream>
using namespace std;

struct node{
    int data;
    struct node* link;
};

node* merge(struct node* list1, struct node* list2){
    struct node* merged=NULL;
    if(list1==NULL)
        return(list2);
    else if(list2==NULL)
        return(list1);
    
    if(list1->data<=list2->data){
        merged=list1;
        merged->link=merge(list1->link,list2);
    }
    else{
        merged=list2;
        merged->link=merge(list1,list2->link);
    }
    return(merged);
}
void push(struct node** list, int add){
    node* temp = new node;
    temp->data=add;
    temp->link= *list;
    *list = temp;
}

void display(struct node* temp){
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->link;
    }
}

int main(){
    int n,m,add;
    char wc;
    struct node* list1=NULL;
    struct node* list2=NULL;
    struct node* merged=NULL;
    cout<<"Enter the Max of List 1: ";
    cin>>n;
    cout<<"Enter the Max of List 1: ";
    cin>>m;
    for(int i=0;i<n;i++){
        cin>>add;
        push(&list1,add);
    }
    for(int i=0;i<m;i++){
        cin>>add;
        push(&list2,add);
    }
    merged=merge(list1,list2);
    display(merged);
}
