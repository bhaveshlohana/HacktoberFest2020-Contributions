#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int top;
    int n;
    int *st;
};
typedef struct stack STACK;
void push(STACK*,int);
void display(STACK*);
void peek(STACK*);
void pop(STACK*);
int main()
{
    STACK *s = (STACK*)malloc(sizeof(STACK));
    printf("Enter number of nodes : ");
    scanf("%d", &(s->n));
    s->st = (int*)malloc(sizeof(int)*(s->n));
    s->top = -1;
    int val;
    for(int i = 0;i<s->n;i++)
    {
        printf("Enter value : ");
        scanf("%d",&val);
        push(s,val);
    }
    display(s);
    pop(s);
    peek(s);
    display(s);
}
void push(STACK *s, int val)
{
    if(s->top == (s->n)-1)
        printf("Stack Overflow\n");
    else
    {
            s->top+=1;
            s->st[s->top] = val;  
    } 
}
void display(STACK *s)
{
    for (int i = s->top; i>=0 ; i--)
    {
        printf("%d ",s->st[i]);
    }
    printf("\n");
}
void pop(STACK* s)
{
    if (s->top==-1)
        printf("Stack Underflow\n");
    else
        printf("%d\n",s->st[s->top]);
        s->top-=1;
}
void peek(STACK *s)
{
    printf("%d\n", s->st[s->top]);
}