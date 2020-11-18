#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int top = -1;
float eval(char*);
void push(int*,int);
int pop(int*);
int main()
{
    char postfix[10];
    printf("Enter postfix expression : ");
    scanf("%s", postfix);
    printf("Answer = %f\n", eval(postfix));
}
float eval(char *postfix)
{
    int i = 0;
    int stack[10]; char c;
    int ans = 0;
    int op1,op2;
    while(postfix[i])
    {
        c = postfix[i];
        if (c=='+' || c=='-' || c=='/' || c=='*')
        {
            op1 = pop(stack);
            op2 = pop(stack);
            switch(c)
            {
                case '+':
                {
                    ans = op1+op2;
                    //printf("%d\n",ans);
                    break;
                    
                }
                case '-':
                {
                    ans = op2-op1;
                    break;
                    
                }
                case '*':
                {
                    ans = op1*op2;
                    break;
                    
                }
                case '/':
                {
                    ans = op2/op1;
                    break;
                    
                }
            }
            push(stack,ans);
        } 
        else
        {
            push(stack,c-48);
        }
        i+=1;
    }
    return pop(stack);
}
void push(int *s, int val)
{
    top+=1;
    s[top]=val;
}
int pop(int *s)
{
    int c = s[top];
    top--;
    return c;
}