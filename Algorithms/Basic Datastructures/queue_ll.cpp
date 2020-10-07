#include<iostream>
using namespace std;

struct node{
    int data;
    node* link;
}*f=NULL,*r=NULL;

void push(int add){
    node*temp =new node;
    temp->data=add;
    temp->link=NULL;
    if(r==NULL)
        f=r=temp;
    else{
        r->link=temp;
        r=temp;
    }
}

void pop(){
    node*temp=f;
    if(f==NULL)
        cout<<"Queue Underflow";
    else if(f==r)
        f=r=NULL;
    else
        f=f->link;
    delete(temp);
}

int main(){
    int n,opt,ele,max;
    char wc;

    do{
        cout<<"Enter the Process to be done.\n1.Push\n2.Pop\nEnter your Option: ";
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

            default:cout<<"Choose the right Option.";
        }
        cout<<"Want to Continue?(Y/N):";
        cin>>wc;
    }while(wc=='Y'||wc=='y');
}
