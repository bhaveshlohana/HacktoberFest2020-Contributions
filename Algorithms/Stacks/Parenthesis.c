#include <stdio.h>
#include <stdlib.h>
int check(char*);
int peek(char*);
int pop(char*);
void push(char*, char);
int top = -1;
int main()
{
    char s[100];
    printf("Enter string : ");
    scanf("%s", s);
    printf("Valid : %d\n", check(s));
}
int check(char *s)
{
    int flag = 0;
    int i = 0;
    char stack[100];
    while(s[i])
    {
        if(s[i]=='{' || s[i]=='(' || s[i]=='[')
            push(stack,s[i]);
        else
        {
            if (top==-1)
                return 0;
            else if ((s[i]=='}' && peek(stack)=='{') || (s[i]==')' && peek(stack)=='(') || (s[i]==']' && peek(stack)=='['))
                pop(stack);
            else;
        }
        i+=1;
    }
    return (top==-1);
}
int peek(char *stack)
{
    return stack[top];
}
int pop(char *stack)
{
    top-=1;
    return stack[top+1];
}
void push(char *stack, char c)
{
    top+=1;
    stack[top]=c;
}