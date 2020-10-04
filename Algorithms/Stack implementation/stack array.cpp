#include <iostream>
using namespace std;
#define Nil 0
#define MaxEl 10
typedef int infotype;
typedef int address;
typedef struct{
    infotype Data[MaxEl+1];
    address TOP;
}Stack;
#define TOP(S) (S).TOP
#define InfoTop(S) (S).Data[(S).TOP]
void CreateEmpty(Stack *S){
    TOP(*S)=Nil;
}
bool IsEmpty(Stack S){
    return (TOP(S)==Nil);
}
bool IsFull(Stack S){
    return (TOP(S)==MaxEl);
}
void Push(Stack *S,infotype x){
    if(!IsFull(*S)){
        TOP(*S)++;
        InfoTop(*S)=x;
    }else{
        cout<<"Stack Penuh";
    }
}
void Pop(Stack *S, infotype *x){
    if(!IsEmpty(*S)){
        *x=InfoTop(*S);
        TOP(*S)--;
    }else{
        cout<<"Stack Kosong";
    }
}
int main()
{
    Stack S;
    CreateEmpty(&S);
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        Push(&S,x);
    }
    while(!IsEmpty(S)){
        Pop(&S,&x);
        cout<<x<<" ";
    }
}
