#include<stdio.h>

int isempty();
int isfull();
int peak();
void push();
int pop();
void display();

int top=-1,i,go=-1;
char s[100],ma[100];int main()      
{
	int ch;
	    
	    do       
        {
	    printf("\n\n---- STACK----\n\tMenu ");
	    printf(" \n1.push\n2.pop\n3.peak\n4.Display\n");
	    printf("Enter your choice(1-5):");
	    scanf("%d",&ch);
	    switch(ch)
	    { 
            case 1:push();
                    break;
	        case 2:pop();
                    break;
	        case 3: peak();
                    break;
	        case 4: display();
	                break;
	        default: printf("Wrong Choice!!");
	    }
	    
    }while (ch<=5);
	    return 0;
}
    

int isempty()
    {
        if (go==-1)
        return 1;
        else
        return 0;
        
    }
int isfull(){
        if(go==99)
        return 1;
        else 
        return 0;
    }
void push()
    {
        if(isfull())
        printf("Stack is overflow\n");
        else
        {
            char ch;
            printf("Enter the element");
            scanf("%ch",&ch);
            if (ch=='+'){
                top++;
                printf("man");
                s[top]=ch;}
            if (ch=='-'){
                for(i=top;i>=-1;i--){
                    if (s[i]!='+')
                    {
                        go++;
                        ma[go]=s[i];
                    }
                    top=top-i;
                    s[top++]=ch;
                    }
                }
            if (ch=='*'){
                for(i=top;i>=-1;i--){
                    if (s[i]!='+'|| s[i]!='-')
                    {
                        go++;
                        ma[go]=s[i];
                    }
                    top=top-i;
                    s[top]=ch;
                    }
                }
                if (ch=='%'){
                for(i=top;i>=-1;i--){
                    if (s[i]!='+'||s[i]!='-'||s[i]!='*')
                    {
                        go++;
                        ma[go]=s[i];
                    }
                }
                    top=top-i;
                    s[top]=ch;
                    
                if (ch=='('){
                    s[top]=ch;
                    }
                if (ch==')'){
                    for(i=top;i>=-1;i--){
                        if (s[i]!='(')
                        {
                            go++;
                            ma[go]=s[i];
                        }
                    }
                        top=top-i;
                    }
                else {
                    
                        go++;
                        ma[go]=s[i];
                }
                }
            }
        }
    }

int pop(){
        if(isempty())
        printf("stack is underflow\n");
        else
        {
            return s[top--];
        }
    }

int peak(){
        if(isempty())
        printf("stack is underflow\n");
        else
        {
            return s[top];
        }
    }
void display()
    {
        if(isempty())
        printf("stack is empty");
        else
        {
            for(i=go;i>=0;i--){
                printf("%d\t",ma[i]);     
            }
        }
    }

