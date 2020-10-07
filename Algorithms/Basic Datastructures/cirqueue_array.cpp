#include<iostream>
using namespace std;

int f=-1,r=-1,cirque[50];

void push(int add, int max){
    if(((f==0)&&(r==max-1))||(f==r+1))
        cout<<"Circular Queue Overflow";
    else{
        if(r==-1)
            f=r=0;
        else if(r==max-1)
            r=0;
        else
            r++;
        cirque[r]=add;
    }
}

void pop(int max){
    if(f==-1)
        cout<<"Circular Queue Underflow";
    else if(f==r)
        f=r=-1;
    else if(f==max-1)
        f=0;
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
                pop(max);
                break;
            
            default:cout<<"Choose the right Option.";
        }
        cout<<"Want to Continue?(Y/N):";
        cin>>wc;
    }while(wc=='Y'||wc=='y');
}
