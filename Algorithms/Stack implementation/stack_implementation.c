#include<stdio.h> 
#define MAX 5

int st[MAX],top=-1;

void push(int st[], int x);
void display(int st[]);
int pop(int st[]);
int peek(int st[]);

int main(){
    int option=0,val;
    while(option != 5){
        printf("\n****** Main Menu ******\n");
        printf("\n1: Push");
        printf("\n2: Peek");
        printf("\n3: display");
        printf("\n4: Pop");
        printf("\n5: Quit");
        printf("\n Enter your option :");
        scanf("%d",&option);
    
    switch (option){
        case 1:
            printf(" Enter the value to be pushed on stack: ");
            scanf("%d",&val);
            push(st, val);
            break;
        case 4:
            val = pop(st);
            if (val != -1){
                printf("The value deleted from the stack is : %d",val);
            }
            break;
        case 2:
            val = peek(st);
            if (val != -1){
                printf("The value at the top of the stack is : %d",val);
            }
            break;        
        case 3:
            display(st);
            break;  
    }
    }
    return 0;   
}
void push(int st[], int val){
    if(top == MAX-1){
        printf("Stack Overflow");
    }
    else{
        top++;
        st[top] = val;
    }
}
int pop(int st[]){
    int val;
    if (top == -1){
        printf("Stack Underflow");
        return -1;
    }
    else{
        val=st[top];
        top--;
        return val;
    }
}
void display(int st[]){
    int i;
    for(i=top; i>=0; i--){
        printf("\n%d\n",st[i]);
    }
}
int peek(int st[]){
    if(top == -1){
        printf("The stack is empty");
    }
    else{
        return (st[top]);
    }
}


