#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <list>
#include <iomanip>
#include <cmath>
using namespace std;
class Stack
{
private:
    int top;
    int arr[5];

public:
    Stack()
    {
        top = -1;
        for (int i = 0; i < 5; i++)
        {
            arr[i] = 0;
        }
    }
    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isFull()
    {
        if (top == 4)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void push(int val)
    {
        if (isFull())
        {
            cout << "Stack Overflow\n";
        }
        else
        {
            top++;
            arr[top] = val;
        }
    }
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow\n";
            return 0;
        }
        else
        {
            int popValue = arr[top];
            arr[top] = 0;
            top--;
            return popValue;
        }
    }
    int count()
    {
        return top + 1;
    }
    int peek(int pos)
    {
        if (isEmpty())
        {
            cout << "Stack Underflow\n";
            return 0;
        }
        else
        {
            return arr[pos];
        }
    }
    void change(int pos, int val)
    {
        arr[pos] = val;
        cout << "value changed at location" << pos << endl;
    }
    void display()
    {
        cout << "All values in the stack are " << endl;
        for (int i = 4; i >= 0; i--)
        {
            cout << arr[i] << endl;
        }
    }

};

int main()
{
    Stack s1;
    int option, position, value;

    do
    {
        cout << "What operation do you want to perform? Select option number. Enter 0 to exit!\n";
        cout << "1. Push()\n";
        cout << "2. Pop()\n";
        cout << "3. isEmpty()\n";
        cout << "4. isFull()\n";
        cout << "5. peek()\n";
        cout << "6. count()\n";
        cout << "7. change()\n";
        cout << "8. display()\n";
        cout << "9. Clear Screen\n\n";
        cin >> option;
        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "Enter an item to push in the stack\n";
            cin >> value;
            s1.push(value);
            break;
        case 2:
            cout << "Pop function called - Popped Value: " << s1.pop() << endl;
            break;
        case 3:
            if (s1.isEmpty())
            {
                cout << "Stack is Empty\n";
            }
            else
            {
                cout << "Stack is not Empty\n";
            }
            break;
        case 4:
            if (s1.isFull())
            {
                cout << "Stack is Full\n";
            }
            else
            {
                cout << "Stack is not Full\n";
            }
            break;
        case 5:
            cout << "Enter position of item you want to peek: \n";
            cin >> position;
            cout << "Peek function called - value at position " << position << "is " << s1.peek(position) << endl;
            break;
        case 6:
            cout << "Count function called - Number of items in Stack are: " << s1.count() << endl;
            break;
        case 7:
            cout << "Change function called - \n";
            cout << "Enter position of item you want to change: ";
            cin >> position;
            cout << "Enter value of item you want to change: ";
            cin >> value;
            s1.change(position, value);
            break;
        case 8:
            cout << "Display function called - \n";
            s1.display();
            break;
        case 9:
            system("cls");
            break;

        default:
            cout << "Enter proper option number \n";
            break;
        }
    } while (option != 0);

    return 0;
}
