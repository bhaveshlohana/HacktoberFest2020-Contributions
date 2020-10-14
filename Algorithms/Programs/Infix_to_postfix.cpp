#include <iostream>
#include <stack>
using namespace std;

int outStackPre(char c)
{
    if(c == '+' || c == '-')
        return 1;
    else if(c == '*' || c == '/')
        return 2;
    else if(c == '^')
        return 4;
    else if(c == '(')
        return 5;
    else if(c == ')')
        return 0;
    return -1;
}

int inStackPre(char c)
{
    if(c == '+' || c == '-')
        return 1;
    else if(c == '*' || c == '/')
        return 2;
    else if(c == '^')
        return 3;
    else if(c == '(')
        return 0;
    return -1;
}

bool isOperator(char c) {
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')' || c == '^')
        return true;
    else
        return false;
}

void convert(string infix)
{
    stack<char> s;
    string postfix = "";
    int length = infix.length();
    int i = 0;
    while(i < length)
    {
        if( !isOperator(infix[i]) )
            postfix += infix[i++];
        else
        {
            if( s.empty() )
                s.push(infix[i++]);
            else if( outStackPre(infix[i]) > inStackPre(s.top()) )
                s.push( infix[i++] );
            else
            {
                if(infix[i] == ')')
                {
                    while(s.top() != '(')
                    {
                        postfix += s.top();
                        s.pop();
                    }
                    s.pop();
                    i++;
                }
                else
                {
                    postfix += s.top();
                    s.pop();
                }
            }
        }
    }
    while(!s.empty())
    {
        postfix += s.top();
        s.pop();
    }
    cout << postfix;
}


int main()
{
    string infix = "(a+b)*c-d^e^f";
    cout << "Infix: " << infix << "\n";
    cout << "Postfix: ";
    convert(infix);
}
