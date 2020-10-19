#include<stdio.h>       
#define max 100
char a[max],exp[max];
int top=-1;

void push(char val)
{
    if(top==max-1)
        printf("\n Stack Overflow !! No values can be added now.\n");
    else
    {
        top++;
        a[top]=val;
        printf("\n The value pushed is stack is %c. The status of top now is %d\n",val,top);
    }
}
void pop()
{
    if(top==-1)
        printf("\n Stack underflow !! No elements can be deleted.\n");
    else
    {
        printf("\n The element to be deleted is %c.",a[top]);
        top--;
        printf("\n The status of top is %d\n",top);
    }
}

void display()
{
    int pos;
    pos=0;
    printf("\n ELEMENTS OF STACK : ");
    if(top==-1)
        printf("\t Stack is empty \n");
        while(pos<=top)
    {
        printf("\t%c",a[top-pos]);
        pos++;
    }
}

int balance()
{
    int i = 0;
    while (exp[i])
    {
        if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[')
            push(exp[i]);
        else if (a[top] == '(' && exp[i]== ')')
            pop();
        else if (a[top] == '{' && exp[i] == '}')
            pop();
        else if (a[top] == '[' && exp[i] == ']')
            pop();
        else
        {
            display();
            return 0;
        }
        i++;
    }
    display();
    if (top==-1)
        return 1; /*balanced*/
    else
        return 0; /*not balanced*/
}

int main()
{
    int x;
    printf("\n\n ENTER STRING : ");
    gets(exp);
    printf("\n\n\t\t*******\n\t\tPROCESS\n\t\t-------\n");
    x=balance(exp);
    printf("\n\n\t\t*******\n\n\t\t     CONCLUSION \n\n\t\t");
    if(x)
        printf("Stack is Balanced \n");
    else
        printf("Stack is not Balanced \n");
    return 0;
}
