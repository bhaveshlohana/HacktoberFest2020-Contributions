#include<iostream>
using namespace std;

struct node{
    int data;
    struct node* link;
}*top=NULL;

void push(int add){
    node* temp = new node;
    temp->data=add;
    temp->link=NULL;
    if(top==NULL)
        top=temp;
    else{
        temp->link=top;
        top=temp;
    }
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
    int n,opt,ele,max;
    char wc;

    do{
        cout<<"Enter the Process to be done.\n1.Push\n2.Pop\n3.Display\nEnter your Option: ";
        cin>>opt;
        switch(opt){
            case 1:
                cout<<"Enter the element: ";
                cin>>ele;
                push(ele);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            default:cout<<"Choose the right Option.";
        }
        cout<<"Want to Continue?(Y/N):";
        cin>>wc;
    }while(wc=='Y'||wc=='y');
}
