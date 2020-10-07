#include<iostream>
using namespace std;

struct node{
    int data;
    node* link;
};

node* create(struct node* list,int add){
    if(list!=NULL)
        return list;
    struct node* temp=NULL;
    temp->data=add;
    list=temp;
    list->link=list;
    return list;
}

struct node* addbegin(struct node* list,int add){
    if(list == NULL)
        return create(list,add);
    struct node* temp=NULL;
    temp->data=add;
    temp->link=list->link;
    list->link=temp;
    return list;
}

struct node* addend(struct node* list, int add){
    if(list==NULL)
        return create(list, add);
    struct node* temp=NULL;
    temp->data=add;
    temp->link=list->link;
    list->link=temp;
    list=temp;
    return list;
}

void display(struct node* list){
    struct node* temp=NULL;
    temp=list->link;
    while(list!=NULL){
        cout<<list->data<<" ";
        temp=temp->link;
    }
}
int main(){
    int n,opt,ele,max;
    char wc;
    struct node* list=NULL;
    
    do{
        cout<<"Enter the Process to be done.\n1.Push at the Beginning\n2.Push at the End\n3.Display\nEnter your Option: ";
        cin>>opt;
        switch(opt){
            case 1:
                cout<<"Enter the element: ";
                cin>>ele;
                addbegin(list,ele);
                break;
            case 2:
                addend(list,ele);
                break;
            case 3:
                display(list);
                break;
            default:cout<<"Choose the right Option.";
        }
        cout<<"Want to Continue?(Y/N):";
        cin>>wc;
    }while(wc=='Y'||wc=='y');
}
