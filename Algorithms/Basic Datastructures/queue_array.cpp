#include<iostream>
using namespace std;

int r=-1,f=-1,queue[50];

void push(int add,int max){
    if(r==max-1){
        cout<<"Queue Overflow";
    }
    else if(r==-1){
        f=r=0;
        queue[r]=add;
    }
    else{
        r++;
        queue[r]=add;
    }
}

void pop(){
    if(f==-1)
        cout<<"Queue Underflow";
    else if(f==r)
        f=r=1;
    else
        f++;
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
