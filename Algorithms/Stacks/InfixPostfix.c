#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void convert(char*, char*);
void push (char*, char);
char pop(char*);

int top = -1;

int main()
{
    char infix[10],postfix[10];
    printf("Enter infix :");
    scanf("%s", infix);
    printf("Infix  : %s\n", infix);
    convert(infix, postfix);
    printf("Postfix  : %s\n", postfix);
}
int inputprecedence(char c)
{
    switch(c)
    {
        case '+':return 1;
        case '-':return 1;
        case '*':return 3;
        case '/':return 3;
        case '$':return 6;
        case '(':return 9;
        case ')':return 0;
        default:return 7;
    }
}
int stackprecedence(char c)
{
    switch(c)
    {
        case '+':return 2;
        case '-':return 2;
        case '*':return 4;
        case '/':return 4;
        case '$':return 5;
        case '(':return 0;
        case '#':return -1;
        default:return 8;
    }
}
void push(char *stack, char c)
{
    top+=1;
    stack[top] = c;
}
char pop(char* stack)
{
    char x = stack[top];
    top-=1;
    return x;
}
void convert(char *infix, char *postfix)
{
    char stack[10];
    int ctr = 0;
    top = -1;
    push(stack, '#');
    int i = 0;
    while (infix[i])
    {
        while(stackprecedence(stack[top])>inputprecedence(infix[i]))
        {
            postfix[ctr]=pop(stack);
            ctr+=1;
        }
        if(stackprecedence(stack[top])<inputprecedence(infix[i]))
        {
            push(stack, infix[i]);
        }
        else
        {
            pop(stack);
        }
        i+=1;
    }
    while(top!=-1)
    {
        postfix[ctr]=pop(stack);
        ctr+=1;
    }
    postfix[ctr-1] = '\0';
}
