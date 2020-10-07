//Stack as an array
#include<iostream>
using namespace std;

int top=-1,stack[50];
void push(int add,int max){
    if(top==max-1)
        cout<<"Stack Overflow";
    else{
        top++;
        stack[top]=add;
    }
}

void pop(){
    if(top==-1)
        cout<<"Stack Underflow";
    else{
        cout<<"deleting "<<stack[top]<<" ...";
        top--;
    }
}

int main(){
    int n,opt,ele,max;
    char wc;
    cout<<"Enter the max length: ";
    cin>>max;
    do{
        cout<<"Enter the Process to be done.\n1.Push\n2.Pop\nEnter your Option: ";
        cin>>opt;
        switch(opt){
            case 1:
                cout<<"Enter the element: ";
                cin>>ele;
                push(ele,max);
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
