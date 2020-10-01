#include <stdio.h>
#include <stdlib.h>
int top, n;
void push(int*, int);
void pop(int*);
void peek(int*);
void display(int*);
int main()
{
    printf("Enter number of elements in stack : ");
    scanf("%d", &n);
    int *a = (int*)malloc(n*sizeof(int));
    top = -1;
    int val;
    for (int i = 0; i<n;i++)
    {
        printf("Enter element : ");
        scanf("%d",&val);
        push(a,val);
    }
    display(a);
    peek(a);
    pop(a);
    display(a);
    free(a);
}
void push(int *a, int val)
{
    if(top==n-1)
        printf("Stack Overflow\n");
    else
    {
            top++;
            a[top]=val;
    } 
}
void pop(int *a)
{
    if (top==-1)
        printf("Stack Underflow\n");
    else
        printf("%d\n",a[top]);
        top--;
}
void peek(int*a)
{
    printf("%d\n", a[top]);
}
void display(int*a)
{
    for (int i = top; i>=0 ; i--)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}