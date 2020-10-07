#include<iostream>
using namespace std;

struct node{
    int data;
    struct node* link;
}*top=NULL;

void intersect(struct node* list1,struct node* list2){
    struct node*check1 = list1;
    struct node*check2 = list2;
    while(check1!=NULL){
        while (check2!=NULL) {
            if(check1->data==check2->data){
                cout<<check1->data<<" ";
            }
            check2=check2->link;
        }
        check1=check1->link;
        check2=list2;
    }
}
void push(struct node** list, int add){
    node* temp = new node;
    temp->data=add;
    temp->link= *list;
    *list = temp;
}

void pop(){
    node*temp=top;
    if(top==NULL)
        cout<<"Stack Empty";
    else{
        top=top->link;
        temp->link=NULL;
    }
    delete(temp);
}

void display(){
    node*temp=top;
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
    intersect(list1,list2);
}
