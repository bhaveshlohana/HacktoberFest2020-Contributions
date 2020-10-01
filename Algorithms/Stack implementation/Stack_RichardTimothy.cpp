#include<bits/stdc++.h>
using namespace std;
int Stack[100], Max=100, top=-1;
bool isempty(){
    if(top==-1){
        return 1;
    }else{
        return 0;
    }
}
bool isfull(){
    if(top==Max-1){
        return 1;
    }else{
        return 0;
    }
}
void push(int val){
   if(isfull())
   cout<<"Stack Overflow"<<endl;
   else {
      top++;
      Stack[top]=val;
   }
}

void pop(){
   if(isempty())
   cout<<"Stack Underflow"<<endl;
   else {
      cout<<"The popped element is "<<Stack[top]<<endl;
      top--;
   }
}
void display(){
   if(top>=0) {
      cout<<"Stack elements are:";
      for(int i=top; i>=0; i--)
      cout<<Stack[i]<<" ";
      cout<<endl;
   } else
   cout<<"Stack is empty";
}
void peek(){
    cout<<Stack[top]<<endl;
}
int main() {
    
   int ch, val;
   cout<<"1 to Push"<<endl;  cout<<"2 to Pop"<<endl; cout<<"3 to Display"<<endl; cout<<"4 to peek"<<endl;
   cout<<"5 to exit"<<endl;
   do {
      cout<<"Enter choice: "<<endl;
      cin>>ch;
      switch(ch) {
         case 1: {
            cout<<"Enter the  value to be pushed:"<<endl;
            cin>>val;
            push(val);
            break;
         }
         case 2: {
            pop();
            break;
         }case 3: {
           display();
            break;
         }
         case 4: {
            peek();
            break;
         }
         default: {
            cout<<"Invalid Choice"<<endl;
         }
      }
   }while(ch!=5);
   return 0;}
